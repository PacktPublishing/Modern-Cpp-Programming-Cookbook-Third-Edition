#pragma once

#include <string>
#include <vector>
#include <optional>

namespace recipe_6_08
{
   struct booking
   {
      int                        id;
      int                        nights;
      double                     rate;
      std::string                description;
      std::vector<std::string>   extras;
   };

   std::optional<booking> make_booking(std::string_view description, int nights, double rate)
   {
      static int nextid = 1;

      return booking
      {
         nextid++,
         nights,
         rate,
         description.data(),
         {}
      };
   }

   std::optional<booking> add_rental(std::optional<booking> b)
   {
      b->extras.push_back("Car rental");

      return b;
   }

   std::optional<booking> add_insurance(std::optional<booking> b)
   {
      b->extras.push_back("Travel insurance");

      return b;
   }

   double calculate_price(std::optional<booking> b)
   {
      return b->nights * b->rate * 1.1;
   }

   double apply_discount(std::optional<double> p)
   {
      return *p * .9;
   }


   void execute()
   {
#if __cpp_lib_optional == 202110L
      {
         auto b = make_booking("Hotel California", 3, 300);
         auto p = b.transform(calculate_price);

         std::cout << *p << '\n';
      }

      {
         auto b = make_booking("Hotel California", 3, 300);
         b = b.and_then(add_insurance);
         auto p = b.transform(calculate_price);

         std::cout << *p << '\n';
      }

      {
         auto b = make_booking("Hotel California", 3, 300)
                  .or_else([]() -> std::optional<booking> {
                     std::cout << "creating the booking failed!\n";
                     return std::nullopt;
                  });
      }

      {
         auto p =
            make_booking("Hotel California", 3, 300)
            .and_then(add_rental)
            .and_then(add_insurance)
            .or_else([]() -> std::optional<booking> {
               std::cout << "creating the booking failed!\n";
               return std::nullopt; })
            .transform(calculate_price)
            .transform(apply_discount)
            .or_else([]() -> std::optional<double> {
               std::cout << "computing price failed!\n"; return -1; });

         if (p)
            std::cout << *p << '\n';
      }
#endif
   }
}