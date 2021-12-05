#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int pump=0;
    int tank=0;
    for(int i=0; i<n; i++)
    {
        int l,kl;
        cin>>l>>kl;
        tank+=l-kl;
        if(tank<0)
        {
            pump=i+1;
            tank=0;
        }
    }
    cout<<pump;
    return 0;
}
