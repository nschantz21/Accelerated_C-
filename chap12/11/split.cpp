#include <vector>
#include <cctype>
#include "split.h"
#include "Str.h"


using std::vector;

std::istream& getline(std::istream& is, Str& s, const char seperator);

vector<Str> split(const Str& s){
    vector<Str> ret;
    typedef Str::size_type Str_size;
    Str_size i = 0;
    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;
            // find end of next word
            Str_size j = i;
            // invariant: none of the characters in range [original j, current j)is a space
            while (j != s.size() && !isspace(s[j]))
                j++;
                // if we found some nonwhitespace characters
                if (i != j) {
                // copy from s starting at i and taking j - i chars
                    ret.push_back(s.substr(i, j - i));
                    i = j;
            }
        }
    return ret;
}

// sort based on lowercase of first letter in a Str
bool compare(const Str& x, const Str& y)
{  
    return tolower(x[0]) < tolower(y[0]);
}

bool compare_same_first(const Str& x, const Str& y){
    return x[0] == y[0];
}

bool compare_word_size(const Str& x, const Str& y){
    return x.size() < y.size();
}