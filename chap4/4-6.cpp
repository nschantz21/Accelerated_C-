//Rewrite the Student_info structure to calculate the grades immediately and store only the
//final grade.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double grade(const double& y, const double& z){
    int final2 = (y + z) / 2;;
    
    return final2;
}


struct Student_info2 {
    std::string name;
    double grade;
} Nick ; // note the semicolon it's required



int main(){

    Student_info2 Nick;
    cout<<"enter the name"<<endl;
    getline(cin,Nick.name);
    cout<<"give the midterm and final:"<<endl;
    
    double midterm;
    double final;
    cin>>midterm;cin>>final;
    
    double g = grade(midterm, final);
    
    Nick.grade = g;
    
    cout<<endl;
    
    cout<<Nick.name<<"\t"<<Nick.grade<<endl;
    cout.flush();
    
    return 0;
}