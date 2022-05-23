/* Inkluderingsdirektiv: */
#include "header.hpp"

/*****************************************************************************************
* Ansluter tre lysdioder till PIN 17, 22 och 23 samt en tryckknapp till PIN 27.
* Lysdioderna lagras i en statisk array f�r att kunna blinka i en sekvens med valbar
* riktning och f�rdr�jningstid. Ifall tryckknappen trycks ned, s� blinkar lysdioderna
* bakl�nges med en blinkhastighet p� 50 milliseknder. Annars blinkar lysdioderna
* framl�nges med en blinkhastighet p� 200 millisekunder.
******************************************************************************************/
int main(void)
{
   gpiod_line* led1 = gpiod_line_new(17, gpio_direction::output);
   gpiod_line* led2 = gpiod_line_new(22, gpio_direction::output);
   gpiod_line* led3 = gpiod_line_new(23, gpio_direction::output);
   gpiod_line* button1 = gpiod_line_new(27);

   auto leds = array_new<gpiod_line*>();
   leds->push(leds, led1);
   leds->push(leds, led2);
   leds->push(leds, led3);

   for (;;)
   {
      if (gpiod_line_get_value(button1))
         gpiod_lines_blink(leds, 50, blink_direction::backwards);
      else
         gpiod_lines_blink(leds, 200);
   }

   return 0;
}