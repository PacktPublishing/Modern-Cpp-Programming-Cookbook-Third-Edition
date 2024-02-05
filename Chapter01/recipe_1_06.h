#pragma once

#ifdef __cpp_using_enum
#include <string_view>
#endif

namespace recipe_1_06
{   
   /*
   enum Status { Unknown, Created, Connected };

   enum Codes 
   { 
      OK, 
      Failure, 
      // Unknown redefinition
   };
   */

   /*
   namespace Status
   {
      enum Status { Unknown, Created, Connected };
   }

   namespace Codes
   {
      enum Codes { OK, Failure, Unknown };
   }
   */

   enum class Status { Unknown, Created, Connected };

   enum class Codes { OK, Failure, Unknown };


   enum class Codes2 : unsigned int;

   void print_code(Codes2 const code) {}

   enum class Codes2 : unsigned int
   {
      OK = 0,
      Failure = 1,
      Unknown = 0xFFFF0000U
   };

#ifdef __cpp_using_enum
   struct foo
   {
      enum class Status { Unknown, Created, Connected };

      using enum Status;
   };

   void process(Status const s)
   {
      switch (s)
      {
         using enum Status;
         case Unknown:   /*...*/ break;
         case Created:   /*...*/ break;
         case Connected: /*...*/ break;
      }
   }

   std::string_view to_string(Status const s)
   {
      switch (s)
      {
         using enum Status;
         case Unknown:   return "Unknown";
         case Created:   return "Created";
         case Connected: return "Connected";
         default:        return "";
      }
   }
#endif

   void old_api(unsigned flag)
   {
      if ((flag & 0x01) == 0x01) { /* can read */ }
      if ((flag & 0x02) == 0x02) { /* can write */ }
      if ((flag & 0x04) == 0x04) { /* can delete */ }
   }

   enum class user_rights : unsigned
   {
      None,
      Read = 1,
      Write = 2,
      Delete = 4
   };

   enum A {};
   enum class B {};

   void execute()
   {
      Codes code = Codes::Unknown;

      Codes c1 = Codes::OK;					      // OK
      //int c2 = Codes::Failure;   				   // error
      int c3 = static_cast<int>(Codes::Failure);// OK

      {
#ifdef __cpp_using_enum
         using Status::Unknown;
         Status s1 = Unknown;

         foo::Status s2 = foo::Created; // instead of foo::Status::Created
#endif
      }

      {
         old_api(1); // read only
         old_api(3); // read & write

         old_api(static_cast<int>(user_rights::Read)); // read only
         old_api(static_cast<int>(user_rights::Read) | static_cast<int>(user_rights::Write)); // read & write

         // C++23: std::to_underlying
         old_api(std::to_underlying(user_rights::Read));
         old_api(std::to_underlying(user_rights::Read) | std::to_underlying(user_rights::Write));

         // C++23: std::is_scoped_enum
         std::cout << std::is_scoped_enum_v<A> << '\n';
         std::cout << std::is_scoped_enum_v<B> << '\n';
      }
   }
}