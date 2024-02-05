#pragma once

#include <utility>

namespace recipe_9_13
{
   void execute()
   {
      {
         int a = -1;
         unsigned int b = 42;

         if (a < b)
         {
            std::cout << "-1 < 42\n";
         }
         else
         {
            std::cout << "-1 >= 42\n";
         }
      }

      {
         int a = -1;
         unsigned int b = 42;

         if(a < 0 || static_cast<unsigned int>(a) < b)
         {
            std::cout << "-1 < 42\n";
         }
         else
         {
            std::cout << "-1 >= 42\n";
         }
      }

#ifdef __cpp_lib_integer_comparison_functions
      {
         int a = -1;
         unsigned int b = 42;

         if (std::cmp_less(a, b))
         {
            std::cout << "-1 < 42\n";
         }
         else
         {
            std::cout << "-1 >= 42\n";
         }
      }

      {
         // if (std::cmp_equal(true, 1)) {} // error
      }

      {
         __int64 a = -1;
         unsigned __int64 b = 42;

         if (std::cmp_less(a, b))
         {
            std::cout << "-1 < 42\n";
         }
         else
         {
            std::cout << "-1 >= 42\n";
         }
      }

      {
         int32_t a = -1;
         uint32_t b = 42;

         if (std::cmp_less(a, b))
         {
            std::cout << "-1 < 42\n";
         }
         else
         {
            std::cout << "-1 >= 42\n";
         }
      }

#endif
   }
}