#include <stdio.h>
int main()
{
	int n=0, m=0, sum_int=0, dif_int=0;
    float s=0, d=0, sum_float=0, dif_float=0;
    
    scanf("%d %d", &n, &m);
    scanf("%f %f", &s, &d);
    
    sum_int=(n+m);
    dif_int=(n-m);
    sum_float=(s+d);
    dif_float=(s-d);
    
    printf("%d %d\n", sum_int, dif_int);
    printf("%0.1f %0.1f\n", sum_float, dif_float);
    
    return 0;
}
