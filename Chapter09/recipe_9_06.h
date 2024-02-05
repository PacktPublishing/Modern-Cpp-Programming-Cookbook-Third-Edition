#pragma once

#include <type_traits>

namespace recipe_9_06
{
#ifdef __cpp_lib_is_constant_evaluated
   namespace v1
   {
      constexpr double power(double base, int exponent)
      {
         if (std::is_constant_evaluated())
         {
            double result = 1.0;
            if (exponent == 0)
            {
               return result;
            }
            else if (exponent > 0) {
               for (int i = 0; i < exponent; i++) {
                  result *= base;
               }
            }
            else {
               exponent = -exponent;
               for (int i = 0; i < exponent; i++) {
                  result *= base;
               }
               result = 1.0 / result;
            }
            return result;
         }
         else
         {
            return std::pow(base, exponent);
         }
      }

      consteval int plus_one(int const i)
      {
         return i + 1;
      }

      consteval int plus_two(int i)
      {
         return plus_one(i) + 1;
      }
      
      constexpr int plus_two_alt(int const i)
      {
         if (std::is_constant_evaluated())
         {
            // return plus_one(i) + 1; // error: call to immediate function is not a constant expression
            return 0;
         }
         else
         {
            return i + 2;
         }
      }      
   }
#endif

#ifdef __cpp_if_consteval
   namespace v2
   {
      constexpr double power(double base, int exponent)
      {
         if consteval
         {
            double result = 1.0;
            if (exponent == 0)
            {
               return result;
            }
            else if (exponent > 0) {
               for (int i = 0; i < exponent; i++) {
                  result *= base;
               }
            }
            else {
               exponent = -exponent;
               for (int i = 0; i < exponent; i++) {
                  result *= base;
               }
               result = 1.0 / result;
            }
            return result;
         }
         else
         {
            return std::pow(base, exponent);
         }
      }

      constexpr double power_but_wrong(double base, int exponent)
      {
         if constexpr (std::is_constant_evaluated()) // always evaluates to true
         {
         }
      }

      consteval int plus_one(int const i)
      {
         return i + 1;
      }

      consteval int plus_two(int i)
      {
         return plus_one(i) + 1;
      }

      constexpr int plus_two_alt(int const i)
      {
         if consteval
         {
            return plus_one(i) + 1;
         }
         else
         {
            return i + 2;
         }
      }
   }
#endif

   void execute()
   {
      {
#ifdef __cpp_lib_is_constant_evaluated
         using namespace v1;

         constexpr double a = power(10, 5); // compile-time eval
         std::cout << a << '\n';

         double b = power(10, 5);           // runtime eval
         std::cout << b << '\n';
#endif
      }

      {
#ifdef __cpp_if_consteval
         using namespace v2;

         constexpr double a = power(10, 5); // compile-time eval
         std::cout << a << '\n';

         double b = power(10, 5);           // runtime eval
         std::cout << b << '\n';
#endif
      }

   }
}