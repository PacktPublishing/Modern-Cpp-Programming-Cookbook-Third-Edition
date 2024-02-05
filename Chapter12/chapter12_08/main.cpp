#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <print>
#include <unordered_map>
#include <map>
#include <ranges>

namespace rv = std::ranges::views;
namespace rg = std::ranges;

bool is_prime(int const number)
{
   if (number != 2)
   {
      if (number < 2 || number % 2 == 0) return false;
      auto root = std::sqrt(number);
      for (int i = 3; i <= root; i += 2)
      {
         if (number % i == 0) return false;
      }
   }
   return true;
}

int main()
{
#ifdef __cpp_lib_ranges_to_container
   {
      // vector
      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      std::vector<int> primes = numbers | rv::filter(is_prime) | rg::to<std::vector>();
      rg::copy(primes, std::ostream_iterator<int>(std::cout, " "));
      std::println("");

      std::string text{ "server=demo123;db=optimus" };
      auto parts = text | rv::lazy_split(';') | rg::to<std::vector<std::string>>();
      rg::copy(parts, std::ostream_iterator<std::string>(std::cout, " "));
      std::println("");

      // map
      std::vector<std::string> words{ "one", "two", "three", "four", "five" };
      auto zipped = rv::zip(numbers, words) | rg::to<std::unordered_multimap<int, std::string>>();

      for (auto const [number, word] : zipped)
      {
         std::println("{} = {}", number, word);
      }

#ifdef __cpp_lib_ranges_stride	
      // string
      std::string text2 = text | rv::stride(3) | rg::to<std::string>();
      std::println("{}", text2);
#endif
   }

   {
      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      std::list<int> list = numbers |rg::to<std::list>();
   }

   {
      std::map<int, std::string> m{ {1, "one"}, {2, "two"}, {3, "three"} };
      std::vector<std::pair<int, std::string>> words = m | rg::to<std::vector<std::pair<int, std::string>>>();
   }
#endif
}