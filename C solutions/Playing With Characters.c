#include <stdio.h>

int main() 
{
    int i;
    
    for (i=0; i<3; i++) {
        char ch[1000];
        scanf(" %[^\n]", ch);
        printf("%s\n", ch);
    }
    return 0;
}
