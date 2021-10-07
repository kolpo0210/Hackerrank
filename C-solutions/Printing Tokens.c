#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    int len, i; 
    
    scanf(" %[^\n]", s);
    len=strlen(s);
    
    for (i=0; i<len; i++) {
        if (s[i] != ' ') {
            printf("%c", s[i]);
        }
        else {
            i++;
            if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') {
                printf("\n");
                printf("%c", s[i]);
            }
        }
    }
    
    return 0;
}
