#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int a[3],p=0,q=0;
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int b[3];
    scanf("%d %d %d",&b[0],&b[1],&b[2]);
    for(int i=0;i<3;i++)
        {
        if(a[i]>b[i])
            p++;
        else if(b[i]>a[i])
            q++;
    }
    printf("%d %d",p,q);
    return 0;
}
