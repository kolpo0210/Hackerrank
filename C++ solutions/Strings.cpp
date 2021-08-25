#include <iostream>
#include <string>
using namespace std;

int main() {
    int temp;
	string first;
    string second;
    string third;
    
    cin>>first;
    cin>>second;
    
    cout<<first.length()<< " ";
    cout<<second.length()<<"\n";
    
    third=first+second;
    cout<<third<<"\n";
    
    temp=first[0];
    first[0]=second[0];
    second[0]=temp;
    
    cout<<first<<" ";
    cout<<second;
    
    return 0;
}
