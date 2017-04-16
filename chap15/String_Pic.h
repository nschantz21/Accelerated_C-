
#include "Pic_base.h"

class Pic_base;

class String_Pic: public Pic_base {
    std::vector<std::string> data; // copy of user's string
    String_Pic(const std::vector<std::string>& v): data(v) {}
    
    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};