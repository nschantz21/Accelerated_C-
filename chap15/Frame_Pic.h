#include "Pic_base.h"
#include "Ptr.h"
#include <iostream>
class Pic_base;


class Frame_Pic: public Pic_base {
    // no public interface - "class" members are inherently private
    // may need to add friend definitions for Picture class
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic): p(pic) {} // only constructor needed
    
    // declare our intention to define class-specific versions of each of the three virtual s from that base class
    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

