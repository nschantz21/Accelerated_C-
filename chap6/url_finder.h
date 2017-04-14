#ifndef GUARD_url_finder_h
#define GUARD_url_finder_h
// url_finder.h
#include <vector>
#include <string>

bool not_url_char(char c);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif