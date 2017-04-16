
#include "Pic_base.h"
#include "Ptr.h"
class Pic_base;

class VCat_Pic: public Pic_base {
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) {}
    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};