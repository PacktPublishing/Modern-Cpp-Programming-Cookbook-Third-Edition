#pragma once

#ifdef __cpp_lib_format
#include <format>
#endif

namespace recipe_2_17
{
   namespace v1
   {
      struct employee
      {
         int         id;
         std::string firstName;
         std::string lastName;
      };
   }

   namespace v2
   {
      struct employee
      {
         int         id;
         std::string firstName;
         std::string lastName;
      };
   }

   namespace v3
   {
      struct employee
      {
         int         id;
         std::string firstName;
         std::string lastName;
      };
   }
}

#ifdef __cpp_lib_format
template <>
struct std::formatter<recipe_2_17::v1::employee>
{
   constexpr auto parse(std::format_parse_context& ctx)
   {
      return ctx.begin();
   }

   auto format(recipe_2_17::v1::employee const& e, std::format_context& ctx) const
   {
      return std::format_to(ctx.out(),
         "[{}] {} {}",
         e.id, e.firstName, e.lastName);
   }
};

template<>
struct std::formatter<recipe_2_17::v2::employee>
{
   constexpr auto parse(std::format_parse_context& ctx)
   {
      auto iter = begin(ctx);
      while(iter != ctx.end() && *iter != '}')
      {
         switch (*iter)
         {
         case 'L': 
            lexicographic_order = true; 
            break;
         case 'u': 
            uppercase = true; 
            break;
         case 'l': 
            lowercase = true; 
            break;
         }

         ++iter;
      }

      return iter;
   }

   auto format(recipe_2_17::v2::employee const& e, std::format_context& ctx) const
   {
      if (lexicographic_order)
         return std::format_to(ctx.out(), 
                               "[{}] {}, {}", 
                               e.id, 
                               text_format(e.lastName), 
                               text_format(e.firstName));

      return std::format_to(ctx.out(), 
                            "[{}] {} {}", 
                            e.id, 
                            text_format(e.firstName),
                            text_format(e.lastName));
   }

private:
   bool lexicographic_order = false;
   bool uppercase = false;
   bool lowercase = false;
   
   constexpr std::string text_format(std::string text) const
   {
      if(lowercase)
         std::transform(text.begin(), text.end(), text.begin(), ::tolower);
      else if(uppercase)
         std::transform(text.begin(), text.end(), text.begin(), ::toupper);
      return text;
   }
};

template<>
struct std::formatter<recipe_2_17::v3::employee> : std::formatter<char const*>
{
   auto format(recipe_2_17::v3::employee const& e, std::format_context& ctx) const
   {
      return std::format_to(ctx.out(), "[{}] {} {}",
         e.id, e.firstName, e.lastName);
   }
};

#endif

namespace recipe_2_17
{
   void execute()
   {
#ifdef __cpp_lib_format
      {
         v1::employee e{ 42, "John", "Doe" };

         auto s1 = std::format("{}", e);   // [42] John Doe
         std::cout << s1 << '\n';

         //auto s2 = std::format("{:L}", e); // error
      }
      
      {
         v2::employee e{ 42, "John", "Doe" };

         auto s1 = std::format("{}", e);     // [42] John Doe
         std::cout << s1 << '\n';

         auto s2 = std::format("{:L}", e);   // [42] Doe, John
         std::cout << s2 << '\n';

         auto s3 = std::format("{:u}", e);   // [42] JOHN DOE
         std::cout << s3 << '\n';

         auto s4 = std::format("{:lL}", e);  // [42] doe, john
         std::cout << s4 << '\n';

         // uppercase ignored when lowercase also specified
         auto s5 = std::format("{:ulL}", e);  // [42] doe, john
         std::cout << s5 << '\n';

         auto s6 = std::format("{0} = {0:L}", e);     // [42] John Doe = [42] Doe, John
         std::cout << s6 << '\n';

         // unknown format will be ignored
         auto s7 = std::format("{:A}", e);   // [42] John Doe
         std::cout << s7 << '\n';
      }
      
      {
         v3::employee e{ 42, "John", "Doe" };

         auto s1 = std::format("{}", e);   // [42] John Doe
         std::cout << s1 << '\n';
      }
#endif
   }
}
