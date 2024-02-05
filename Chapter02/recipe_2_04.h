#pragma once

#include <string>

namespace recipe_2_04
{
   void f(char) {}
   void f(signed char) {}
   void f(unsigned char) {}

   void execute()
   {
      {
         char c = 'C';
         const char* s = "C++";
         std::cout << c << s << '\n';
      }

      {
         wchar_t c = L'Ʃ';
         const wchar_t* s = L"δῆμος";
         std::wcout << c << s << '\n';
      }

      {
#ifdef __cpp_char8_t
         char8_t c = u8'A';
         const char8_t* s = u8"Æthelflæd";
#endif
      }

      {
         char16_t c = u'Æ';
         const char16_t* s = u"Æthelflæd";
      }

      {
         char32_t c = U'👏';
         const char32_t* s = U"🙈🙉🙊";
      }

      {
         std::cout << std::is_same_v<char, signed char> << '\n';   // prints 0
         std::cout << std::is_same_v<char, unsigned char> << '\n'; // prints 0
      }

      {
         auto c1 = 'a';     // char
         auto c2 = L'b';    // what_t
         auto c3 = u8'c';   // char8_t in C++20
         auto c4 = u'd';    // char16_t
         auto c5 = U'e';    // char32_t

         auto sa1 = "a";    // const char*
         auto sa2 = L"a";   // const wchar_t*
         auto sa3 = u8"a";  // const char8_t* in C++20
         auto sa4 = u"a";   // const char16_t*
         auto sa5 = U"a";   // const char32_t*
      }

      {
         using namespace std::string_literals;

         auto s1 = "a"s;    // std::string
         auto s2 = L"a"s;   // std::wstring
         auto s3 = u8"a"s;  // std::u8string
         auto s4 = u"a"s;   // std::u16string
         auto s5 = U"a"s;   // std::u32string
      }

      {
#ifdef __cpp_unicode_literals
         std::u16string hb = u"Harald Bluetooth \u16BC\u16d2";                // ᚼᛒ
         std::u32string eh = U"Egyptian hieroglyphs \U00013000 \U000131B2";   // 𓀀 𓆲
#endif
      }

      {
#ifdef __cpp_named_character_escapes
         std::u16string hb = u"Harald Bluetooth \N{Runic Letter Long-Branch-Hagall H}\N{Runic Letter Berkanan Beorc Bjarkan B}";
         std::u32string eh = U"Egyptian hieroglyphs \N{EGYPTIAN HIEROGLYPH A001} \N{EGYPTIAN HIEROGLYPH M003A}";
#endif
      }

      {
         std::u32string eh = U"Egyptian hieroglyphs \u{13000} \u{131B2}"; // 𓀀 𓆲
      }
   }
}