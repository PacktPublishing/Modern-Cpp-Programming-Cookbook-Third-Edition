#pragma once

#include <iostream>
#include <vector>

namespace recipe_2_01
{
   void execute()
   {
      {
         int age = 42;
         int attendance = 96321;
      }

      {
         unsigned int length = 32;
         short year = 2023; // same as short int
         unsigned long long filesize = 3'758'096'384;
      }

      {
         std::vector<int> arr{1, 2, 3};
         std::size_t items = arr.size();
      }

      {
         double price = 4.99;
         float temperature = 36.5;
         long double pi = 3.14159265358979323846264338327950288419716939937510L;
      }

      {
         std::int8_t x = 42;
         std::cout << x << '\n'; // [1] prints *

         std::int16_t y = 42;
         std::cout << y << '\n'; // [2] prints 42
      }

      {
         auto a = 4'234'871'523ll;
         auto b = 0xBAAD'F00D;
         auto c = 00'12'34;
         auto d = 0b1011'0101'0001'1001;

         auto e = 1'2'3'4'5;
      }
   }
}