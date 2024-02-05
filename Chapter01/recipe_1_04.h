#pragma once

#include <iostream>
#include <string>

namespace recipe_1_04
{
   struct Point
   {
      double x;
      double y;

      Point(double const x = 0.0, double const y = 0.0) : x(x), y(y) {}
   };

   struct foo
   {
      foo() { std::cout << "default constructor" << '\n'; }
      foo(std::string const & text) { std::cout << "constructor '" << text << "'" << '\n'; }
      foo(foo const & other) { std::cout << "copy constructor" << '\n'; }
      foo(foo&& other) { std::cout << "move constructor" << '\n'; };
      foo& operator=(foo const & other) { std::cout << "assignment" << '\n'; return *this; }
      foo& operator=(foo&& other) { std::cout << "move assignment" << '\n'; return *this; }
      ~foo() { std::cout << "destructor" << '\n'; }
   };

   enum class TextVerticalAlignment { Top, Middle, Bottom };
   enum class TextHorizontalAlignment { Left, Center, Right };

   struct Control
   {
      const int DefaultHeight = 14;
      const int DefaultWidth = 80;
      
      std::string text;
      TextVerticalAlignment valign = TextVerticalAlignment::Middle;
      TextHorizontalAlignment halign = TextHorizontalAlignment::Left;

      Control(std::string const & t) : text(t) 
      {}

      Control(std::string const & t,
         TextVerticalAlignment const va,
         TextHorizontalAlignment const ha) : text(t), valign(va), halign(ha) 
      {}
   };

   void execute()
   {
      {
         struct bar
         {
            foo f;

            bar(foo const & value)
            {
               f = value;
            }
         };

         foo f;
         bar b(f);
      }

      {
         struct bar
         {
            foo f;

            bar(foo const & value) : f(value)
            {
            }
         };

         foo f;
         bar b(f);
      }

      {
         enum class TextFlow { LeftToRight, RightToLeft };

         struct Control
         {
            const int DefaultHeight = 20;
            const int DefaultWidth = 100;

            TextFlow textFlow = TextFlow::LeftToRight;
            std::string text;

            Control(std::string const & t) : text(t)
            {}
         };
      }

      {
         struct bar
         {
            foo f{ "default value" };

            bar() : f{ "constructor initializer" }
            {
            }
         };

         bar b;
      }
   }
}