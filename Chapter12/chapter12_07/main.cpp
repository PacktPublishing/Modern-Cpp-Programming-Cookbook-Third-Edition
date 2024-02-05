#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <print>
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
   // C++20 range adaptors
   // ----------------------------------------
   
   // filter (https://en.cppreference.com/w/cpp/ranges/filter_view)
   {
      std::println("filter");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto primes = numbers | rv::filter(is_prime);
      rg::copy(primes, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }

   // transform (https://en.cppreference.com/w/cpp/ranges/transform_view)
   {
      std::println("transform");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto letters = numbers | rv::transform([](int i) { return static_cast<char>('A' + i); });
      rg::copy(letters, std::ostream_iterator<char>{ std::cout, " " });

      std::println("");
   }

   // take (https://en.cppreference.com/w/cpp/ranges/take_view)
   {
      std::println("take");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto some_numbers = numbers | rv::take(3);
      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }

   // take_while (https://en.cppreference.com/w/cpp/ranges/take_while_view)
   {
      std::println("take_while");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto some_numbers = numbers | rv::take_while([](int i) { return i < 3; });
      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }
   
   // drop (https://en.cppreference.com/w/cpp/ranges/drop_view)
   {
      std::println("drop");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto some_numbers = numbers | rv::drop(3);
      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }
   
   // drop_while (https://en.cppreference.com/w/cpp/ranges/drop_while_view)
   {
      std::println("drop_while");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto some_numbers = numbers | rv::drop_while([](int i) { return i < 3; });
      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }   

   // join (https://en.cppreference.com/w/cpp/ranges/join_view)
   {
      std::println("join");

      std::vector<std::vector<int>> numbers{ {1, 1}, {2, 3}, {5, 8}, {13} };
      auto joined_numbers = numbers | rv::join;
      rg::copy(joined_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }

   // split (https://en.cppreference.com/w/cpp/ranges/split_view)
   {
      std::println("split");

      std::string text{ "Hello, world!" };
      auto words = text | rv::split(' ');

      for (auto const word : words)
      {
         std::cout << std::quoted(std::string_view(word)) << ' ';
      }

      std::println("");
   }

   // split
   {
      std::println("split");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto split_numbers = numbers | rv::split(5);

      for (auto const split : split_numbers)
      {
         rg::copy(split, std::ostream_iterator<int>{ std::cout, " " });
         std::cout << '|';
      }

      std::println("");
   }
   
   // lazy_split (https://en.cppreference.com/w/cpp/ranges/lazy_split_view)
   {
      std::println("lazy_split");

      std::string text{ "server=demo123;db=optimus" };
      auto words = text | rv::lazy_split(';');

      std::ranges::for_each(words, [](auto const& view)
         {
            std::cout << "{ ";
            for (const auto element : view)
               std::cout << element << ' ';
            std::cout << "} ";
         });

      std::println("");
   }

   // lazy split
   {
      std::println("lazy split");

      std::string text{ "Hello, world!" };
      auto words = text | rv::lazy_split(' ');

      for (auto const word : words)
      {
         std::cout << std::quoted(std::ranges::to<std::string>(word)) << ' ';
      }

      std::println("");
   }
   
   // reverse (https://en.cppreference.com/w/cpp/ranges/reverse_view)
   {
      std::println("reverse");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto reversed_numbers = numbers | rv::reverse;
      rg::copy(reversed_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }
   
   // elements (https://en.cppreference.com/w/cpp/ranges/elements_view)
   {
      std::println("elements");

      std::vector<std::tuple<int, std::string_view>> numbers{
         {1, "one"},
         {1, "one"},
         {2, "two"},
         {3, "three"},
         {5, "five"},
         {8, "eight"},
         {13, "thirteen"} };

      auto some_numbers = numbers | rv::elements<0>;

      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });
      std::println("");

      auto some_names = numbers | rv::elements<1>;

      rg::copy(some_names, std::ostream_iterator<std::string_view>{ std::cout, " " });
      std::println("");
   }
   
   // keys (https://en.cppreference.com/w/cpp/ranges/keys_view)
   // values (https://en.cppreference.com/w/cpp/ranges/values_view)
   {
      std::println("keys & values");

      std::vector<std::pair<int, std::string_view>> numbers{
         {1, "one"},
         {1, "one"},
         {2, "two"},
         {3, "three"},
         {5, "five"},
         {8, "eight"},
         {13, "thirteen"} };

      auto some_numbers = numbers | rv::keys;

      rg::copy(some_numbers, std::ostream_iterator<int>{ std::cout, " " });
      std::println("");

      auto some_names = numbers | rv::values;

      rg::copy(some_names, std::ostream_iterator<std::string_view>{ std::cout, " " });
      std::println("");
   }

   // C++23 range adaptors
   // ----------------------------------------
   // enumerate (https://en.cppreference.com/w/cpp/ranges/enumerate_view)
   {
#ifdef __cpp_lib_ranges_enumerate
      std::println("enumerate");

      std::vector<std::string> words{ "one", "two", "three", "four", "five" };
      auto enumerated_words = words | rv::enumerate;

      for (auto const [index, word] : enumerated_words)
      {
         std::println("{} : {}", index, word);
      }

      std::println("");
#endif
   }
   
   // zip (https://en.cppreference.com/w/cpp/ranges/zip_view)
   {
#ifdef __cpp_lib_ranges_zip
      std::println("zip");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      std::vector<std::string> words{ "one", "two", "three", "four", "five" };
      auto zipped = rv::zip(numbers, words);

      for (auto const [number, word] : zipped)
      {
         std::println("{} : {}", number, word);
      }

      std::println("");
#endif
   }
   
   // zip_transform (https://en.cppreference.com/w/cpp/ranges/zip_transform_view)
   {
#if __cpp_lib_ranges_zip == 202110L
      std::println("zip_transform");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      std::vector<std::string> words{ "one", "two", "three", "four", "five" };

      auto zipped = rv::zip_transform(
         [](int number, std::string word) {
            return std::to_string(number) + " : " + word;
         },
         numbers, 
         words);

      std::ranges::for_each(zipped, [](auto e) {std::println("{}", e); });

      std::println("");
#endif
   }
   
   // adjacent (https://en.cppreference.com/w/cpp/ranges/adjacent_view)
   {
#if __cpp_lib_ranges_zip == 202110L
      std::println("adjacent");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto adjacent_numbers = numbers | rv::adjacent<3>;

      std::ranges::for_each(
         adjacent_numbers, 
         [](auto t) {
            auto [a, b, c] = t;
            std::println("{},{},{}", a, b, c); 
         });

      std::println("");
#endif
   }
   
   // adjacent_transform (https://en.cppreference.com/w/cpp/ranges/adjacent_transform_view)
   {
#if __cpp_lib_ranges_zip == 202110L
      std::println("adjacent_transform");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto adjacent_numbers = numbers | rv::adjacent_transform<3>(
         [](int a, int b, int c) {return a * b * c; });

      std::ranges::for_each(adjacent_numbers, [](auto e) {std::println("{}", e); });

      std::println("");
#endif
   }
   
   // join_with (https://en.cppreference.com/w/cpp/ranges/join_with_view)
   {
      std::println("join_with");

      std::vector<std::vector<int>> numbers{ {1, 1, 2}, {3, 5, 8}, {13} };
      auto joined_numbers = numbers | rv::join_with(0);

      rg::copy(joined_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
   }
   
   // slide (https://en.cppreference.com/w/cpp/ranges/slide_view)
   {
#ifdef __cpp_lib_ranges_slide
      std::println("slide");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto slide_numbers = numbers | rv::slide(3);

      std::ranges::for_each(
         slide_numbers,
         [](auto r) {
            rg::copy(r, std::ostream_iterator<int>{ std::cout, " " });
            std::println("");
         });

      std::println("");
#endif
   }
   
   // chunk (https://en.cppreference.com/w/cpp/ranges/chunk_view)
   {
#ifdef __cpp_lib_ranges_chunk
      std::println("chunk");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto chunk_numbers = numbers | rv::chunk(3);

      std::ranges::for_each(
         chunk_numbers,
         [](auto r) {
            rg::copy(r, std::ostream_iterator<int>{ std::cout, " " });
            std::println("");
         });

      std::println("");
#endif
   }
   
   // chunk_by (https://en.cppreference.com/w/cpp/ranges/chunk_by_view)
   {
#ifdef __cpp_lib_ranges_chunk_by
      std::println("chunk_by");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto chunk_numbers = numbers | rv::chunk_by([](int a, int b) {return a * b % 2 == 1; });

      std::ranges::for_each(
         chunk_numbers,
         [](auto r) {
            rg::copy(r, std::ostream_iterator<int>{ std::cout, " " });
            std::println("");
         });

      std::println("");
#endif
   }
   
   // stride (https://en.cppreference.com/w/cpp/ranges/stride_view)
   {
#ifdef __cpp_lib_ranges_stride
      std::println("stride");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      auto stride_numbers = numbers | rv::stride(3);

      rg::copy(stride_numbers, std::ostream_iterator<int>{ std::cout, " " });

      std::println("");
#endif
   }
   
   // cartesian_product (https://en.cppreference.com/w/cpp/ranges/cartesian_product_view)
   {
#ifdef __cpp_lib_ranges_cartesian_product	
      std::println("cartesian_product");

      std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13 };
      std::vector<std::string> words{ "one", "two", "three" };
      auto product = rv::cartesian_product(numbers, words);

      rg::for_each(
         product,
         [](auto t) {
            auto [number, word] = t;
            std::println("{} : {}", number, word);
         });

      std::println("");
#endif
   }
}