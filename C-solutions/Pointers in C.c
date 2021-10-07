#include<stdio.h>  
  
void update(int, int, int*);
void update2(int, int, int*);
  
int main()  {  
    int a, b, c;

    scanf("%d%d", &a, &b);  
    update(a, b, &c);  
    printf("%d\n", c);
    update2(a, b, &c);
    printf("%d", c);
      
    return 0;  
}  
  
void update(int x, int y, int *z){  
    *z = x+y;
}  
void update2(int x, int y, int *z){
    if(x>y){
        *z = x - y;
    }
    else if (x<y) {
        *z = y - x;
    }
}
