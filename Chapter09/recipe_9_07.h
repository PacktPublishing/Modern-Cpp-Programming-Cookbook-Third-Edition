#pragma once

#include <cassert>

namespace recipe_9_07
{
   namespace v1
   {
      struct dimension
      {
         double width;
         double height;
      };

      struct document_type
      {
         virtual ~document_type() {};
         virtual dimension size() const = 0;
      };

      struct document_legal : document_type
      {
         dimension size() const override { return { 215.9, 355.6 }; }
      };

      struct document_letter : document_type
      {
         dimension size() const override { return { 215.9, 279.4 }; }
      };

      struct document_half_letter : document_type
      {
         dimension size() const override { return { 139.7, 215.9 }; }
      };

      struct document_a4 : document_type
      {
         dimension size() const override { return { 210, 297 }; }
      };

      struct document_a5 : document_type
      {
         dimension size() const override { return { 148.5, 210 }; }
      };

      struct envelope_type
      {
         virtual ~envelope_type(){}
         virtual dimension size() const = 0;
         virtual dimension max_enclosure_size() const = 0;
      };

      struct envelop_commercial_8 : envelope_type
      {
         dimension size() const override { return { 219, 92 }; }
         dimension max_enclosure_size() const override { return { 213, 86 }; }
      };

      struct envelop_commercial_9 : envelope_type
      {
         dimension size() const override { return { 225, 98 }; }
         dimension max_enclosure_size() const override { return { 219, 92 }; }
      };

      struct envelop_booklet_6_9 : envelope_type
      {
         dimension size() const override { return { 229, 152 }; }
         dimension max_enclosure_size() const override { return { 222, 146 }; }
      };

      bool document_fits_envelope(document_type const& d, envelope_type const& e)
      {
         return e.max_enclosure_size().width >= d.size().width;
      }
   }

   namespace v2
   {
      struct dimension
      {
         double width;
         double height;
      };

      struct document_type
      {
         constexpr virtual ~document_type() {};
         constexpr virtual dimension size() const = 0;
      };

      struct document_legal : document_type
      {
         constexpr dimension size() const override { return { 215.9, 355.6 }; }
      };

      struct document_letter : document_type
      {
         constexpr dimension size() const override { return { 215.9, 279.4 }; }
      };

      struct document_half_letter : document_type
      {
         constexpr dimension size() const override { return { 139.7, 215.9 }; }
      };

      struct document_a4 : document_type
      {
         constexpr dimension size() const override { return { 210, 297 }; }
      };

      struct document_a5 : document_type
      {
         constexpr dimension size() const override { return { 148.5, 210 }; }
      };

      struct envelope_type
      {
         constexpr virtual ~envelope_type() {}
         constexpr virtual dimension size() const = 0;
         constexpr virtual dimension max_enclosure_size() const = 0;
      };

      struct envelop_commercial_8 : envelope_type
      {
         constexpr dimension size() const override { return { 219, 92 }; }
         constexpr dimension max_enclosure_size() const override { return { 213, 86 }; }
      };

      struct envelop_commercial_9 : envelope_type
      {
         constexpr dimension size() const override { return { 225, 98 }; }
         constexpr dimension max_enclosure_size() const override { return { 219, 92 }; }
      };

      struct envelop_booklet_6_9 : envelope_type
      {
         constexpr dimension size() const override { return { 229, 152 }; }
         constexpr dimension max_enclosure_size() const override { return { 222, 146 }; }
      };

      constexpr bool document_fits_envelope(document_type const& d, envelope_type const& e)
      {
         return e.max_enclosure_size().width >= d.size().width;
      }
   }

   void execute()
   {
      {
         using namespace v1;
         envelop_commercial_8 e1;

         document_a5 d1;
         document_legal d2;
         assert(document_fits_envelope(d1, e1));
         assert(!document_fits_envelope(d2, e1));
      }

      {
         using namespace v2;
         constexpr envelop_commercial_8 e1;

         constexpr document_a5 d1;
         constexpr document_legal d2;
         static_assert(document_fits_envelope(d1, e1));
         static_assert(!document_fits_envelope(d2, e1));
      }
   }
}