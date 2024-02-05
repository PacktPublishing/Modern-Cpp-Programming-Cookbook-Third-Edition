#pragma once

namespace recipe_10_07
{
   class button
   {
   public:
      void erase_background()
      {
         std::cout << "erasing button background..." << '\n';
      }

      void paint()
      {
         std::cout << "painting button..." << '\n';
      }
   };

   class checkbox
   {
   public:
      void erase_background()
      {
         std::cout << "erasing checkbox background..." << '\n';
      }

      void paint()
      {
         std::cout << "painting checkbox..." << '\n';
      }
   };

   namespace v1
   {
      template <typename T>
      class control : public T
      {
      public:
         void draw()
         {
            T::erase_background();
            T::paint();
         }
      };
   }

   namespace v2
   {
      class control_base
      {
      public:
         virtual ~control_base() {}
         virtual void draw() = 0;
      };

      template <typename T>
      class control : public control_base, public T
      {
      public:
         void draw() override
         {
            T::erase_background();
            T::paint();
         }
      };

      void draw_all(std::vector<control_base*> const & controls)
      {
         for (auto& c : controls)
         {
            c->draw();
         }
      }
   }

   void execute()
   {
      {
         using namespace v1;

         control<button> b;
         b.draw();

         control<checkbox> c;
         c.draw();
      }

      {
         using namespace v2;

         std::vector<control_base*> controls;

         control<button> b;
         control<checkbox> c;

         draw_all({&b, &c});
      }
   }
}