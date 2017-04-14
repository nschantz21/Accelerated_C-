#ifndef GUARD_split_h
#define GUARD_split_h
// split.h
#include "Vec.h"
#include<string>

Vec<std::string> split(const std::string&);
bool compare(const std::string&, const std::string&);
bool compare_same_first(const std::string&, const std::string&);
bool compare_word_size(const std::string&, const std::string&);


#endif