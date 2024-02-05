#pragma once

#include <vector>
#include <thread>
#include <iostream>

#ifdef __cpp_lib_syncbuf
#include <syncstream>
#endif

namespace recipe_8_14
{
   void execute()
   {
      {
         std::vector<std::jthread> threads;
         for (int i = 1; i <= 10; ++i)
         {
            threads.push_back(
               std::jthread([](const int id)
                  {
                     std::cout << "thread " << id << " running\n";
                  }, i));
         }
      }

      {
         std::vector<std::jthread> threads;
         for (int i = 1; i <= 10; ++i)
         {
            threads.push_back(
               std::jthread([](const int id)
                  {
                     std::stringstream ss;
                     ss << "thread " << id << " running\n";
                     std::cout << ss.str();
                  }, i));
         }
      }

#ifdef __cpp_lib_syncbuf
      {
         std::vector<std::jthread> threads;
         for (int i = 1; i <= 10; ++i)
         {
            threads.push_back(
               std::jthread([](const int id)
                  {
                     std::osyncstream scout{ std::cout };
                     scout << "thread " << id << " running\n";
                  }, i));
         }
      }

      {
         std::vector<std::jthread> threads;
         for (int i = 1; i <= 10; ++i)
         {
            threads.push_back(
               std::jthread([](const int id)
                  {
                     std::osyncstream{ std::cout } << "thread " << id << " running\n";
                  }, i));
         }
      }

      {
         std::ostringstream str{ };
         {
            std::osyncstream syncstr{ str };
            syncstr << "sync stream demo";
            std::cout << "A:" << str.str() << '\n';
         }

         std::cout << "B:" << str.str() << '\n';
      }

      {
         std::ostringstream str{ };
         {
            std::osyncstream syncstr{ str };
            syncstr << "sync stream demo";
            std::cout << "A:" << str.str() << '\n';
            syncstr.emit();
            std::cout << "B:" << str.str() << '\n';
            syncstr << "demo part 2";
            std::cout << "C:" << str.str() << '\n';
         }
         std::cout << "D:" << str.str() << '\n';
      }

      {
         std::ostringstream str{ };
         {
            std::osyncstream syncstr{ str };
            syncstr << "sync stream demo";
            std::cout << "A:" << str.str() << '\n';
            {
               std::osyncstream syncstr2{ syncstr.get_wrapped() };
               syncstr2 << "demo part 3";
               std::cout << "B:" << str.str() << '\n';
            }
            std::cout << "C:" << str.str() << '\n';
         }
         std::cout << "D:" << str.str() << '\n';
      }
#endif
   }
}
