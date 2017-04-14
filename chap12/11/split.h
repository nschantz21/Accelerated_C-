#ifndef GUARD_split_h
#define GUARD_split_h
// split.h
#include<vector>
#include "Str.h"

std::vector<Str> split(const Str&);
bool compare(const Str&, const Str&);
bool compare_same_first(const Str&, const Str&);
bool compare_word_size(const Str&, const Str&);
std::istream& getline(std::istream& is, Str& s, const char seperator);


#endif