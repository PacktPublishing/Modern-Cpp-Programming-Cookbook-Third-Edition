#pragma once

#ifdef __cpp_lib_span
#include <span>
#endif

namespace recipe_6_12
{
#ifdef __cpp_lib_span
   void func(int* buffer, size_t length) { /* � */ }

   void func(std::span<int> buffer)
   {
      for (auto const e : buffer)
         std::cout << e << ' ';
      std::cout << '\n';
   }
#endif
   void execute()
   {
#ifdef __cpp_lib_span
      {
         int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
         std::span<int, 7> s{ arr };
      }

      {
         int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
         std::span<int> s{ arr };
      }

      {
         int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
         std::span<int, 7> s{ arr };
         std::cout << s.front() << " == " << s[0] << '\n';           // 1 == 1
         std::cout << s.back() << " == " << s[s.size() - 1] << '\n'; // 13 == 13
         std::cout << *s.data() << '\n';                             // 1
      }
 
      {
         int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
         std::span<int, 7> s{ arr };

         std::span<int> first_3 = s.first(3);
         func(first_3);  // 1 1 2
         std::span<int> last_3 = s.last(3);
         func(last_3);   // 5 8 13
         std::span<int> mid_3 = s.subspan(2, 3);
         func(mid_3);    // 2 3 5
      }
#endif
   }
}