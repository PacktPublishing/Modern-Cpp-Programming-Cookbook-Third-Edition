#include <iostream>
#include <atomic>

#include <coroutine>

template <typename T>
struct task;

namespace details
{
   struct promise_base
   {
      auto initial_suspend() noexcept { return std::suspend_always{}; }
      auto final_suspend() noexcept   { return std::suspend_always{}; }
      void unhandled_exception()      { std::terminate(); }
   };

   template <typename T>
   struct promise final : public promise_base
   {
      task<T> get_return_object() noexcept;

      template<typename V,
               typename = std::enable_if_t<std::is_convertible_v<V&&, T>>>
      void return_value(V&& value) noexcept(std::is_nothrow_constructible_v<T, V&&>)
      {
         value_ = value;
      }

      T get_value() const noexcept { return value_; }
   private:
      T value_;
   };

   template <>
   struct promise<void> final : public promise_base
   {
      task<void> get_return_object() noexcept;

      void return_void() noexcept {}
   };

   template <typename T>
   struct promise<T&> final : public promise_base
   {
      task<T&> get_return_object() noexcept;

      void return_value(T& value) noexcept
      {
         value_ = std::addressof(value);
      }

      T& get_value() const noexcept { return *value_; }

   private:
      T* value_ = nullptr;
   };
}

template <typename T = void>
struct task
{
   using promise_type = details::promise<T>;

   struct task_awaiter
   {
      task_awaiter(std::coroutine_handle<promise_type> coroutine) noexcept
         : handle_(coroutine)
      {}

      bool await_ready() const noexcept
      {
         return !handle_ || handle_.done();
      }

      void await_suspend([[maybe_unused]] std::coroutine_handle<> continuation) noexcept
      {
         handle_.resume();
      }

      decltype(auto) await_resume()
      {
         if (!handle_)
            throw std::runtime_error{ "broken promise" };

         return handle_.promise().get_value();
      }

      friend struct task<T>;
   private:
      std::coroutine_handle<promise_type> handle_;
   };

   explicit task(std::coroutine_handle<promise_type> handle) 
      : handle_(handle) 
   {
   }

   ~task()
   {
      if (handle_) handle_.destroy();
   }

   task(task&& t) noexcept
      : handle_(t.handle_)
   {
      t.handle_ = nullptr;
   }

   task& operator=(task&& other) noexcept
   {
      if (std::addressof(other) != this)
      {
         if (handle_) handle_.destroy();

         handle_ = other.handle_;
         other.handle_ = nullptr;
      }

      return *this;
   }

   task(task const &) = delete;
   task& operator=(task const &) = delete;

   T value() const noexcept   { return handle_.promise().get_value(); }
   void resume() noexcept     { handle_.resume(); }
   bool is_ready() const noexcept   { return !handle_ || handle_.done(); }

   auto operator co_await() const& noexcept
   {
      return task_awaiter{ handle_ };
   }
   
private:
   std::coroutine_handle<promise_type> handle_ = nullptr;
};

namespace details
{
   template <typename T>
   task<T> promise<T>::get_return_object() noexcept
   {
      return task<T>{std::coroutine_handle<promise<T>>::from_promise(*this)};
   }

   task<void> promise<void>::get_return_object() noexcept
   {
      return task<void>{std::coroutine_handle<promise<void>>::from_promise(*this)};
   }

   template <typename T>
   task<T&> promise<T&>::get_return_object() noexcept
   {
      return task<T&>{std::coroutine_handle<promise<T&>>::from_promise(*this)};
   }
}

task<int> get_answer()
{
   co_return 42;
}

task<> print_answer()
{
   auto t = co_await get_answer();
   std::cout << "the answer is " << t << '\n';
}

task<int&> get_answer(int& a)
{
   std::cout << "ref answering...\n";
   a++;
   co_return a;
}

task<> say_hello()
{
   std::cout << "hello, world!\n";
   co_return;
}

template <typename T>
void execute(T&& t)
{
   while (!t.is_ready()) t.resume(); 
};

int main()
{
   {
      std::cout << "starting...\n";
      execute(say_hello());
   }

   {
      std::cout << "asking...\n";
      auto t = get_answer();
      execute(t);
      std::cout << "the answer is " << t.value() << '\n';
   }

   {
      int a = 42;
      std::cout << "asking...\n";
      auto t = get_answer(a);
      execute(t);
      int& b = t.value();
      std::cout << "the answer is " << b << '\n';
      b++;
      std::cout << "the answer is (a) " << a << '\n';
      std::cout << "the answer is (b) " << b << '\n';
   }

   {
      auto t = print_answer();
      execute(t);
   }
}