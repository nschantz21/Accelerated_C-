#include<iostream>
#include<vector>
#include<string>

class Pic_base {
    // no public interface - all interface through derived classes or Picture
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;
    
    // this class is an abstract base class
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
}; // don't forget this dumb semi-colon