#pragma once

#include <vector>
#include <format>
#include <array>

namespace recipe_3_05
{
   namespace v1
   {
      template <typename T>
      T minimum(T a, T b)
      {
         return a <= b ? a : b;
      }

      template <>
      const char* minimum(const char* a, const char* b)
      {
         return std::strcmp(a, b) <= 1 ? a : b;
      }

      // explicit instantiation of minimum<T> for char
      template<> char minimum(char a, char b);

      template <typename T>
      std::basic_string<T> minimum(std::basic_string<T> a, std::basic_string<T> b)
      {
         return a.length() <= b.length() ? a : b;
      }

      std::string minimum(std::string a, std::string b)
      {
         return a.length() <= b.length() ? a : b;
      }

      template <typename T, std::size_t S>
      std::array<T, S> make_array()
      {
         return std::array<T, S>{};
      }

      template <typename T, auto S>
      std::array<T, S> make_array2()
      {
         return std::array<T, S>{};
      }

      template <typename T>
      struct Minimum
      {
         T operator()(T a, T b)
         {
            return a <= b ? a : b;
         }
      };

      template <typename T, template <typename> class M>
      T trimin(T a, T b, T c)
      {
         return M<T>{}(a, M<T>{}(b, c));
      }

      template <typename T>
      T minimum2(T a, T b)
      {
         return a <= b ? a : b;
      }
   }

   namespace v2
   {
      template <typename T>
      T minimum(T a, T b)
      {
         return a <= b ? a : b;
      }

      template <typename T>
      T* minimum(T* a, T* b) = delete;
   }

   void execute()
   {
      {
         using namespace v1;

         {
            std::cout << minimum(3, 4) << '\n';
            std::cout << minimum(3.99, 4.01) << '\n';
            std::cout << minimum("abc", "acxyz") << '\n';

            std::cout << minimum(std::string("def"), std::string("acxyz")) << '\n';
            std::wcout << minimum(std::wstring(L"def"), std::wstring(L"acxyz")) << '\n';
         }

         {
            auto arr = make_array<int, 10>();
         }

         {
            auto arr = make_array2<int, 10>();
         }

         {
            std::cout << trimin<int, Minimum>(1, 2, 3) << '\n';
            std::cout << trimin<int, Minimum>(5, 2, 7) << '\n';
         }

         {
            // minimum2(1, 2u); // error, ambiguous template parameter T
            minimum2<unsigned>(1, 2u); // OK
         }
      }

      {
         using namespace v2;

         std::cout << minimum(3, 4) << '\n';

         [[maybe_unused]] int a = 3;
         [[maybe_unused]] int b = 4;
         //std::cout << minimum(&a, &b) << '\n';
      }
   }
}
