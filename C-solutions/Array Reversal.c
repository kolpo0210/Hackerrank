#include <stdio.h>
int main()
{
    int n, i;
    int arr[1000];
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i=n-1; i>=0; i--) {
        printf("%d", arr[i]);
        printf(" ");
    }
    
    return 0;
}
