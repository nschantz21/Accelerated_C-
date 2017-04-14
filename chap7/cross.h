#ifndef GUARD_cross_h
#define GUARD_cross_h

// gen_sent.h
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "split.h"


// you put default values in the declaration not the definitions
// meaning you put it in the header, not the related .cpp file
std::map<std::string, std::vector<int> > xref(std::istream&, std::vector<std::string> find_words(const std::string&) = split);


#endif