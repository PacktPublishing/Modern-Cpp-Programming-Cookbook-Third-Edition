#pragma once

#include <functional>
#include <iostream>

namespace recipe_3_04
{
   constexpr int fib(int const n)
   {
      return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
   }

   std::function<int(int const)> fib_create()
   {
      std::function<int(int const)> lfib = [&lfib](int const n)
      {
         return n <= 2 ? 1 : lfib(n - 1) + lfib(n - 2);
      };

      return lfib;
   }

   std::function<int(int const)> fib_create2()
   {
      std::function<int(int const)> f = [](int const n) 
      {
         std::function<int(int const)> lfib = [&lfib](int n)
         {
            return n <= 2 ? 1 : lfib(n - 1) + lfib(n - 2);
         };
         return lfib(n);
      };

      return f;
   }

   class __lambda_name_3
   {
   public:
      template<class T1>
      inline int operator()(T1 f, const int n) const
      {
         if (n < 2) {
            return 1;
         }
         else {
            return f(f, n - 1) + f(f, n - 2);
         }
      }

      template<>
      inline int operator() < __lambda_name_3 > (__lambda_name_3 f, const int n) const
      {
         if (n < 2) {
            return 1;
         }
         else {
            return f.operator()(__lambda_name_3(f), n - 1) + f.operator()(__lambda_name_3(f), n - 2);
         }
      }
   };

   struct fibonacci
   {
      std::function<int(int const)> lfib =
         [this](int const n)
         {
            return n <= 2 ? 1 : lfib(n - 1) + lfib(n - 2);
         };
   };


   void execute()
   {
      {
         auto f10 = fib(10);

         std::cout << "fib(10): " << f10 << '\n';
      }

      // C++11
      {
         std::function<int(int const)> lfib = [&lfib](int const n)
         {
            return n <= 2 ? 1 : lfib(n - 1) + lfib(n - 2);
         };

         auto f10 = lfib(10);

         std::cout << "fib(10): " << f10 << '\n';
      }

      {
         auto lfib = fib_create2();

         auto f10 = lfib(10);

         std::cout << "fib(10): " << f10 << '\n';
      }

      // C++14
      {
         auto lfib = [](auto f, int const n)
         {
            if (n < 2) return 1;
            else return f(f, n - 1) + f(f, n - 2);
         };

         lfib(lfib, 10);
      }

      {
         __lambda_name_3 lfib = __lambda_name_3{};
         lfib.operator()(__lambda_name_3(lfib), 10);
      }

      {
         fibonacci f;
         f.lfib(10);
      }

      // C++23
#ifdef DEDUCING_THIS
      {
         auto lfib = [](this auto const & self, int n) -> int
         {
            return n <= 2 ? 1 : self(n - 1) + self(n - 2);
         };

         lfib(5);
      }

      {
         auto lfib = [](this auto const& self, int n)
         {
            if (n <= 2) return 1;
            return self(n - 1) + self(n - 2);
         };

         lfib(5);
      }
#endif
   }
}
