#include <vector>
#include <string>
#include <iostream>
#include "Pic.h"

using std::vector; using std::string;
using std::endl; using std::cin; using std::cout;

int median_test(int x){
    if (x == 0){
        return 0;
    } else
    return x % 2 == 0 ? x / 2 : (x - 1) / 2 + 1;
}

int main() {
    vector<string> my_vec;
    while(cin){
        string st;
        getline(cin, st);
        my_vec.push_back(st);
    }
    
    Picture p(my_vec);
    Picture q = frame(p);
    Picture r = hcat(p, q) ;
    Picture s = vcat(q, r);
    // Picture my_frame = frame(my_pic);
    Picture x = frame(hcat(s, vcat(r, q)));
    cout << hcat(vcat(q,q),q) << endl;
    cout << hcat(q, vcat(q,q)) << endl;
    /*
    x.reframe('L', '!', '+');
    cout << x;
    
    cout << hcat(p, p);
    
    for(int m = 0; m < 100; ++m)
        cout<< median_test(m)<< "\n";
    */
    int my_int = 5 / 2;
    cout<< my_int << "\n";
    return 0;
}