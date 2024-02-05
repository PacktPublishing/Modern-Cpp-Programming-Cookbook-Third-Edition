#include <iostream>
#include <optional>
#ifdef __cpp_lib_generator
#include <generator>
#endif

#ifdef __cpp_lib_generator
std::generator<int> get_values() noexcept
{
   co_yield 1;
   co_yield 2;
   co_yield 3;
}

std::generator<int> iota(int start = 0, int step = 1) noexcept
{
   auto value = start;
   for (int i = 0;; ++i)
   {
      co_yield value;
      value += step;
   }
}

std::generator<std::optional<int>> iota_n(int start = 0, int step = 1, int n = std::numeric_limits<int>::max()) noexcept
{
   auto value = start;
   for (int i = 0; i < n; ++i)
   {
      co_yield value;
      value += step;
   }
}

std::generator<int> fibonacci() noexcept
{
   int a = 0, b = 1;
   while (true)
   {
      co_yield b;
      auto tmp = a;
      a = b;
      b += tmp;
   }
}
#endif

int main()
{
#ifdef __cpp_lib_generator
   std::cout << "get_values():";
   for (auto i : get_values())
   {
      std::cout << i << ' ';
   }
   std::cout << '\n';

   std::cout << "iota():";
   for (auto i : iota())
   {
      std::cout << i << ' ';
      if (i >= 10) break;
   }
   std::cout << '\n';

   std::cout << "iota_n(0,1,10):";
   for (auto i : iota_n(0, 1, 10))
   {
      if (!i.has_value()) break;
      std::cout << i.value() << ' ';
   }
   std::cout << '\n';

   std::cout << "iota(10, -2):";
   int c = 1;
   for (auto i : iota(10, -2))
   {
      std::cout << i << ' ';
      if (++c > 10) break;
   }
   std::cout << '\n';

   c = 1;
   std::cout << "fibonacci:";
   for (auto i : fibonacci())
   {
      std::cout << i << ' ';
      if (++c > 10) break;
   }
   std::cout << '\n';
#endif
}