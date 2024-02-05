#include <vector>
#include <iostream>
#include <array>

#ifdef __cpp_lib_mdspan
#include <mdspan>
#endif

namespace recipe_6_13
{
   namespace v1
   {
      template <typename T, std::size_t ROWS, std::size_t COLS>
      struct matrix
      {
         T& 
#ifdef __cpp_multidimensional_subscript
         operator[]
#else
         operator()
#endif
         (std::size_t const r, std::size_t const c)
         {
            if (r >= ROWS || c >= COLS)
               throw std::runtime_error("Invalid index");

            return data[r * COLS + c];
         }

         T const& 
#ifdef __cpp_multidimensional_subscript
         operator[]
#else
         operator()
#endif
         (std::size_t const r, std::size_t const c) const
         {
            if (r >= ROWS || c >= COLS)
               throw std::runtime_error("Invalid index");

            return data[r * COLS + c];
         }

         std::size_t size() const { return data.size(); }
         std::size_t empty() const { return data.empty(); }

         template <std::size_t dimension>
         std::size_t extent() const
         {
            static_assert(dimension <= 1,
               "The matrix only has two dimensions.");

            if constexpr (dimension == 0) return ROWS;
            else if constexpr (dimension == 1) return COLS;
         }
      private:
         std::array<T, ROWS* COLS> data;
      };
   }

   namespace v1
   {
      void f(int data[3][2]) { /* … */ }
      void g(int** data, size_t row, size_t cols) { /* … */ }
      void h(std::vector<std::vector<int>> dat, size_t row, size_t cols) { /* … */ }
   }

   namespace v2
   {
#ifdef __cpp_lib_mdspan
      void f(std::mdspan<int, std::extents<size_t, 2, 3>> data) { /* … */ }
#endif
   }

   int g_data[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
   int* get_data() { return g_data; }

   void execute()
   {
#ifdef __cpp_lib_mdspan
      {
         int* data = get_data();
         std::mdspan<int, std::extents<size_t, 2, 3>> m(data);
      }

      {
         std::vector v{ 1,2,3,4,5,6,7,8,9 };

         std::mdspan<int, std::extents<size_t,
            2,
            std::dynamic_extent>> mv{ v.data(), 3 };
      }

      {
         int* data = get_data();

         std::mdspan<int, std::extents<size_t,
            std::dynamic_extent,
            std::dynamic_extent>> m(data, 2, 3);
      }

      {
         int* data = get_data();

         std::mdspan m(data, 2, 3);
      }

      {
         int* data = get_data();

         std::mdspan<int,
            std::extents<size_t, 2, 3>,
            std::layout_right> mv{ data };
      }

      {
         int* data = get_data();

         std::mdspan<int,
            std::extents<size_t, 2, 3>,
            std::layout_left> mv{ data };
      }

      {
         int* data = get_data();

         std::mdspan<int,
            std::extents<size_t, 2, 3>,
            std::layout_stride> mv{ data };
      }

      {
         using namespace v1;

         matrix<int, 2, 3> m;
         for (std::size_t r = 0; r < m.extent<0>(); r++)
         {
            for (std::size_t c = 0; c < m.extent<1>(); c++)
            {
#ifdef __cpp_multidimensional_subscript
               m[r, c] = r * m.extent<1>() + c + 1; // m[r,c] in C++23
#else
               m(r, c) = r * m.extent<1>() + c + 1; // m(r,c) previously
#endif
            }
         }
      }

      {
         std::array<int, 6> arr;
         std::mdspan m{ arr.data(), std::extents{2, 3} };

         for (std::size_t r = 0; r < m.extent(0); r++)
         {
            for (std::size_t c = 0; c < m.extent(1); c++)
            {
               m[r, c] = r * m.extent(1) + c + 1;
            }
         }
      }

      {
         std::vector v{ 1,2,3,4,5,6,7,8,9 };
         std::mdspan<int,
            std::extents<size_t, 2, 3>,
            std::layout_right> mv{ v.data() };
      }

      {
         std::vector v{ 1,2,3,4,5,6,7,8,9 };
         std::mdspan<int,
            std::extents<size_t,
            std::dynamic_extent,
            std::dynamic_extent>,
            std::layout_stride>
            mv{ v.data(), { std::dextents<size_t,2>{2, 3},
                            std::array<std::size_t, 2>{3, 1}} };
      }
#endif
   }
}