#pragma once

#ifdef __cpp_lib_format
#include <format>
#endif

#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <iterator>
#include <string>

namespace recipe_2_16
{
   void execute()
   {
#ifdef __cpp_lib_format
      {
         auto text = std::format("{} is {}", "John", 42);
      }

      {
         auto text = std::format("{0} is {1}", "John", 42);
      }

      {
         auto text = std::format("{0} hex is {0:08X}", 42);
      }

      {
         auto now = std::chrono::system_clock::now();
         auto date = std::format("Today is {:%Y-%m-%d}", now);
         std::cout << date << '\n';
      }

      {
         std::vector<char> buf;
         std::format_to(std::back_inserter(buf), "{} is {}", "John", 42);
      }

      {
         auto size = std::formatted_size("{} is {}", "John", 42);
         std::vector<char> buf(size);
         std::format_to(buf.data(), "{} is {}", "John", 42);
      }

      {
         char buf[100];
         auto result = std::format_to_n(buf, sizeof(buf), "{} is {}", "John", 42);
      }

      {
         auto t1 = std::format("{:5}", 42);    // "   42"
         auto t2 = std::format("{:5}", 'x');   // "x    "
         auto t3 = std::format("{:*<5}", 'x'); // "x****"
         auto t4 = std::format("{:*>5}", 'x'); // "****x"
         auto t5 = std::format("{:*^5}", 'x'); // "**x**"
         auto t6 = std::format("{:5}", true);  // "true "
      }

      {
         auto t7 = std::format("{0:},{0:+},{0:-},{0: }", 42);   // "42,+42,42, 42"
         auto t8 = std::format("{0:},{0:+},{0:-},{0: }", -42);  // "-42,-42,-42,-42"
      }

      {
         auto t9  = std::format("{:+05d}", 42); // "+0042"
         auto t10 = std::format("{:#05x}", 42); // "0x02a"
         auto t11 = std::format("{:<05}", -42); // "-42  "
      }
#endif 
   }
}