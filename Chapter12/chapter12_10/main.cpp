#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
#include <format>

struct Product
{
   int         id;
   std::string name;
   double      price;
};

int main()
{
   // finding elements in a range

   {
      std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };

      auto it = std::ranges::find(v, 3);
      if (it != v.cend()) std::cout << *it << '\n';
   }

   {
      std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };

      auto it = std::ranges::find(v.begin(), v.end(), 3);
      if (it != v.cend()) std::cout << *it << '\n';
   }

   {
      std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };

      auto it = std::ranges::find_if(v, [](int const n) {return n > 10; });
      if (it != v.cend()) std::cout << *it << '\n';
   }

   {
      std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };
      std::vector<int> p{ 5, 7, 11 };

      auto it = std::ranges::find_first_of(v, p);

      if (it != v.cend())
         std::cout << "found " << *it
         << " at index " << std::ranges::distance(v.cbegin(), it)
         << '\n';
   }

   // sorting a range
   {
      std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };

      std::ranges::sort(v);
      // v = {1, 1, 2, 3, 5, 8, 13}

      std::ranges::sort(v, std::ranges::greater());
      // v = {13, 8, 5, 3, 2, 1 ,1}
   }

   {
      std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };

      auto sorted = std::ranges::is_sorted(v);

      sorted = std::ranges::is_sorted(v, std::ranges::greater());
   }

   {
      std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };

      auto it = std::ranges::is_sorted_until(v);

      auto length = std::ranges::distance(v.cbegin(), it);
      // length = 2
   }

   // initializing a range
   {
      std::vector<int> v(5);
      std::ranges::fill(v, 42);
      // v = {42, 42, 42, 42, 42}

      std::array<int, 5> a;
      std::ranges::fill(a, 42);
      // a = {42, 42, 42, 42, 42}
   }

   {
      std::vector<int> v(10);
      std::ranges::fill_n(v.begin(), 5, 42);
      // v = {42, 42, 42, 42, 42, 0, 0, 0, 0, 0}
   }

   {
      std::vector<int> v(5);

      auto i = 1;
      std::ranges::generate_n(v.begin(), v.size(), [&i] { return i * i++; });
      // v = {1, 4, 9, 16, 25}
   }

   {
      std::vector<int> v(5);

      std::ranges::iota(v, 1);
      // v = {1, 2, 3, 4, 5}
   }

   // constrained algorithms + ranges
   {
      std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };

      auto range =
         v |
         std::views::filter([](int const n) {return n % 2 == 1; }) |
         std::views::transform([](int const n) {return n * n; }) |
         std::views::take(4);

      std::ranges::for_each(range, [](int const n) {std::cout << n << ' '; });

      std::cout << '\n';

      auto it = std::ranges::find_if(range, [](int const n) {return n > 10; });

      if (it != range.end())
         std::cout << *it << '\n';
   }

   // projection
   {
      std::vector<Product> products
      {
         {1, "pen", 15.50},
         {2, "pencil", 9.99},
         {3, "rubber", 5.0},
         {4, "ruler", 5.50},
         {5, "notebook", 12.50}
      };

      auto pos = std::find_if(
         products.begin(), products.end(),
         [](Product const& p) {
            return p.price == 12.5;
         });
      if (pos != products.end())
         std::cout << pos->name << '\n';

      auto it = std::ranges::find(products, 12.50, &Product::price);
      if (it != products.end())
         std::cout << it->name << '\n';

      std::ranges::sort(products, std::ranges::less(), &Product::name);
      std::ranges::for_each(products, [](Product const& p)
         {
            std::cout << std::format("{} = {}\n", p.name, p.price);
         });
   }
}