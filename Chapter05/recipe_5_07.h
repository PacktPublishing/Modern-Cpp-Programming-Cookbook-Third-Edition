#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

namespace recipe_5_07
{
   struct color
   {
      unsigned char red   = 0;
      unsigned char blue  = 0;
      unsigned char green = 0;
   };

   std::vector<color> make_gradient(color const& c1, color const& c2, size_t points)
   {
      std::vector<color> colors(points);

      auto rstep = static_cast<double>(c2.red - c1.red) / points;
      auto gstep = static_cast<double>(c2.green - c1.green) / points;
      auto bstep = static_cast<double>(c2.blue - c1.blue) / points;

      auto r = c1.red;
      auto g = c1.green;
      auto b = c1.blue;

      std::generate_n(colors.begin(), points, [&r, &g, &b, rstep, gstep, bstep] {
         color c {
            static_cast<unsigned char>(r),
            static_cast<unsigned char>(g),
            static_cast<unsigned char>(b) 
         };

         r += rstep;
         g += gstep;
         b += bstep;

         return c;
      });

      return colors;
   }

   void execute()
   {
      {
         std::vector<int> v(5);
         std::fill(v.begin(), v.end(), 42);
         // v = {42, 42, 42, 42, 42}

         std::array<int, 5> a;
         std::fill(a.begin(), a.end(), 42);
         // a = {42, 42, 42, 42, 42}
      }

      {
         std::vector<int> v(10);
         std::fill_n(v.begin(), 5, 42);
         // v = {42, 42, 42, 42, 42, 0, 0, 0, 0, 0}
      }

      {
         std::random_device rd{};
         std::mt19937 mt{ rd() };
         std::uniform_int_distribution<> ud{1, 10};

         std::vector<int> v(5);

         std::generate(v.begin(), v.end(), [&ud, &mt] {return ud(mt); });         
      }

      {
         std::vector<int> v(5);

         auto i = 1;
         std::generate_n(v.begin(), v.size(), [&i] { return i*i++; });
         // v = {1, 4, 9, 16, 25}
      }

      {
         std::vector<int> v(5);
         
         std::iota(v.begin(), v.end(), 1);
         // v = {1, 2, 3, 4, 5}
      }

      {
         color white { 255, 255, 255 };
         color black { 0, 0, 0 };
         std::vector<color> grayscale = make_gradient(white, black, 256);
         std::for_each(
            grayscale.begin(), grayscale.end(),
            [](color const& c) {
               std::cout << 
                  static_cast<int>(c.red) << ", "
                  << static_cast<int>(c.green) << ", "
                  << static_cast<int>(c.blue) << '\n';
            });
      }
   }
}