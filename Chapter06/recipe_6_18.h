#pragma once

#include <string_view>

#ifdef __cpp_lib_source_location	
#include <source_location>
#endif

namespace recipe_6_18
{
   namespace v1
   {
      void log(std::string_view message, std::string_view file, int line, std::string_view function)
      {
         std::cout << file << '('
            << line << ") '"
            << function << "': "
            << message << '\n';
      }
   }

   namespace v2
   {
#ifdef __cpp_lib_source_location	
      void log(std::string_view message,
         std::source_location const location = std::source_location::current())
      {
         std::cout << location.file_name() << '('
            << location.line() << ':'
            << location.column() << ") '"
            << location.function_name() << "': "
            << message << '\n';
      }
#endif
   }

   void execute()
   {
      v1::log("This is a log entry!", __FILE__, __LINE__, __FUNCTION__);

      v2::log("This is a log entry!");
   }
}