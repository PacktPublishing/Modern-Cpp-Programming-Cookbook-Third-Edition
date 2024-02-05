#pragma once

#include <vector>
#include <iostream>
#include <cstring>

#ifdef __cpp_lib_int_pow2
#include <bit>
#else
namespace std
{
   template <class To, class From>
   typename std::enable_if_t<
      (sizeof(To) == sizeof(From)) &&
      std::is_trivially_copyable_v<From> &&
      std::is_trivial_v<To>,
      // this implementation requires that To is trivially default constructible
      To>
      // constexpr support needs compiler magic
      bit_cast(const From& src) noexcept
   {
      To dst;
      std::memcpy(&dst, &src, sizeof(To));
      return dst;
   }

   template <class T, typename S = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool> && !std::is_same_v<T, char>>>
   constexpr bool has_single_bit(T x) noexcept
   {
      return x != 0 && (x & (x - 1)) == 0;
   }
}
#endif

namespace recipe_5_04
{
   void execute()
   {
      // std::bit_cast
      {
         const double pi = 3.1415927;
         const uint64_t bits = std::bit_cast<uint64_t>(pi);
         const double pi2 = std::bit_cast<double>(bits);

         std::cout
            << std::fixed << pi << '\n'   // prints 3.1415923
            << std::hex << bits << '\n'   // prints 400921fb5a7ed197
            << std::fixed << pi2 << '\n';  // prints 3.1415923

         std::cout << std::dec;
      }

      // std::has_single_bit
      {
         std::cout << std::boolalpha << std::has_single_bit(0u) << '\n'; // false
         std::cout << std::boolalpha << std::has_single_bit(1u) << '\n'; // true
         std::cout << std::boolalpha << std::has_single_bit(2u) << '\n'; // true
         std::cout << std::boolalpha << std::has_single_bit(3u) << '\n'; // false
         std::cout << std::boolalpha << std::has_single_bit(4u) << '\n'; // true
         //std::cout << std::boolalpha << std::has_single_bit(42.99) << '\n'; // ERROR
      }

#ifdef __cpp_lib_int_pow2
      // bit_ceil
      {
         std::cout << std::bit_ceil(0u) << '\n';  // 0
         std::cout << std::bit_ceil(3u) << '\n';  // 4
         std::cout << std::bit_ceil(4u) << '\n';  // 4
         std::cout << std::bit_ceil(31u) << '\n'; // 32
         std::cout << std::bit_ceil(42u) << '\n'; // 64
      }

      // bin_floor
      {
         std::cout << std::bit_floor(0u) << '\n';  // 0
         std::cout << std::bit_floor(3u) << '\n';  // 2
         std::cout << std::bit_floor(4u) << '\n';  // 4
         std::cout << std::bit_floor(31u) << '\n';  // 16
         std::cout << std::bit_floor(42u) << '\n';  // 32
      }

      // bit_width
      {

         std::cout << std::bit_width(0u)    << '\n';  // 0
         std::cout << std::bit_width(2u)    << '\n';  // 2
         std::cout << std::bit_width(15u)   << '\n';  // 4
         std::cout << std::bit_width(16u)   << '\n';  // 5
         std::cout << std::bit_width(1000u) << '\n';  // 10
      }

      // rotl
      {
         unsigned char n = 0b00111100;
         auto vl1 = std::rotl(n, 0); // 0b00111100
         auto vl2 = std::rotl(n, 1); // 0b01111000
         auto vl3 = std::rotl(n, 3); // 0b11100001
         auto vl4 = std::rotl(n, 9); // 0b01111000
         auto vl5 = std::rotl(n, -2);// 0b00001111
      }

      // rotr
      {
         unsigned char n = 0b00111100;
         auto vr1 = std::rotr(n, 0); // 0b00111100
         auto vr2 = std::rotr(n, 1); // 0b00011110
         auto vr3 = std::rotr(n, 3); // 0b10000111
         auto vr4 = std::rotr(n, 9); // 0b00011110
         auto vr5 = std::rotr(n, -2);// 0b11110000
      }

      // popcount
      {
         std::cout << std::popcount(0b00000000u) << '\n'; // 0
         std::cout << std::popcount(0b11111111u) << '\n'; // 8
         std::cout << std::popcount(0b10000001u) << '\n'; // 2
      }

      // countl_zero
      {
         std::cout << std::countl_zero(0b00000000u) << '\n'; // 8
         std::cout << std::countl_zero(0b11111111u) << '\n'; // 0
         std::cout << std::countl_zero(0b00111010u) << '\n'; // 2
      }

      // countl_one
      {
         std::cout << std::countl_one(0b00000000u) << '\n'; // 0
         std::cout << std::countl_one(0b11111111u) << '\n'; // 8
         std::cout << std::countl_one(0b11000101u) << '\n'; // 2
      }

      // countr_zero
      {
         std::cout << std::countr_zero(0b00000000u) << '\n'; // 8
         std::cout << std::countr_zero(0b11111111u) << '\n'; // 0
         std::cout << std::countr_zero(0b00111010u) << '\n'; // 1
      }

      // countr_one
      {
         std::cout << std::countr_one(0b00000000u) << '\n'; // 0
         std::cout << std::countr_one(0b11111111u) << '\n'; // 8
         std::cout << std::countr_one(0b11000101u) << '\n'; // 1
      }
#endif
   }
}
