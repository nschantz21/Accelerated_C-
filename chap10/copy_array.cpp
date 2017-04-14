#include <algorithm> // copy
#include <cstring>
using std::copy; 
/*
function that takes a pointer to the initial character of a nullterminated
character array such as a string literal, copies all the characters in the array
(including the null character at the end) into a newly allocated array, and returns a pointer to
the initial element of the new array
*/

char* duplicate_chars(const char* p){
    // allocate enough space; remember to add one for the null
    size_t length = strlen(p) +1;
    char* result = new char[length];
    
    // copy into our newly allocated space and return pointer to first element
    copy(p, p + length, result);
    return result;
}

int main(){
    return 0;
}