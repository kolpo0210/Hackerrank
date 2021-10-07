#include <stdio.h>
int main()
{
    char s[26];
    scanf(" %[^\n]", s);
    printf("Hello, World!");
    printf("\n%s", s);

    return 0;
}
