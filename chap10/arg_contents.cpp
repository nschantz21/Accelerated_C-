#include <string> // string 
#include <fstream> // ifstream
#include <iostream> // cout, endl, cerr

using std::string; using std::ifstream;
using std::cout; using std::endl; using std::cerr;


// produces, on its standard output, a copy of the
// contents of all the files whose names are given as arguments to main

int main(int argc, char**argv){
    int fail_count = 0;
    // for each file in the input list
    for (int i = 1; i < argc; ++i){
        ifstream in(argv[i]);
        
        // if it exists, wirte its contents, otherwise generate an error message
        if(in){
            string s;
            while (getline(in, s))
                cout << s << endl;
        } else {
            cerr << "cannot open file " << argv[i] << endl; // use cerr to write an urgent complaint
            ++fail_count;
        }
    }
    return fail_count;
}