#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    int list_array[1000];
    int temp=0;

    cin>>n>>t;

    for(int i=0; i<t; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>list_array[j];
        }
        for(int j=0; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(list_array[k] > list_array[j])
                {
                    temp = list_array[j];
                    list_array[j] = list_array[k];
                    list_array[k] = temp;
                }
            }
        }
        for(int j=0; j<n; j++)
        {
            cout<<list_array[j]<<' ';
        }
    }
}
