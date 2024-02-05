#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef _WINDOWS
#include <Windows.h>
#endif

namespace recipe_7_06
{
   using namespace std::string_literals;

   void test_money()
   {
      std::vector<std::string> locale_names
      {
         ""s, 
#ifdef _WINDOWS
         "English_US.1252"s,
         "English_UK.1252"s,
         "Japanese_Japan.932"s,
         "French_France.1252"s,
         "German_Germany.1252"s,
         "Romanian_Romania.1250"s
#else
         "en_US.utf8"s,
         "en_GB.utf8"s,
         "ja_JP.utf8"s,
         "fr_FR.utf8"s,
         "de_DE.utf8"s,
         "ro_RO.utf8"s
#endif
      };

      long double mon = 12345.67;

      std::cout << std::showbase
         << std::put_money(mon) << " or "
         << std::put_money(mon, true)
         << '\n';

      for (auto const & locale : locale_names)
      {
         std::cout.imbue(std::locale(locale));
         std::cout << std::showbase
            << locale << ": "
            << std::put_money(mon) << " or "
            << std::put_money(mon, true)
            << '\n';
      }

      std::cout.imbue(std::locale::classic());

      std::vector<std::string> texts{ "$123.46"s, "123.46 USD"s, "USD 123.46"s, "123.46"s };

      for (auto const & text : texts)
      {
         std::cout << '\n' << "parsing " << std::quoted(text) << '\n';
         for (auto const & locale : locale_names)
         {
            std::istringstream stext(text);
            long double value;

            stext.imbue(std::locale(locale));
            stext >> std::get_money(value);

            std::cout << locale << ": ";
            if (stext)
            {
               std::cout << value << '\n';
            }
            else
            {
               std::cout << "failed" << '\n';
            }
         }
      }
   }

   void write_money()
   {
#ifdef _WINDOWS
      auto loc_uk = std::locale{ "English_UK.1252" };
#else
      auto loc_uk = std::locale{ "en_GB.utf8" };
#endif

      long double mon = 12345.67;

      std::cout.imbue(loc_uk);

      std::cout << std::put_money(mon) << '\n';                        // 123.46
      std::cout << std::showbase << std::put_money(mon) << '\n';       // £123.46
      std::cout << std::showbase << std::put_money(mon, true) << '\n'; // GBP 123.46

      std::string smon = "12345.67";

      std::cout << std::put_money(smon) << '\n';                        // 123.46
      std::cout << std::showbase << std::put_money(smon) << '\n';       // £123.46
      std::cout << std::showbase << std::put_money(smon, true) << '\n'; // GBP 123.46

      std::cout.imbue(std::locale::classic());
   }

   void read_money()
   {
      {
#ifdef _WINDOWS
         auto loc_us = std::locale{ "English_US.1252" };
#else
         auto loc_us = std::locale{ "en_US.utf8" };
#endif
         {
            auto text = "$123.45 567.89 USD"s;
            std::istringstream stext(text);
            stext.imbue(loc_us);

            long double v1;
            std::string v2;

            stext >> std::get_money(v1) >> std::get_money(v2);
            // v1 = 12345, v2 = "56789"

            std::cout << v1 << '\n';
            std::cout << v2 << '\n';
         }

         {
            auto text = "123.45 567.89"s;
            std::istringstream stext(text);
            stext.imbue(loc_us);

            long double v1 = 0;
            std::string v2;

            stext.seekg(0, std::ios::beg);
            stext >> std::get_money(v1, true) >> std::get_money(v2, true);
            // v1 = 12345, v2 = "56789"

            std::cout << v1 << '\n';
            std::cout << v2 << '\n';
         }
      }
   }

   void execute()
   {
#ifdef _WINDOWS 
      auto ocp = GetConsoleOutputCP();
      SetConsoleOutputCP(CP_UTF8);
#endif
      test_money();

      write_money();
      read_money();

#ifdef _WINDOWS 
      SetConsoleOutputCP(ocp);
#endif
   }
}