#ifndef ARRAY_T_HPP_
#define ARRAY_T_HPP_

/* Inkluderingsdirektiv: */
#include "array.hpp"

/* Statiska funktioner: */
template<class T> static void array_push(struct array<T>* self, const T& new_element);
template<class T> static void array_clear(struct array<T>* self);

/*****************************************************************************************
* Konstruktor, returnerar initierad arraypekare.
******************************************************************************************/
template<class T> 
array<T>* array_new(void)
{
   array<T>* self = new array<T>;
   if (!self) return 0;
   self->size = 0;
   self->push = array_push;
   self->clear = array_clear;
   array_clear(self);
   return self;
}

/*****************************************************************************************
* Destruktor, frigör allokerat minne.
******************************************************************************************/
template<class T> 
void array_delete(array<T>* self) { delete(self); }

/*****************************************************************************************
* Lägger till ett element längst bak i en array, förutsatt att denna inte är full.
******************************************************************************************/
template<class T>
static void array_push(array<T>* self, const T& new_element)
{
   if (self->size < self->CAPACITY)
      self->data[self->size++] = new_element;
   return;
}

/*****************************************************************************************
* Nollställer innehållet i en array.
******************************************************************************************/
template<class T>
static void array_clear(array<T>* self)
{
   for (auto i = self->data; i < self->data + self->CAPACITY; i++)
      *i = static_cast<T>(0);
   self->size = 0;
   return;
}

#endif /* ARRAY_T_HPP_ */