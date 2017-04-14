#include "url_finder.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main(){
    
    
    std::clock_t start;
    start = std::clock();
    std::ifstream file;
    
    file.open("websheet.txt");
    string x;
    while(getline(file, x)){
        vector<string> urls = find_urls(x);
    
        vector<string>::iterator i = urls.begin();
        while(i != urls.end()){
            cout << *i << endl;
            ++i;
        }
    }
    
    return 0;
}