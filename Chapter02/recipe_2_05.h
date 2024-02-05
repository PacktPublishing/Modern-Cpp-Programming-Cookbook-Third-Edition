#pragma once

#ifdef _WINDOWS
#include <windows.h>
#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#include <io.h>
#include <fcntl.h>
#else
#include <locale>
#endif

namespace recipe_2_05
{
   void execute()
   {
      {
         std::cout << "C++\n";
      }

#ifndef _WINDOWS
      {
         std::cout << "Erling Håland\n";
         std::cout << "Thomas Müller\n";
         std::cout << "Στέφανος Τσιτσιπάς\n";

         std::string monkeys = "🙈🙉🙊";
         std::cout << monkeys << '\n';
      }

      {
         std::cout << reinterpret_cast<const char*>(u8"Στέφανος Τσιτσιπάς\n");
      }
#endif

#ifdef _WINDOWS
      {
         SetConsoleOutputCP(CP_UTF8);

         std::cout << reinterpret_cast<const char*>(u8"Erling Håland\n");
         std::cout << reinterpret_cast<const char*>(u8"Thomas Müller\n");
         std::cout << reinterpret_cast<const char*>(u8"Στέφανος Τσιτσιπάς\n");
         std::cout << reinterpret_cast<const char*>(u8"🙈🙉🙊\n");
      }
#else
      {
         std::locale utf8("en_US.UTF8");
         std::wcout.imbue(utf8);

         std::wcout << L"Erling Håland\n";
         std::wcout << L"Thomas Müller\n";
         std::wcout << L"Στέφανος Τσιτσιπάς\n";

         std::wstring monkeys = L"🙈🙉🙊";
         std::wcout << monkeys << '\n';
      }
#endif

#ifdef _WINDOWS
      {
         auto mode = _setmode(_fileno(stdout), _O_U16TEXT);

         std::wcout << L"Erling Håland\n";
         std::wcout << L"Thomas Müller\n";
         std::wcout << L"Στέφανος Τσιτσιπάς\n";

         _setmode(_fileno(stdout), mode);
      }
#endif

#ifdef _WINDOWS
      {
         char c = 224;
         for (int codepage = 1250; codepage <= 1258; codepage++)
         {
            SetConsoleOutputCP(codepage);
            std::cout << c << ' ';
         }
      }
#endif
   }
}