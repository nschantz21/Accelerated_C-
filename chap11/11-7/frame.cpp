#include <algorithm>
#include <string>
#include "Vec.h"

#include "frame.h"

using std::string;


#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

string::size_type width(const Vec<string>& v) {
  string::size_type maxlen = 0;
#ifdef _MSC_VER
  for(Vec<string>::size_type i = 0; i != v.size(); ++i)
#else
    for(Vec<string>::size_type i = 0; i != v.size(); ++i)
#endif
      maxlen = max(maxlen, v[i].size());

  return maxlen;
}

Vec<string> frame(const Vec<string>& v) {
  Vec<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  // write the top border
  ret.push_back(border);

  // write each interior row, bordered by an asterisk and a space
#ifdef _MSC_VER
  for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
#else
    for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
#endif
      ret.push_back("* " + v[i] +
		    string(maxlen - v[i].size(), ' ') + " *");
    }

    // write the bottom border
    ret.push_back(border);

    return ret;
  }

  Vec<string> vcat(const Vec<string>& top,
		      const Vec<string>& bottom) {
    // copy the `top' picture
    Vec<string> ret = top;

    // copy entire `bottom' picture
#ifdef _MSC_VER
    for (Vec<string>::const_iterator it = bottom.begin();
#else
	 for (Vec<string>::const_iterator it = bottom.begin();
#endif
	      it != bottom.end(); ++it)
	   ret.push_back(*it);

	 return ret;
	 }

    Vec<string>
      hcat(const Vec<string>& left, const Vec<string>& right) {
      Vec<string> ret;

      // add 1 to leave a space between pictures
      string::size_type width1 = width(left) + 1;

      // indices to look at elements from `left' and `right' respectively
#ifdef _MSC_VER
      Vec<string>::size_type i = 0, j = 0;
#else
      Vec<string>::size_type i = 0, j = 0;
#endif

      // continue until we've seen all rows from both pictures
      while (i != left.size() || j != right.size()) {
	// construct new `string' to hold characters from both pictures
	string s;

	// copy a row from the left-hand side, if there is one
	if (i != left.size())
	  s = left[i++];

	// pad to full width
	s += string(width1 - s.size(), ' ');

	// copy a row from the right-hand side, if there is one
	if (j != right.size())
	  s += right[j++];

	// add `s' to the picture we're creating
	ret.push_back(s);
      }

      return ret;
    }