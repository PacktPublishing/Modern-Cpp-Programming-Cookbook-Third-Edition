#pragma once

#include <array>

#ifdef __cpp_lib_mdspan
#include <mdspan>
#endif

namespace recipe_1_15
{
   template <typename T>
   struct some_buffer
   {
      some_buffer(size_t const size) :data(size)
      {}

      size_t size() const { return data.size(); }

      T const& operator[](size_t const index) const
      {
         if (index >= data.size())
            std::runtime_error("invalid index");

         return data[index];
      }

      T& operator[](size_t const index)
      {
         if (index >= data.size())
            std::runtime_error("invalid index");

         return data[index];
      }

   private:
      std::vector<T> data;
   };

   namespace v1
   {
      template <typename T, size_t ROWS, size_t COLS>
      struct matrix
      {
         T& operator()(size_t const row, size_t const col)
         {
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

         T const& operator()(size_t const row, size_t const col) const
         {
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

      private:
         std::array<T, ROWS* COLS> data;
      };
   }

   namespace v2
   {
      template <typename T, size_t ROWS, size_t COLS>
      struct matrix
      {
         T& operator[](std::initializer_list<size_t> index)
         {
            size_t row = *index.begin();
            size_t col = *(index.begin() + 1);
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

         T const& operator[](std::initializer_list<size_t> index) const
         {
            size_t row = *index.begin();
            size_t col = *(index.begin() + 1);
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

      private:
         std::array<T, ROWS* COLS> data;
      };

   }

#ifdef __cpp_multidimensional_subscript
   namespace v3
   {
      template <typename T, size_t ROWS, size_t COLS>
      struct matrix
      {
         T& operator[](size_t const row, size_t const col)
         {
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

         T const& operator[](size_t const row,
            size_t const col) const
         {
            if (row >= ROWS || col >= COLS)
               throw std::runtime_error("invalid index");

            return data[row * COLS + col];
         }

      private:
         std::array<T, ROWS* COLS> data;
      };
   }
#endif

   void execute()
   {
      {
         using namespace v1;

         matrix<int, 2, 3> m;
         m(0, 0) = 1;
      }

      {
         using namespace v2;

         matrix<int, 2, 3> m;
         m[{0, 0}] = 1;
      }

      {
#ifdef __cpp_multidimensional_subscript
         using namespace v3;

         matrix<int, 2, 3> m;
         m[0, 0] = 1;
#endif
      }

      {
#ifdef __cpp_lib_mdspan
         int data[2 * 3] = {};
         auto m = std::mdspan<int, std::extents<2, 3>>(data);
         m[0, 0] = 1;
#endif
      }
   }
}