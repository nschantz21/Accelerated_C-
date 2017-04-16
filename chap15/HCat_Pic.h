#include "Pic_base.h"
#include "Ptr.h"
#include<iostream>
class Pic_base;

class HCat_Pic: public Pic_base {
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& I, const Ptr<Pic_base>& r):
        left(l), right(r) {}
    
    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};