#ifndef GUARD_Pic_h
#define GUARD_Pic_h
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include "Ptr.h"

/*
The Pic_base class
*/
// forward declaration
class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;
    friend class Picture;
    // no public interface - all interface through derived classes or Picture
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;
    
    // this class is an abstract base class
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
    virtual void reframe(char, char, char) = 0;
    
    protected:
        // static so not associated with the object
        static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
            while(beg!= end){
                os << " ";
                ++beg;
            }
        }
}; // don't forget this dumb semi-colon

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture reframe(const Picture&, char, char);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);
    
    public:
        Picture(const std::vector<std::string>& = std::vector<std::string>());
        void reframe(char c, char t_b, char s) { p->reframe(c, t_b, s); }
    private:
        Picture(Pic_base* ptr): p(ptr) {}
        Ptr<Pic_base> p;
};

// output operator for Picture class
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


class String_Pic: public Pic_base {
    friend class Picture;
    std::vector<std::string> data; // copy of user's string
    String_Pic(const std::vector<std::string>& v): data(v) {}
    
    wd_sz width() const;
    ht_sz height() const {return data.size();}
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char, char, char) {}
};


class VCat_Pic: public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) {}
    // implemented inline
    wd_sz width() const {
        return std::max(top->width(), bottom->width());
    }
    ht_sz height() const {
        return top->height() + bottom->height();
    }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char, char, char);
};


class HCat_Pic: public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):
        left(l), right(r) {}
    
    wd_sz width() const{
        return left->width() + right->width();
    }
    
    
    
    ht_sz height() const {
        return std::max(left->height(), right->height());
    }
    
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char, char, char);
};


class Frame_Pic: public Pic_base {
    friend Picture frame(const Picture&);
    
    // no public interface - "class" members are inherently private
    // may need to add friend definitions for Picture class
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic): p(pic), top_bottom('-'), side('|'), corner('*') {} // only constructor needed
    explicit Frame_Pic(const Ptr<Pic_base>& pic, char c, char t_b, char s): p(pic) { top_bottom = t_b; side = s; corner = c;}
    
    char top_bottom;
    char side;
    char corner;
    
    // declare our intention to define class-specific versions of each of the three virtual s from that base class
    wd_sz width() const {
        return p->width() + 4;
    }
    
    ht_sz height() const{
        return p->height() + 4;
    }
    
    void display(std::ostream& os, ht_sz, bool) const;
    void reframe(char, char, char);
};



#endif