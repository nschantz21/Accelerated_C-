#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterat
using std::string; using std::cout;
using std:: cin; using std::ostream_iterator;

bool space(char c)
{
    return isspace(c);
}
bool not_space(char c)
{
    return !space(c);
}
template <class Out>    // changed
void split(const string& str, Out os){
    
    typedef string::const_iterator iter;
    
    iter i = str.begin();
    while(i != str.end()){
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        
        // find end of next word
        iter j = find_if(i, str.end(), space);
        
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = string(i, j); // changed
            
        i = j;
    }
}

int main(){
    string s;
    while (getline(cin, s))
        split(s, ostream_iterator<string>(cout, "\n"));
    return 0;
}