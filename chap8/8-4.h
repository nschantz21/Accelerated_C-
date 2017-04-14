#ifndef GUARD_8_4_h
#define GUARD_8_4_h

#include <iterator>

template <class Type>
void my_swap(Type& a, Type& b) {
  Type c = a;
  a = b;
  b = c;
}



#endif