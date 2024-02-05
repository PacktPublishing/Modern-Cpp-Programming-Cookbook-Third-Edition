#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <functional>

#ifdef __cpp_lib_latch
#include <latch>
#endif

#ifdef __cpp_lib_barrier
#include <barrier>
#endif

#ifdef __cpp_lib_semaphore
#include <semaphore>
#endif

#ifdef __cpp_lib_jthread
#include <stop_token>
#endif

namespace recipe_8_13
{
   void process(std::vector<int> const& data) noexcept
   {
      for (auto const e : data)
      {
         std::cout << e << ' ';
      }
      
      std::cout << '\n';
   }

   int create(int const thread, int const i) noexcept
   {
      return thread * 10 + i;
   }

#if defined (__cpp_lib_latch) && defined(__cpp_lib_jthread)
   void test_latches()
   {
      int const jobs = 4;
      std::latch work_done(jobs);
      std::vector<int> data(jobs);
      std::vector<std::jthread> threads;
      for (int i = 1; i <= jobs; ++i)
      {
         threads.push_back(std::jthread([&data, i, &work_done] {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s); // simulate work

            data[i-1] = create(i, 1); // create data

            work_done.count_down(); // decrement counter
            }));

      }
      work_done.wait();             // wait for all jobs to finish
      process(data);                // process data from all jobs
   }
#endif

#if defined (__cpp_lib_barrier) && defined(__cpp_lib_jthread)
   void test_barriers()
   {
      int const jobs = 4;
      std::vector<int> data(jobs);
      int cycle = 1;
      std::stop_source st;

      auto on_completion = [&data, &cycle, &st]() noexcept {   // completion function
         process(data);          // process data from all jobs
         cycle++;
         if (cycle == 10)        // stop after ten cycles
            st.request_stop();
         };

      std::barrier work_done(jobs, on_completion);

      std::vector<std::jthread> threads;
      for (int i = 1; i <= jobs; ++i)
      {
         threads.push_back(std::jthread(
            [&data, &cycle, &work_done](std::stop_token st, int const i)
            {
               while (!st.stop_requested())
               {
                  using namespace std::chrono_literals;
                  std::this_thread::sleep_for(200ms); // simulate work

                  data[i-1] = create(i, cycle);   // create data 

                  work_done.arrive_and_wait();  // decrement counter
               }
            },
            st.get_token(),
            i));
      }

      for (auto& t : threads) t.join();
   }
#endif

#if defined(__cpp_lib_semaphore) && defined(__cpp_lib_jthread)
   void test_semaphores()
   {
      int const jobs = 4;
      std::vector<int> data;

      std::binary_semaphore sem(1);

      std::vector<std::jthread> threads;
      for (int i = 1; i <= jobs; ++i)
      {
         threads.push_back(std::jthread([&data, i, &sem] {
            for (int k = 1; k < 5; ++k)
            {
               using namespace std::chrono_literals;
               std::this_thread::sleep_for(200ms);   // simulate work
               int value = create(i, k);     // create data

               sem.acquire();                 // acquire the semaphore
               data.push_back(value);        // write to the shared resource
               sem.release();                 // release the semaphore
            }
         }));
      }

      for (auto& t : threads) t.join();

      process(data);                         // process data from all jobs
   }
#endif

   void execute()
   {
#ifdef __cpp_lib_latch
      test_latches();
#endif

#ifdef __cpp_lib_barrier
      test_barriers();
#endif

#ifdef __cpp_lib_semaphore
      test_semaphores();
#endif
   }
}
