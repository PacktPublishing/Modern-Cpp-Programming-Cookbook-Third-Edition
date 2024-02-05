#include <iostream>
#include <string>
#include <vector>
#include <concepts>

namespace v1
{
   auto sum(auto a, auto b)
   {
      return a + b;
   }
}

namespace v2
{
   auto sum(std::integral auto a, std::integral auto b)
   {
      return a + b;
   }
}

namespace v3
{
   auto sum(auto a, auto b)
   {
      return a + b;
   }

   template <>
   auto sum(char const* a, char const* b)
   {
      return std::string(a) + std::string(b);
   }
}

namespace v4
{
   auto sum(std::integral auto ... args)
   {
      return (args + ...);
   }
}

int main()
{
   {
      using namespace v1;

      auto a = sum(40, 2);    // 42
      auto b = sum(42.0, 2);  // 44.0
   }

   {
      using namespace v2;

      auto a = sum(40, 2);    // 42
      // auto b = sum(42.0, 2);  // error
   }

   {
      using namespace v3;

      auto a = sum(40, 2);       // 42
      auto b = sum("40", "2");   // "402"
   }

   {
      using namespace v4;

      auto a = sum(10, 30, 2);   // 42
   }

   {
      auto lsum = [](std::integral auto a, std::integral auto b)
         {
            return a + b;
         };

      auto a = lsum(40, 2);    // 42
      //auto b = lsum(42.0, 2);  // error
   }
}