#include <iostream>
using namespace std;
void update(int *a,int *b) {
if(*a>*b){
    *b = *a-*b;
    *a = *a -*b +*a;
}
else {
    *b = *b-*a;
    *a = *a + *b + *a;
}
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    cin>>a>>b;
    update(pa, pb);
    cout<<a<<"\n"<<b;

    return 0;
}
