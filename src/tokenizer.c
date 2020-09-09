#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if(((c == ' ') || (c == '\t')) && (c != '0'))
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if ((c != ' ') && (c != '\t') && (c != '0'))
    {
      return 1;
    }
  return 0;
}

char *word_start(char *s)
{
  
}
