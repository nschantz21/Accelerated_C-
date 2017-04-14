#include <fstream>
#include <string>
using std::string; using std::ifstream;
using std::ofstream; using std::endl;

// copies a file named in to a file named out:

int main(){
    ifstream infile("main2.cpp");
    ofstream outfile("out.txt");
    
    string s;
    
    while (getline(infile, s))
        outfile << s << endl;
    return 0;
}