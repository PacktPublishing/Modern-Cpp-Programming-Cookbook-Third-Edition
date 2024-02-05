#pragma once

#include <iostream>
#include <chrono>

namespace recipe_6_03
{
   void execute()
   {
#if (__cpp_lib_chrono == 201907L)
      using namespace std::chrono;
      using namespace std::chrono_literals;

      {
         auto time = zoned_time{ current_zone(), system_clock::now() };
         std::cout << time << '\n'; // 2024-01-16 22:10:30.9274320 EET
      }

      {
         auto time = zoned_time{ locate_zone("Europe/Rome"), system_clock::now() };
         std::cout << time << '\n'; // 2024-01-16 21:10:30.9291091 CET
      }

      {
         auto time = zoned_time{ current_zone(), system_clock::now() };
         std::cout << std::format(std::locale{ "ro_RO" }, "%c", time)
            << '\n'; // 16.01.2020 22:12:57
      }

      {
         auto time = local_days{ 2024y / June / 1 } +12h + 30min + 45s + 256ms;
         auto ny_time = zoned_time<std::chrono::milliseconds>{
                           locate_zone("America/New_York"), time };
         std::cout << ny_time << '\n'; // 2024-06-01 12:30:45.256 EDT

         auto la_time = zoned_time<std::chrono::milliseconds>(
            locate_zone("America/Los_Angeles"), ny_time);
         std::cout << la_time << '\n'; // 2024-06-01 09:30:45.256 PDT
      }

      {
         auto zst = zoned_time<std::chrono::seconds>(
            current_zone(),
            sys_days{ 2024y / May / 10 } +14h + 20min + 30s);
         std::cout << zst << '\n'; // 2024-05-10 17:20:30 EEST (or GMT+3)

         auto zlt = zoned_time<std::chrono::seconds>(
            current_zone(),
            local_days{ 2024y / May / 10 } +14h + 20min + 30s);
         std::cout << zlt << '\n'; // 2024-05-10 14:20:30 EEST (or GMT+3)

         auto zpt = zoned_time<std::chrono::seconds>(
            locate_zone("Europe/Paris"),
            zlt);
         std::cout << zpt << '\n'; //2024-05-10 13:20:30 CEST (or GMT+2)
      }
#endif
   }
}