#ifndef GUARD_frame_h
#define GUARD_frame_h
// split.h
#include<vector>
#include<string>
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>& , const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);


#endif