// Exercise 3-5

/*
    Write a program that will keep track of grades for several students at once. The program
    could keep two vectors in sync: The first should hold the student's names, and the second the
    final grades that can be computed as input is read. For now, you should assume a fixed
    number of homework grades. We'll see in §4.1.3/56 how to handle a variable number of
    grades intermixed with student names.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<string> names;
    vector<int> grades;
    
    string name;
    int grade;    
    int assignments = 3;
    
    
    cout<<"Who are your students? "<<endl;
    
    while (cin >> name && name!="end"){
        names.push_back(name);   
    }
    
    typedef vector<int>::size_type vec_sz;
    typedef vector<int>::iterator vec_it;
    vec_sz size = names.size();
    
    for(int i = 0; i < size; i++){
        cout<<"What are "<<names[i]<<"'s grades?"<<endl;
        int count = 0;
        int x = 0;
        int sum = 0;
        while(count<assignments){
            ++count;
            cin>>x;
            sum += x;
        }
        
        grades.push_back((sum/count));
    }
    
    for(int y = 0; y < size; y++)
        cout<<names[y]<<" "<<grades[y]<<endl;
    
    return 0;
// it works!
}