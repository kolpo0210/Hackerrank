#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   long long int a[5],i,max=-1,min=100000000000,sum=0;
    for(i=0;i<5;i++){
        scanf("%lld",&a[i]);
        sum = sum + a[i];
        if(a[i]<min){
            min = a[i];
        }
        if(a[i]>max){
            max = a[i];
        }
    }
    printf("%lld %lld",sum-max,sum-min);
    return 0;
}
