#ifndef ARRAY_HPP_
#define ARRAY_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>

/*****************************************************************************************
* Strukt-template för lagring av data i en statisk array, som rymmer 100 element.
******************************************************************************************/
template<class T>
struct array
{
   static const std::size_t CAPACITY = 100; /* Arrayens kapacitet. */
   T data[CAPACITY]; /* Statisk array. */
   std::size_t size = 0x00; /* Antalet befintliga element. */
   void (*push)(array* self, const T& new_element); /* Lägger till nytt element. */
   void (*clear)(array* self); /* Nollställer arrayen. */
   T* begin(void) { return this->data; }
   T* end(void) { return this->data + this->size; }
};

// Externa funktioner:
template<class T> array<T>* array_new(void); /* Konstruktor. */
template<class T> void array_delete(array<T>* self); /* Destruktor. */

/* Inkluderar implementeringsfil innehållande funktionstemplates: */
#include "array_t.hpp"

#endif /* ARRAY_HPP_ */