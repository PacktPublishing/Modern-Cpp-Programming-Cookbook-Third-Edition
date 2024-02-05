#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cassert>

namespace fs = std::filesystem;

namespace recipe_7_08
{
   void execute()
   {
      // append
#if defined(_WIN32) || defined(_WIN64)
      {
         auto path = fs::path{"C:\\Users\\Marius\\Documents"};

         path /= "Book";
         path = path / "Modern" / "Cpp";
         path.append("Programming");

         std::cout << path << '\n';
      }
#else
      {
         auto path = fs::path{ "/home/marius/docs" };
         path /= "book";
         path = path / "modern" / "cpp";
         path.append("programming");

         std::cout << path << '\n';
      }
#endif

      // concat
#if defined(_WIN32) || defined(_WIN64)
      {
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };

         path += "\\Book";
         path.concat("\\Modern");

         std::cout << path << '\n';
      }
#else
      {
         auto path = fs::path{ "/home/marius/docs" };

         path += "/book";
         path.concat("/modern");

         std::cout << path << '\n';
      }
#endif

      // decomposition
      {
#if defined(_WIN32) || defined(_WIN64)
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };
#else
         auto path = fs::path{ "/home/marius/docs" };
#endif

         path /= "sample.file.txt";

         std::cout
            << "root:        " << path.root_name() << '\n'
            << "root dir:    " << path.root_directory() << '\n'
            << "root path:   " << path.root_path() << '\n'
            << "rel path:    " << path.relative_path() << '\n'
            << "parent path: " << path.parent_path() << '\n'
            << "filename:    " << path.filename() << '\n'
            << "stem:        " << path.stem() << '\n'
            << "extension:   " << path.extension() << '\n';
      }

      // query
      {
#if defined(_WIN32) || defined(_WIN64)
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };
#else
         auto path = fs::path{ "/home/marius/docs" };
#endif

         path /= "sample.file.txt";

         std::cout
            << "has root:        " << path.has_root_name() << '\n'
            << "has root dir:    " << path.has_root_directory() << '\n'
            << "has root path:   " << path.has_root_path() << '\n'
            << "has rel path:    " << path.has_relative_path() << '\n'
            << "has parent path: " << path.has_parent_path() << '\n'
            << "has filename:    " << path.has_filename() << '\n'
            << "has stem:        " << path.has_stem() << '\n'
            << "has extension:   " << path.has_extension() << '\n';
      }

      // absolute / relative
      {
         auto path1 = fs::current_path();
#if defined(_WIN32) || defined(_WIN64)
         auto path2 = fs::path{ "marius\\temp" };
#else
         auto path2 = fs::path{ "marius/temp" };
#endif

         std::cout
            << "absolute: " << path1.is_absolute() << '\n'
            << "absolute: " << path2.is_absolute() << '\n';
      }

      // modifiers
      {
#if defined(_WIN32) || defined(_WIN64)
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };
#else
         auto path = fs::path{ "/home/marius/docs" };
#endif

         path /= "sample.file.txt";
        
         path.replace_filename("output");
         path.replace_extension(".log");

#if defined(_WIN32) || defined(_WIN64)
         assert(fs::path{ "C:\\Users\\Marius\\Documents\\output.log" } == path);
#else
         assert(fs::path{ "/home/marius/docs/output.log" } == path);
#endif

         path.remove_filename();
#if defined(_WIN32) || defined(_WIN64)
         assert(fs::path{ "C:\\Users\\Marius\\Documents\\" } == path);
#else
         assert(fs::path{ "/home/marius/docs/" } == path);
#endif
      }

      // preferred
      {
#if defined(_WIN32) || defined(_WIN64)
         auto path = fs::path{"Users/Marius/Documents"};
         path.make_preferred();

         assert(path == fs::path{ "Users\\Marius\\Documents"});
#else
         auto path = fs::path{ "\\home\\marius\\docs" };
         path.make_preferred();

         assert(path == fs::path{ "/home/marius/docs" });
#endif
      }

      // iterating
      {
#if defined(_WIN32) || defined(_WIN64)
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };
#else
         auto path = fs::path{ "/home/marius/docs" };
#endif

         path /= "sample.file.txt";

         for (auto const & part : path)
         {
            std::cout << part << '\n';
         }
      }

      // Windows path - should be tried on Linux
      {
         auto path = fs::path{ "C:\\Users\\Marius\\Documents" };
         path /= "Books\\Modern.cpp";

         std::cout << path << '\n';
         std::cout
            << "root: " << path.root_name() << '\n'
            << "root dir: " << path.root_directory() << '\n'
            << "root path: " << path.root_path() << '\n'
            << "rel path: " << path.relative_path() << '\n'
            << "parent path: " << path.parent_path() << '\n'
            << "filename: " << path.filename() << '\n'
            << "stem: " << path.stem() << '\n'
            << "extension: " << path.extension() << '\n';
      }

      // Linux path - should be tried on Windows 
      {
         auto path = fs::path{ "C:/Users/Marius/Documents" };
         path /= "Books/Modern.cpp";

         std::cout << path << '\n';
         std::cout
            << "root: " << path.root_name() << '\n'
            << "root dir: " << path.root_directory() << '\n'
            << "root path: " << path.root_path() << '\n'
            << "rel path: " << path.relative_path() << '\n'
            << "parent path: " << path.parent_path() << '\n'
            << "filename: " << path.filename() << '\n'
            << "stem: " << path.stem() << '\n'
            << "extension: " << path.extension() << '\n';
      }
   }
}