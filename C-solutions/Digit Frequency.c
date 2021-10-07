#include <stdio.h>
#include <string.h>
int main() {    
    char s[1000];
    char str[10]={'0','1','2','3','4','5','6','7','8','9'};
    int len, i, j, count=0;
    
    scanf(" %[^\n]", s);
    len=strlen(s);
    
    for (i=0; i<10; i++) {
        for (j=0; j<len; j++) {
            if(str[i]==s[j]){
                count++;
            }
        }
        printf("%d", count);
        if (i!=9) {
            printf(" ");
        }
        count=0;
    }
}

