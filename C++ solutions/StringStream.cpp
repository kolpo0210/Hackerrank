#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int length_s;
    
    cin >> s;
    length_s = s.length();
    
    for(int i=0; i<length_s; i++){
        if(s[i] != ','){
            cout<<s[i];
        }
        else {
            cout<<"\n";
        }
    }
    
    return 0;
}
