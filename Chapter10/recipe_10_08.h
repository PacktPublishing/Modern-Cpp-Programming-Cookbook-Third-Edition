#pragma once

namespace recipe_10_08
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
      struct control
      {
         template <typename T>
         control(T&& obj) :
            ctrl(std::make_shared<control_model<T>>(std::forward<T>(obj)))
         {

         }

         void draw()
         {
            ctrl->draw();
         }

         struct control_concept
         {
            virtual ~control_concept() = default;
            virtual void draw() = 0;
         };

         template <typename T>
         struct control_model : public control_concept
         {
            control_model(T& unit) : t(unit) {}

            void draw() override
            {
               t.erase_background();
               t.paint();
            }
         private:
            T& t;
         };

      private:
         std::shared_ptr<control_concept> ctrl;
      };

      void draw(std::vector<control>& controls)
      {
         for (auto& c : controls)
         {
            c.draw();
         }
      }
   }

   namespace v2
   {
      void draw_button(void* ptr)
      {
         button* b = static_cast<button*>(ptr);
         if (b)
         {
            b->erase_background();
            b->paint();
         }
      }

      void draw()
      {
         button btn;
         draw_button(&btn);

         checkbox cb;
         draw_button(&cb); // probable runtime error
                           // not in this example because there is no data that is accessed
      }
   }

   namespace v3
   {
      struct control_concept
      {
         virtual ~control_concept() = default;
         virtual void draw() = 0;
      };

      struct button_wrapper : control_concept
      {
         button_wrapper(button& b):btn(b)
         {}

         void draw() override
         {
            btn.erase_background();
            btn.paint();
         }
      private:
         button& btn;
      };

      struct checkbox_wrapper : control_concept
      {
         checkbox_wrapper(checkbox& cb) :cbox(cb)
         {}

         void draw() override
         {
            cbox.erase_background();
            cbox.paint();
         }
      private:
         checkbox& cbox;
      };

      void draw(std::vector<control_concept*> const & controls)
      {
         for (auto& c : controls)
            c->draw();
      }
   }

   namespace v4
   {
      struct control_concept
      {
         virtual ~control_concept() = default;
         virtual void draw() = 0;
      };

      template <typename T>
      struct control_wrapper : control_concept
      {
         control_wrapper(T& b) : ctrl(b)
         {}

         void draw() override
         {
            ctrl.erase_background();
            ctrl.paint();
         }
      private:
         T& ctrl;
      };

      void draw(std::vector<control_concept*> const& controls)
      {
         for (auto& c : controls)
            c->draw();
      }
   }

   namespace v5
   {
      struct control_collection
      {
         template <typename T>
         void add_control(T&& obj)            
         {
            ctrls.push_back(std::make_shared<control_model<T>>(std::forward<T>(obj)));
         }

         void draw()
         {
            for (auto& c : ctrls)
            {
               c->draw();
            }
         }

         struct control_concept
         {
            virtual ~control_concept() = default;
            virtual void draw() = 0;
         };

         template <typename T>
         struct control_model : public control_concept
         {
            control_model(T& unit) : t(unit) {}

            void draw() override
            {
               t.erase_background();
               t.paint();
            }
         private:
            T& t;
         };

      private:
         std::vector<std::shared_ptr<control_concept>> ctrls;
      };
   }

   void execute()
   {
      {
         using namespace v1;

         checkbox cb;
         button btn;

         std::vector<control> v{ control(cb), control(btn) };

         draw(v);
      }

      {
         using namespace v2;

         draw();
      }

      {
         using namespace v3;

         checkbox cb;
         button btn;

         checkbox_wrapper cbw(cb);
         button_wrapper btnw(btn);

         std::vector<control_concept*> v{ &cbw, &btnw };

         draw(v);
      }

      {
         using namespace v4;

         checkbox cb;
         button btn;

         control_wrapper<checkbox> cbw(cb);
         control_wrapper<button> btnw(btn);

         std::vector<control_concept*> v{ &cbw, &btnw };

         draw(v);
      }

      {
         using namespace v5;

         checkbox cb;
         button btn;

         control_collection cc;
         cc.add_control(cb);
         cc.add_control(btn);

         cc.draw();
      }
   }
}