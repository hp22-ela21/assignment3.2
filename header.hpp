#ifndef HEADER_HPP_
#define HEADER_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include "gpiod.h"
#include "array.hpp"

/* Enumerationsklasser: */
enum class gpio_direction { input, output };
enum class blink_direction { forwards, backwards };

/* Externa funktioner: */
gpiod_line* gpiod_line_new(const std::uint8_t pin, 
   const gpio_direction direction = gpio_direction::input);
void gpiod_line_delete(gpiod_line* self);
void gpiod_lines_blink(array<gpiod_line*>* lines, const std::size_t delay_time,
   const blink_direction direction = blink_direction::forwards);

#endif /* HEADER_HPP_ */