#pragma once

#include <vector>

#ifdef __cpp_lib_expected
#include <expected>
#endif

#ifdef __cpp_lib_print
#include <print>
#endif

namespace recipe_6_11
{
   enum class Status
   {
      Success, InvalidFormat, InvalidLength, FilterError,
   };

   enum class Filter
   {
      Pixelize, Sepia, Blur
   };

   using Image = std::vector<char>;

   bool IsValidFormat(Image const& img) { return true; }
   bool IsValidLength(Image const& img) { return true; }
   bool Transform(Image& img, Filter const filter)
   {
      switch (filter)
      {
      case Filter::Pixelize:
         img.push_back('P');
         std::cout << "Applying pixelize\n";
         break;
      case Filter::Sepia:
         img.push_back('S');
         std::cout << "Applying sepia\n";
         break;
      case Filter::Blur:
         img.push_back('B');
         std::cout << "Applying blur\n";
         break;
      }
      return true;
   }

#ifdef __cpp_lib_expected
   std::expected<Image, Status> ApplyFilter(Image img, Filter const filter)
   {
      if (!IsValidFormat(img))
         return std::unexpected<Status> {Status::InvalidFormat};

      if (!IsValidLength(img))
         return std::unexpected<Status> {Status::InvalidLength};

      if (!Transform(img, filter))
         return std::unexpected<Status> {Status::FilterError};

      return img;
   }

   std::expected<Image, Status> FlipHorizontally(Image img)
   {
      return Image{ img.rbegin(), img.rend() };
   }
#endif

   void ShowImage(Image const& img)
   {
      std::cout << "[img]:";
      for (auto const& e : img) std::cout << e;
      std::cout << '\n';
   }

   void ShowError(Status const status)
   {
#ifdef __cpp_lib_print
      std::println("Error code: {}\n", static_cast<int>(status));
#else
      std::cout << "Error code: " << static_cast<int>(status) << '\n';
#endif
   }


   void execute()
   {
#ifdef __cpp_lib_expected
      {
         Image img{ 'I','M','G' };

         auto result = ApplyFilter(img, Filter::Sepia);
         if (result)
         {
            ShowImage(result.value());
         }
         else
         {
            ShowError(result.error());
         }
      }

      {
         Image img{ 'I','M','G' };

         auto result = ApplyFilter(img, Filter::Sepia);
         result = ApplyFilter(result.value(), Filter::Pixelize);
         result = ApplyFilter(result.value(), Filter::Blur);
         result = FlipHorizontally(result.value());
         if (result)
         {
            ShowImage(result.value());
         }
         else
         {
            ShowError(result.error());
         }
      }
#endif

      // monadic operations
#if __cpp_lib_expected == 202211L
      {
         Image img{ 'I','M','G' };

         ApplyFilter(img, Filter::Sepia)
            .and_then([](Image result) {
               return ApplyFilter(result, Filter::Pixelize);
            })
            .and_then([](Image result) {
               return ApplyFilter(result, Filter::Blur);
            })
            .and_then(FlipHorizontally)
            .and_then([](Image result) {
               ShowImage(result);
               return std::expected<Image, Status>{result};
            })
            .or_else([](Status status) {
               ShowError(status);
               return std::expected<Image, Status>{std::unexpect, status};
            });

      }

      {
         Image img{ 'I','M','G' };

         auto obj = ApplyFilter(img, Filter::Sepia)
            .and_then([](Image result) {
               return ApplyFilter(result, Filter::Pixelize);
            })
            .and_then([](Image result) {
               return ApplyFilter(result, Filter::Blur);
            })
            .and_then(FlipHorizontally)
            .and_then([](Image result) {
               ShowImage(result);
               return std::expected<Image, Status>{result};
            })
            .or_else([](Status status) {
               ShowError(status);
               return std::expected<Image, Status>{std::unexpect, status};
            })
            .transform([](Image result) {
               std::stringstream s;
               s << std::quoted(std::string(result.begin(), result.end()));
               return s.str();
            })
            .transform_error([](Status status) {
               return status == Status::Success ? "success" : "fail";
            });

            if (obj)
               std::cout << obj.value() << '\n';
            else
               std::cout << obj.error() << '\n';
      }

#endif
   }
}