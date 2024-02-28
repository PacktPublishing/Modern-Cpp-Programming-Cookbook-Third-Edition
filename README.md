# Modern C++ Programming Cookbook, 3rd Edition
This is the code repository for [Modern C++ Programming Cookbook - 3rd Edition](https://www.packtpub.com/product/modern-c-programming-cookbook-third-edition/9781835080542), published by [Packt]. It contains all the supporting project files necessary to work through the book from start to finish.


**Master modern C++ including the latest features of C++23 with 140+ practical recipes**

The author of this book is -Marius Bancila

## About the Book
The updated third edition of Modern C++ Programming Cookbook addresses the latest features of C++23, such as the stack library, the expected and mdspan types, span buffers, formatting library improvements, and updates to the ranges library. It also gets into more C++20 topics not previously covered, such as sync output streams and source_location. The book is organized in the form of practical recipes covering a wide range of real-world problems.

It gets into the details of all the core concepts of modern C++ programming, such as functions and classes, iterators and algorithms, streams and the file system, threading and concurrency, smart pointers and move semantics, and many others. You will cover the performance aspects of programming in depth, and learning to write fast and lean code with the help of best practices.

You will explore useful patterns and the implementation of many idioms, including pimpl, named parameter, attorney-client, and the factory pattern. A chapter dedicated to unit testing introduces you to three of the most widely used libraries for C++: Boost.Test, Google Test, and Catch2.

By the end of this modern C++ programming book, you will be able to effectively leverage the features and techniques of C++11/14/17/20/23 programming to enhance the performance, scalability, and efficiency of your applications.

## Key Takeaways
- Explore the new C++23 language and library features
- Become skilled at using the built-in support for threading and concurrency for daily tasks
- Leverage the standard library and work with containers, algorithms, and iterators
- Solve text searching and replacement problems using regular expressions
- Work with different types of strings and learn the various aspects of compilation
- Take advantage of the file system library to work with files and directories
- Implement various useful patterns and idioms
- Explore the widely used testing frameworks for C++

## Outline and Chapter Summary

### Chapter 01, Learning Modern Core Language Features
This chapter introduces the evolution of the C++ language through its major transformations with the release of C++11 and subsequent versions like C++14, C++17, C++20, and C++23. These updates have brought about new concepts, streamlined syntax and semantics, and fundamentally altered coding practices, ushering in what is termed as modern C++ code. The chapter briefly discusses some key language features introduced since C++11, such as the use of 'auto', type aliases, uniform initialization, non-static member initialization, object alignment control, scoped enumerations, override and final keywords for virtual methods, range-based for loops, explicit constructors and conversion operators, unnamed namespaces, inline namespaces, structured bindings, class template argument deduction, and subscript operator usage for accessing collection elements. Each topic serves to enhance coding routines, providing a glimpse into the broader landscape of modern C++ programming explored further in subsequent chapters.


### Chapter 02, Working with Numbers and Strings
This chapter provides practical recipes for handling fundamental data types—numbers and strings—in modern C++ programming. It covers various tasks such as conversion between numeric and string types, printing Unicode characters, generating random numbers, and utilizing user-defined literals. From exploring numeric types and their limits to formatting text with std::format, each recipe offers insights and solutions to common programming challenges, empowering developers to write efficient and robust code.


### Chapter 03, Exploring Functions
This chapter delves into the modern features and concepts related to functions and callable objects in C++. It emphasizes lambda expressions, higher-order functions, and function templates. The recipes included cover a range of topics: defaulted and deleted functions, using lambdas with standard algorithms, employing generic and template lambdas, writing recursive lambdas, creating function templates, designing function templates with a variable number of arguments, simplifying variadic function templates using fold expressions, implementing higher-order functions like map and fold, composing functions into higher-order functions, and uniformly invoking anything callable. Through these recipes, developers gain insights and strategies for leveraging modern C++ features to enhance code flexibility, readability, and efficiency, particularly in the realm of function handling.


### Chapter 04, Preprocessing and Compilation
This chapter provides a deep dive into the preprocessing and compilation phases of C++, offering insights into how source code is translated into machine-executable instructions. It emphasizes techniques for conditional compilation and touches upon modern practices like using attributes to extend language capabilities. The included recipes cover a spectrum of topics: conditionally compiling source code based on specific conditions, utilizing the indirection pattern for preprocessor string manipulation, conducting compile-time assertion checks through static_assert, conditionally compiling classes and functions using enable_if, selecting compile-time branches with constexpr if, and providing additional metadata to the compiler via attributes. Through these recipes, developers gain a deeper understanding of compile-time decisions and are equipped with strategies to optimize code correctness and performance while harnessing contemporary language features.


### Chapter 05, Standard Library Containers, Algorithms, and Iterators
The C++ standard library has undergone significant evolution with the introduction of C++11/14/17/20, and now C++23. Despite these advancements, its core remains grounded in three primary pillars: containers, algorithms, and iterators. These components are implemented as generic types and function templates, offering versatility and efficiency in various programming tasks. This chapter delves into the synergy between containers, algorithms, and iterators, showcasing how they can be combined to achieve diverse objectives. The recipes covered encompass a wide array of functionalities, from utilizing std::vector as the default container to exploring advanced topics like custom iterators and set operations on ranges. By beginning with the exploration of std::vector, the chapter sets the stage for understanding and leveraging other components of the C++ standard library effectively.


### Chapter 06, General-Purpose Utilities
This chapter explores additional utilities and libraries within the C++ standard library beyond the fundamental components discussed earlier. It focuses on three main areas: the chrono library for managing time-related operations, type traits for obtaining meta-information about types, and newer utility types introduced in recent standards. The recipes cover a wide range of functionalities, including handling time intervals, working with calendars and time zones, measuring function execution time, utilizing utility types like std::any and std::optional, and employing std::span for managing sequences of objects. Additionally, the chapter delves into advanced topics such as type traits, std::source_location for logging details, and the stacktrace library for printing call sequences. Through these recipes, developers gain valuable insights into leveraging the full power of the C++ standard library for diverse programming tasks.


### Chapter 07, Working with Files and Streams
This chapter delves into the essential aspects of the C++ standard library's input/output (I/O) stream-based functionality, enabling developers to interact with files, memory streams, and other I/O devices efficiently. The first part addresses common stream operations, including reading and writing data, localization settings, and manipulating stream input and output. The second part explores the C++17 filesystem library, facilitating filesystem operations like file and directory manipulation. Recipes in this chapter encompass a variety of tasks, such as reading/writing raw and object data from/to binary files, using streams on external buffers, employing localized settings, controlling stream output with manipulators, and utilizing filesystem functionality for creating, copying, deleting files and directories, among others. These recipes equip developers with comprehensive solutions for managing I/O operations and filesystem tasks effectively within their C++ programs.


### Chapter 08, Leveraging Threading and Concurrency
This chapter delves into maximizing computational power by leveraging multiple processors or cores, a critical aspect for various applications. Despite the prevalence of multi-core systems, many developers still primarily write sequential code, missing out on the potential for concurrent execution of independent operations. The chapter introduces standard library support for threads, asynchronous tasks, and related components, emphasizing practical examples to illustrate concepts. With modern processors typically featuring multiple cores, applications need to be explicitly designed to harness this capability by executing functions concurrently across threads. Since C++11, the standard library offers robust support for thread management, synchronization, communication, and asynchronous task execution. Key topics covered include working with threads, synchronizing access to shared data, handling exceptions, inter-thread communication, and utilizing promises and futures for asynchronous task handling. The chapter also explores techniques for parallel execution, such as using atomic types and implementing parallel map and fold operations with threads or tasks. Additionally, it addresses synchronization mechanisms like latches, barriers, and semaphores, essential for coordinating concurrent execution effectively. Through these recipes, developers gain insights into writing efficient, thread-safe code that fully harnesses the computational capabilities of modern hardware.


### Chapter 09, Robustness and Performance
This chapter focuses on essential practices and features in modern C++ programming aimed at enhancing performance, flexibility, and robustness. It highlights key language features such as rvalue references, move semantics, and smart pointers. These features, combined with best practices for exception handling, constant correctness, type-safe conversions, and resource management, enable developers to write more efficient and reliable code. The recipes in this chapter cover a range of critical topics, including exception handling, noexcept specifications, constant correctness, compile-time expressions, move semantics, and smart pointer usage. Through these recipes, developers gain insights into writing high-performance, flexible, and robust C++ code that adheres to modern programming standards and best practices.


### Chapter 10, Implementing Patterns and Idioms
This chapter explores implementing various design patterns and idioms in modern C++, focusing on enhancing readability, performance, and robustness in software development. Design patterns are general reusable solutions to common problems, while idioms are patterns or algorithms specific to one or more programming languages. Rather than reiterating existing patterns, the chapter aims to demonstrate practical implementations of several useful patterns and idioms. The recipes include techniques such as avoiding repetitive if-else statements in factory patterns, implementing the pimpl idiom, named parameter idiom, non-virtual interface idiom, attorney-client idiom for managing friendship, curiously recurring template pattern for static polymorphism, mixins for adding functionality to classes, type erasure idiom for handling unrelated types generically, and implementing a thread-safe singleton. The chapter begins by presenting a simple mechanism for avoiding repetitive if-else statements, providing insights into its implementation and usage. Through these recipes, developers gain valuable techniques for designing more efficient and maintainable C++ code.


### Chapter 11, Exploring Testing Frameworks
This chapter focuses on the crucial aspect of testing code in software development, providing an introduction to several modern and widely used testing frameworks for C++. Despite the absence of native testing support in the C++ standard library, various frameworks offer robust solutions for unit testing C++ code. The chapter covers three prominent frameworks: Boost.Test, Google Test, and Catch2. The recipes included in this chapter offer a comprehensive guide to getting started with each framework, covering topics such as writing and invoking tests, asserting conditions, utilizing test fixtures, and controlling output. These frameworks were selected for their widespread adoption, rich capabilities, ease of use, extensibility, and customization options, making them valuable tools for writing portable and effective testing code in C++. Through these recipes, developers gain practical insights into leveraging these testing frameworks to ensure the reliability and quality of their C++ codebase.


### Chapter 12, C++ 20 Core Features
This chapter explores the significant enhancements introduced in the C++20 standard, which mark a major milestone in the language's development. C++20 introduces numerous features to both the language and the standard library, including the text formatting library, calendar extensions in the chrono library, and changes to the thread support library. However, the most impactful changes affect the language itself, notably modules, concepts, coroutines, and the new ranges library. Due to the extensive nature of these features, this chapter focuses on the essential aspects and practical use cases to help readers get started with their implementation. The recipes in this chapter cover topics such as working with modules, understanding module partitions, specifying requirements on template arguments with concepts, utilizing requires expressions and clauses, exploring abbreviated function templates, and iterating over collections with the ranges library. Additionally, the chapter delves into creating coroutine task and generator types for asynchronous computations and sequences of values, as well as utilizing constrained algorithms and custom range views. The chapter commences with an exploration of modules, which represent the most disruptive change to the C++ language in decades, setting the stage for understanding and leveraging the other new features introduced in C++20.





> If you feel this book is for you, get your [copy](https://www.amazon.com/Modern-Programming-Cookbook-including-practical-ebook/dp/B0CLRSRWFL) today! <img alt="Coding" height="15" width="35"  src="https://media.tenor.com/ex_HDD_k5P8AAAAi/habbo-habbohotel.gif">





With the following software and hardware list you can run all code files present in the book.

## Software and hardware list

| Software required    | Link to the software    | Hardware specifications    | OS required    |
|:---:  |:---:  |:---:  |:---:  |
| VC++ 2022 17.7  | [https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-notes-v17.7](https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-notes-v17.7) | Should work on any recent computer | Windows or GCC 14.0 or Clang 19.0 or Linux or Mac  |


## 3rd party libraries
The following libraries are required/optional for building the code:
| Libary | Path | Purpose | Tested on version |
| ------ | ---- | ------- | ----------------- |
| Boost.Test | https://www.boost.org/ | Testing projects in chapter 11 | 1.83.0 |
| Google Test | https://github.com/google/googletest | Testing projects in chapter 11 | 1.14.0 |
| Catch2 | https://github.com/catchorg/Catch2 | Testing projects in chapter 11 | 3.5.2 |
| Range-v3 | https://github.com/ericniebler/range-v3 | Ranges examples in chapter 12 | 0.12.0 |
| libcoro | https://github.com/jbaldwin/libcoro | Ranges examples in chapter 12 | 0.10 |

## Instructions and Navigation
All of the code is organized into folders, one for each chapter. Some chapters contain one header file for each recipe in that chapter. In this cases, the header files are called _recipe_1_01.h_, _recipe_1_02.h_, etc. Other chapters, contain multiple programs, one for each recipe. In this case, in recipe has its own folder with names such as _chapter12_01_1_, _chapter12_01_2_, etc.

The code will look like the following:
```
    #include <iostream>

    int main()
    {
      std::cout << "Hello World!\n";
    }
```

The code presented in the book is available for download from your account at https://www.packtpub.com/, although I encourage you to try writing all the samples by yourself. In order to compile them, you need VC++ 2022 17.7 on Windows and GCC 14.0 or Clang 19.0 on Linux and Mac. If you don't have the latest version of the compiler, or you want to try another compiler, you can use one that is available online. Although there are various online platforms that you could use, I recommend https://wandbox.org/ or https://godbolt.org/.



## Building the code
The code can be build using CMake. The CMake files provided with the source code require CMake 3.15.0 or newer. The following values can be set:
* `SKIP_TEST_PROJECTS` Flag to prevent the generation of unit test projects (from chapter 11)
* `BOOST_PATH` Path to the installation path of Boost (required unless `SKIP_TEST_PROJECTS` is `ON`)
* `GTEST_PATH` Path to the installation path of Google Test (required unless `SKIP_TEST_PROJECTS` is `ON`)
* `GTEST_PATH_LIB` Path to the Google Test libraries directory (required unless `SKIP_TEST_PROJECTS` is `ON`)
* `CATCH_PATH` Path to the installation path of Catch2 (required unless `SKIP_TEST_PROJECTS` is `ON`)
* `RANGES_PATH` Path to the installation path of Ranges-v3 (required if `USE_RANGES_V3` is `ON`)
* `LIBCORO_PATH` Path to the installation path of libcoro (required for chapter 12)

The following example shows how to generate projects for Visual Studio 2019:

```
cmake -G "Visual Studio 16 2019" -DBOOST_PATH=d:/Work/Libraries/boost_1_83_0/ -DGTEST_PATH=d:/Work/Libraries/googletest-1.14.0/googletest/include/ -DGTEST_PATH_LIB=d:/Work/Libraries/googletest-1.14.0/lib/x64 -DLIBCORO_PATH=d:/Work/Libraries/libcoro-main -DCATCH_PATH="C:/Program Files (x86)/Catch2/include/" -S .\ -B .\build
```

Similarly, you need to do the following for Visual Studio 2022:

```
cmake -G "Visual Studio 17 2022" -A Win32 -DBOOST_PATH=d:/Work/Libraries/boost_1_83_0/ -DGTEST_PATH=d:/Work/Libraries/googletest-1.14.0/googletest/include/ -DGTEST_PATH_LIB=d:/Work/Libraries/googletest-1.14.0/lib/x64 -DLIBCORO_PATH=d:/Work/Libraries/libcoro-main -DCATCH_PATH="C:/Program Files (x86)/Catch2/include/" -S .\ -B .\build
```


## Know more on the Discord server <img alt="Coding" height="25" width="32"  src="https://cliply.co/wp-content/uploads/2021/08/372108630_DISCORD_LOGO_400.gif">
You can get more engaged on the discord server for more latest updates and discussions in the community at [Discord](https://discord.gg/7xRaTCeEhx)

## Download a free PDF <img alt="Coding" height="25" width="40" src="https://emergency.com.au/wp-content/uploads/2021/03/free.gif">
_If you have already purchased a print or Kindle version of this book, you can get a DRM-free PDF version at no cost. Simply click on the link to claim your free PDF._
[Free-Ebook](https://download.packt.com/free-ebook/9781835080542) <img alt="Coding" height="15" width="35"  src="https://media.tenor.com/ex_HDD_k5P8AAAAi/habbo-habbohotel.gif">


We also provide a PDF file that has color images of the screenshots/diagrams used in this book at [GraphicBundle](https://packt.link/gbp/9781835080542) <img alt="Coding" height="15" width="35"  src="https://media.tenor.com/ex_HDD_k5P8AAAAi/habbo-habbohotel.gif">

## Get to know the Author
_Marius Bancila_  is a software engineer with two decades of experience in developing solutions for line of business applications and more. He is the author of Template Metaprogramming with C++ and The Modern C++ Challenge. He works as a software architect and is focused on Microsoft technologies, mainly developing desktop applications with C++ and C#. He is passionate about sharing his technical expertise with others and, for that reason, he has been recognized as a Microsoft MVP for C++ and later developer technologies since 2006. Marius lives in Romania and is active in various online communities.

## Other Related Books
- [C++ High Performance: Master the art of optimizing the functioning of your C++ code - Second Edition](https://www.packtpub.com/en-in/product/c-high-performance-9781839216541)
- [The Art of Writing Efficient Programs: An advanced programmer's guide to efficient hardware utilization and compiler optimizations using C++ examples](https://www.packtpub.com/product/the-art-of-writing-efficient-programs/9781800208117)



### Suggestions and Feedback
[Click here](https://docs.google.com/forms/d/e/1FAIpQLSe5qwunkGf6PUvzPirPDtuy1Du5Rlzew23UBp2S-P3wB-GcwQ/viewform) if you have any feedback or suggestions.
