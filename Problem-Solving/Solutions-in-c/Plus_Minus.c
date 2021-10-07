#include <stdio.h>

int main()
{
   int size,inp; 
   scanf("%d",&size);
   int pos=0,neg=0,zer=0;
   for(int i=0;i<size;i++) {
        scanf("%d",&inp);
        if(inp>0) pos++;
          else if(inp<0) neg++;
             else zer++;
   }
   printf("%6f\n",(float)pos / size);
   printf("%6f\n%6f\n",(float)neg / size ,(float)zer / size);
   return 0;
}
