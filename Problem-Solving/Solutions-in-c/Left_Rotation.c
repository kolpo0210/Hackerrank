#include<stdio.h>
#define MAX 100000

int main(void)
{
    int a[MAX], i, n, d;

    scanf("%d%d", &n, &d);

    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    for(i=0;i<n;i++)
        printf("%d ", a[(i+d)%n]);
    // Circular logical technique used in queues has been used here to print the numbers

    return 0;
}
