#pragma once

#include <vector>
#include <deque>
#include <list>
#include <iostream>

namespace recipe_5_12
{
   void execute()
   {
      {
         std::vector<int> v{ 1,1,2,3,5,8 };
         v.push_back(13);
      }

      {
         std::vector<int> v{ 1,1,2,3,5,8 };
         v.insert(v.begin() + 3, 13);
      }

      {
         std::deque<int> d{ 1,2,3,5,8 };
         d.push_front(1);
         d.push_back(13);
      }

      {
         std::list<int> l{ 1, 1, 2, 3, 5, 8 };
         auto it = std::find(l.begin(), l.end(), 3);         
         l.insert(it, 13);
      }
   }
}