#pragma once

#ifdef __cpp_lib_stacktrace
#include <stacktrace>
#endif

#ifdef __cpp_lib_print
#include <print>
#include <format>
#endif

namespace recipe_6_19
{
   int plus_one(int n)
   {
#ifdef __cpp_lib_stacktrace
      std::cout << std::stacktrace::current() << '\n';
#endif

#ifdef __cpp_lib_stacktrace
      std::cout << std::to_string(std::stacktrace::current()) << '\n';
#endif

#if __cpp_lib_formatters == 202302L
      auto str = std::format("{}\n", std::stacktrace::current());
      std::cout << str;
#endif

#ifdef __cpp_lib_stacktrace
      for (auto const & frame : std::stacktrace::current())
      {
         std::cout << frame << '\n';
      }
#endif

#ifdef __cpp_lib_stacktrace
      for (auto const& frame : std::stacktrace::current())
      {
         std::cout << frame.source_file()
                   << "("<< frame.source_line() << ")"
                   << ": " << frame.description()
                   << '\n';
      }
#endif

#if __cpp_lib_formatters == 202302L
      auto trace = std::stacktrace::current();
      std::cout << std::to_string(trace) << '\n';
#endif

      return n + 1;
   }

   int double_n_plus_one(int n)
   {
      return plus_one(2 * n);
   }

   void execute()
   {
      std::cout << double_n_plus_one(42) << '\n';
   }
}