#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    long long int t,n = 2;
    long long int ans=0;
    scanf("%lld", &t);
    while(3*(n-1) < t)n *= 2;
    ans=3*(n-1)-t+1;
    printf("%lld\n", ans);
    return 0;
}

