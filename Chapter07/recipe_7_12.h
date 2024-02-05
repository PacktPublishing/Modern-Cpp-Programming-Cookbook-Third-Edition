#pragma once

#include <iostream>
#include <filesystem>
#include <iomanip>

namespace fs = std::filesystem;

namespace recipe_7_12
{
   void print_line(std::string_view prefix, std::filesystem::path const& path)
   {
      std::cout << prefix << path << '\n';
   }

   void visit_directory(fs::path const & dir)
   {
      if (fs::exists(dir) && fs::is_directory(dir))
      {
         for (auto const & entry : fs::directory_iterator(dir))
         {
            auto filename = entry.path().filename();
            if (fs::is_directory(entry.status()))
               print_line("[+]", filename);
            else if (fs::is_symlink(entry.status()))
               print_line("[>]", filename);
            else if (fs::is_regular_file(entry.status()))
               print_line("   ", filename);
            else
               print_line("[?]", filename);
         }
      }
      else
      {
         std::cout 
            << "Directory " 
            << std::quoted(dir.string()) 
            << " does not exit" << '\n';
      }
   }

   void visit_directory_rec(fs::path const & dir)
   {
      if (fs::exists(dir) && fs::is_directory(dir))
      {
         for (auto const & entry : fs::recursive_directory_iterator(dir))
         {
            auto filename = entry.path().filename();
            if (fs::is_directory(entry.status()))
               print_line("[+]", filename);
            else if (fs::is_symlink(entry.status()))
               print_line("[>]", filename);
            else if (fs::is_regular_file(entry.status()))
               print_line("   ", filename);
            else
               print_line("[?]", filename);
         }
      }
      else
      {
         std::cout
            << "Directory "
            << std::quoted(dir.string())
            << " does not exit" << '\n';
      }
   }

   void visit_directory_rec_ordered(
      fs::path const & dir, 
      bool const recursive = false, 
      unsigned int const level = 0)
   {
      if (fs::exists(dir) && fs::is_directory(dir))
      {
         auto lead = std::string(level*3, ' ');
         for (auto const & entry : fs::directory_iterator(dir))
         {
            auto filename = entry.path().filename();
            if (fs::is_directory(entry.status()))
            {
               print_line(lead + "[+]", filename);
               if(recursive)
                  visit_directory_rec_ordered(entry, recursive, level+1);
            }
            else if (fs::is_symlink(entry.status()))
               print_line(lead + "[>]", filename);
            else if (fs::is_regular_file(entry.status()))
               print_line(lead + "   ", filename);
            else
               print_line(lead + "[?]", filename);
         }
      }
      else
      {
         std::cout
            << "Directory "
            << std::quoted(dir.string())
            << " does not exit" << '\n';
      }
   }

   std::uintmax_t dir_size(fs::path const & path)
   {     
      if (fs::exists(path) && fs::is_directory(path))
      {
         auto size = static_cast<uintmax_t>(0);

         for (auto const & entry : fs::recursive_directory_iterator(path))
         {
            if (fs::is_regular_file(entry.status()) ||
               fs::is_symlink(entry.status()))
            {
               auto err = std::error_code{};
               auto filesize = fs::file_size(entry, err);
               if (!err)
                  size += filesize;
            }
         }

         return size;
      }

      return static_cast<uintmax_t>(-1);
   }

   void execute()
   {
      auto path = fs::current_path() / "test";
      visit_directory(path);
      visit_directory_rec(path);
      visit_directory_rec_ordered(path, true);

      std::cout << "dir size:" << dir_size(path) << '\n';
   }
}