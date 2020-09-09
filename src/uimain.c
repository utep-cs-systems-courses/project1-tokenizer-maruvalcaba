#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i = 3;
  while(i){
    printf("> ");
    char str[50];
    scanf("%s", str);
    printf("%s\n",str);
    i = i-1;
  }
}
