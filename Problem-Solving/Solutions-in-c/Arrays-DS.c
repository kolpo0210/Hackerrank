#include <stdio.h>
#define MAX_SIZE 10000

int main(){
    long arr[MAX_SIZE];
    long size, i;

    scanf("%d", &size);

    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    for(i = size-1; i>=0; i--){
        printf("%d ", arr[i]);
    }

    return 0;
}
