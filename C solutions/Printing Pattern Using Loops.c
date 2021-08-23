
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

    print_upper_part(n);
    print_lower_part(n);

    return 0;
}

void print_upper_part( int n )
{
    int i,j,k,m;

    for( i = n; i >= 1 ; i-- ){

        for( j = n; j >= i; j-- ){
            printf("%d ",j);
        }

        j++;

        for( k = 1; k <= (2*j) - 3; k++  ){
            printf("%d ",j);
        }

        j = j == 1 ? 2 : j;

        for( m = j; m <= n; m++ ){
            printf("%d ",m);
        }
        printf("\n");
    }
}

void print_lower_part( int n )
{
    int i,j,k,m;

    for( i = 2; i <= n ; i++ ){

        for( j = n; j >= i; j-- ){
            printf("%d ",j);
        }

        j++;

        for( k = 1; k <= (2*j) - 3; k++ ){
            printf("%d ",j);
        }

        for( m = i; m <= n; m++ ){
            printf("%d ",m);
        }
        printf("\n");
    }
}
