#ifndef GUARD_frame_h
#define GUARD_frame_h
// split.h
#include "Vec.h"
#include "Str.h"
Str::size_type width(const Vec<Str>&);
Vec<Str> frame(const Vec<Str>&);
Vec<Str> vcat(const Vec<Str>& , const Vec<Str>&);
Vec<Str> hcat(const Vec<Str>&, const Vec<Str>&);


#endif