#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_nth_term(int n, int a, int b, int c) {
    int i, s=0, p=0;
    for(i=1; i<n-1; i++){
        s+=i;
    }
    p=s+b+c;
    return p;
}

int main() {
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans); 
    return 0;
}
