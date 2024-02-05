#include <iostream>

#include <coro/task.hpp>
#include <coro/sync_wait.hpp>

coro::task<int> get_answer()
{
  co_return 42;
}

coro::task<> print_answer()
{
  auto t = co_await get_answer();
  std::cout << "the answer is " << t << '\n';
}

coro::task<int&> get_answer(int& a)
{
  std::cout << "ref answering...\n";
  a++;
  co_return a;
}

coro::task<> say_hello()
{
  std::cout << "hello, world!\n";
  co_return;
}

coro::task<> demo()
{
  std::cout << "starting...\n";
  co_await say_hello();

  std::cout << "asking...\n";
  auto t = co_await get_answer();
  std::cout << "the answer is " << t << '\n';

  int a = 42;
  std::cout << "asking...\n";
  int& b = co_await get_answer(a);
  std::cout << "the answer is " << b << '\n';
  b++;
  std::cout << "the answer is (a) " << a << '\n';
  std::cout << "the answer is (b) " << b << '\n';

  co_await print_answer();
}

int main()
{   
   coro::sync_wait(demo());
}
