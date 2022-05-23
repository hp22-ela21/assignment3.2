/* Inkluderingsdirektiv: */
#include "header.hpp"

/* Statiska funktioner: */
static void delay(const std::size_t delay_time);

/*****************************************************************************************
* Konstruktor, initierar ny GPIO-linje till in- eller utport.
******************************************************************************************/
gpiod_line* gpiod_line_new(const std::uint8_t pin, const gpio_direction direction)
{
   static gpiod_chip* chip0 = gpiod_chip_open("/dev/gpiochip0");
   gpiod_line* self = gpiod_chip_get_line(chip0, pin);
   if (direction == gpio_direction::output)
      gpiod_line_request_output(self, "", 0);
   else
      gpiod_line_request_input(self, "");
   return self;
}

/*****************************************************************************************
* Destruktor, tar bort reservation från aktuell GPIO-linje.
******************************************************************************************/
void gpiod_line_delete(gpiod_line* self) { gpiod_line_release(self); }

/*****************************************************************************************
* Blinkar GPIO-linjer i en sekvens med valbar fördröjningstid och riktning.
******************************************************************************************/
void gpiod_lines_blink(array<gpiod_line*>* lines, const std::size_t delay_time, 
   const blink_direction direction)
{
   if (direction == blink_direction::forwards)
   {
      for (auto i : *lines)
      {
         gpiod_line_set_value(i, 1);
         delay(delay_time);
         gpiod_line_set_value(i, 0);
      }
   }

   else
   {
      for (auto i = lines->end() - 1; ; --i)
      {
         gpiod_line_set_value(*i, 1);
         delay(delay_time);
         gpiod_line_set_value(*i, 0);
         if (i == lines->begin()) break;
      }
   }

   return;
}

/*****************************************************************************************
* Genererar fördröjning via uppräkning, dock ej optimal precision.
******************************************************************************************/
static void delay(const std::size_t delay_time)
{
   static constexpr std::size_t DELAY_CONSTANT = 232000;
   for (volatile std::size_t i = 0; i < delay_time; i++)
      for (volatile std::size_t j = 0; j < DELAY_CONSTANT; j++);
   return;
}
