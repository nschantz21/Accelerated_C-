#include <cctype>
#include <iostream>
#include <iterator>
#include "Str.h"

Str operator+(const Str& s, const Str& t){
    // we copy the left Str using the synthesized copy constructor
    Str r = s;
    // use the member function, concat/assignment operator
    r+= t;
    return r;
}

// input operator
std::istream& operator>>(std::istream& is, Str& s){
    // obliterator existing value(s)
    s.data->clear();
    
    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ; // nothing to do, except testing the condition
        
    // if still something to read, do so wuntil next whitespace character
    if(is){
        do s.data->push_back(c);
        while(is.get(c) && !isspace(c));
        
        // get rid of trailing whitespace
        // if we read whitespace, then put it back on the stream
        if(is)
            is.unget();
    }
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s){
    std::ostream_iterator<char> out_it(os);
    std::copy(s.begin(), s.end(), out_it);
    return os;
}

std::istream& getline(std::istream&is, Str& s) {
  s.data->clear();

  char c;
  while (is.get(c) && isspace(c));

  if (is) {
    do s.data->push_back(c);
    while (is.get(c) && c != '\n');
    if (is) is.unget();
  }

  return is;
}

