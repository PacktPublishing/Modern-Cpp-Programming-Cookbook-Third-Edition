export module geometry:literals;

import :core;

namespace geometry_literals
{
   export int_point operator ""_ip(const char* ptr, std::size_t)
   {
      int x = 0, y = 0;
      if(ptr)
      {
         while (*ptr != ',' && *ptr != ' ') 
            x = x * 10 + (*ptr++ - '0');
         while (*ptr == ',' || *ptr == ' ') ptr++;
         while (*ptr != 0) 
            y = y * 10 + (*ptr++ - '0');
      }
      return { x, y };
   }
}
