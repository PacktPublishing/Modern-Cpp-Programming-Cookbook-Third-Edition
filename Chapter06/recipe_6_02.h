#pragma once

#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std::chrono_literals;

namespace recipe_6_02
{
#if (__cpp_lib_chrono == 201907L)
   inline int number_of_days(std::chrono::sys_days const& first, std::chrono::sys_days const& last)
   {
      return (last - first).count();
   }
#endif

   void execute()
   {
#if (__cpp_lib_chrono == 201907L)
      {
         // format: year / month /day
         year_month_day d1 = 2024y / 1 / 15;
         year_month_day d2 = 2024y / January / 15;
         // format: day / month / year
         year_month_day d3 = 15d / 1 / 2024;
         year_month_day d4 = 15d / January / 2024;
         // format: month / day / year
         year_month_day d5 = 1 / 15d / 2024;
         year_month_day d6 = January / 15 / 2024;
      }

      {
         // format: year / month / weekday
         year_month_weekday d1 = 2024y / January / Monday[1];
         // format: weekday / month / year
         year_month_weekday d2 = Monday[1] / January / 2024;
         // format: month / weekday / year
         year_month_weekday d3 = January / Monday[1] / 2024;
      }

      {
         auto today = floor<days>(std::chrono::system_clock::now());
         auto tomorrow = today + days{ 1 };
         auto yesterday = today - days{ 1 };
      }

      {
         year_month_day today = floor<days>(std::chrono::system_clock::now());
         year_month_day first_day_this_month = today.year() / today.month() / 1;
         year_month_day last_day_this_month = today.year() / today.month() / std::chrono::last;
         year_month_day last_day_feb_2024 = 2024y / February / std::chrono::last;

         year_month_day_last ymdl{ today.year(), month_day_last{ month{ 2 } } };
         year_month_day last_day_feb{ ymdl };
      }

      {
         auto days = number_of_days(2020y / April / 1, 2024y / December / 25);
      }

      {
         auto day = 2024y / January / 33;
         auto is_valid = day.ok();
      }

      {
         hh_mm_ss<std::chrono::seconds> td(13h + 12min + 11s);
         std::cout << td << '\n';  // 13:12:11
      }

      {
         auto tp = sys_days{ 2024y / April / 1 } +12h + 30min + 45s;
         std::cout << tp << '\n';  // 2024-04-01 12:30:45
      }

      {
         auto tp = std::chrono::system_clock::now();
         auto dp = floor<days>(tp);

         hh_mm_ss<std::chrono::milliseconds> time1{ std::chrono::duration_cast<std::chrono::milliseconds>(tp - dp) };
         std::cout << time1 << '\n';  // 13:12:11.625

         hh_mm_ss<std::chrono::minutes> time2{ std::chrono::duration_cast<std::chrono::minutes>(tp - dp) };
         std::cout << time2 << '\n';  // 13:12
      }

      {
         std::cout << is_am(0h) << '\n';  // true
         std::cout << is_am(1h) << '\n';  // true
         std::cout << is_am(12h) << '\n'; // false

         std::cout << is_pm(0h) << '\n';  // false
         std::cout << is_pm(12h) << '\n'; // true
         std::cout << is_pm(23h) << '\n'; // true
         std::cout << is_pm(24h) << '\n'; // false
      }

      {
         for (auto h : { 0h, 1h, 12h, 23h, 24h })
         {
            std::cout << make12(h).count() << '\n';
            // prints 12, 1, 12, 11, 12
         }

         {
            for (auto [h, pm] : { 
               std::pair<hours, bool>{0h, false},
               std::pair<hours, bool>{1h, false}, 
               std::pair<hours, bool>{1h, true}, 
               std::pair<hours, bool>{12h, false}, 
               std::pair<hours, bool>{12h, true}, })
            {
               std::cout << make24(h, pm).count() << '\n';
               // prints 0, 1, 13, 0, 12
            }
         }
      }
#endif
   }
}