#ifndef GUARD_frame_h
#define GUARD_frame_h
// split.h
#include<vector>
#include "Str.h"
Str::size_type width(const std::vector<Str>&);
std::vector<Str> frame(const std::vector<Str>&);
std::vector<Str> vcat(const std::vector<Str>& , const std::vector<Str>&);
std::vector<Str> hcat(const std::vector<Str>&, const std::vector<Str>&);


#endif