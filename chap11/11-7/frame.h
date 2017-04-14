#ifndef GUARD_frame_h
#define GUARD_frame_h
// frame.h
#include"Vec.h"
#include<string>
std::string::size_type width(const Vec<std::string>&);
Vec<std::string> frame(const Vec<std::string>&);
Vec<std::string> vcat(const Vec<std::string>& , const Vec<std::string>&);
Vec<std::string> hcat(const Vec<std::string>&, const Vec<std::string>&);


#endif