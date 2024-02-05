#pragma once

#ifdef __cpp_lib_spanstream
#include <spanstream>
#include <span>
#endif

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace recipe_7_03
{
   void execute()
   {
#ifdef __cpp_lib_spanstream
      {
         char text[] = "1 1 2 3 5 8";
         std::ispanstream is{ std::span<char>{text} };
         int value;
         while (is >> value)
         {
            std::cout << value << '\n';
         }
      }

      {
         std::string text = "1 1 2 3 5 8";
         std::ispanstream is{ text };
         int value;
         while (is >> value)
         {
            std::cout << value << '\n';
         }
      }

      {
         std::ispanstream is{ "1 1 2 3 5 8" };
         int value;
         while (is >> value)
         {
            std::cout << value << '\n';
         }
      }

      {
         char text[15]{};
         int numbers[]{ 1, 1, 2, 3, 5, 8 };

         std::ospanstream os{ std::span<char>{text} };         
         for (int n : numbers)
         {
            os << n << ' ';
         }

         std::cout << text << '\n';
      }

      {
         char text[] = "1 1 2 3 5 8 ";
         std::vector<int> numbers;

         std::spanstream ss{ std::span<char>{text} };
         int value;
         while (ss >> value)
         {
            numbers.push_back(value);
         }

         ss.clear();
         ss.seekp(0);

         std::for_each(numbers.rbegin(), numbers.rend(), [&ss](const int n) {
            ss << n << ' ';
            });

         std::cout << text << '\n'; // prints 8 5 3 2 1 1
      }

      {
         char text[3]{};
         std::ospanstream os{ std::span<char>{text} };

         os << "42";
         
         auto pos = os.tellp();
         os << "44";
         if (!os.good())
         {
            os.clear();
            os.seekp(pos);
         }

         // text is {'4','2','4'}
         // prints (examples): 424╠╠╠╠╠... or 424MƂ�� etc.
         std::cout << text << '\n';
         
         os << '\0';

         // text is {'4','2','\0'}
         // prints: 42
         std::cout << text << '\n';
      }

      {
         char const text[] = "severity=1,code=42,message=generic error";

         std::unordered_map<std::string, std::string> m;

         std::string key, val;
         std::ispanstream is(text);

         while (std::getline(is, key, '=') >> std::ws)
         {
            if(std::getline(is, val, ','))
               m[key] = val;
         }

         // while (std::getline(std::getline(is, key, '=') >> std::ws, val, ','))
         //   m[key] = val;

         for (auto const & [k, v] : m)
         {
            std::cout << k << " : " << v << '\n';
         }
      }
#endif
   }
}