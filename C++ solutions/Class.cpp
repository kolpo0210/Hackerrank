#include <iostream>
#include <sstream>
using namespace std;
int main(){
    int n, t;
    string first_name;
    string last_name;
    
    cin >> n >> first_name >> last_name >> t;
    
    cout << n << "\n" << last_name << ", " << first_name << "\n" << t << "\n"<< "\n";
    cout << n << "," << first_name << "," << last_name << "," << t;
    
    return 0;
}
