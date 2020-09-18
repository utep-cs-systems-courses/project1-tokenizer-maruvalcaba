#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if(((c == ' ') || (c == '\t')) && (c != '\0'))
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if ((c != ' ') && (c != '\t') && (c != '\0'))
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  int i = 0;
  while(space_char(*(str+i)))
    {
      i++;
    }
  if(str[i] == '\0')
    {
      return 0;
    }
  return str+i;
}

char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(*(word+i)))
    {
      i++;
    }
  return word+i;
}

int count_words(char *s)
{
  int i = 0;
  char *str = s;
  while((*word_terminator(str) != '\0'))
    {
      str = word_start(word_terminator(str));
      if(str ==  0)
	{
	  break;
	}
      i++;
    }
  i++;
  return i;
}

char *copy_str(char *inStr, short len)
{
  char *str_copy =(char *)malloc(len+1);
  int i;
  for(i = 0; i < len; i++)
    {
      str_copy[i] = inStr[i];
    }
  str_copy[i] = '\0';
  return str_copy;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL)
    {
      printf("%s\n", tokens[i]);
      i++;
    }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL)
    {
      free(tokens[i]);
      i++;
    }
  free(tokens);
}

char **tokenize(char* str)
{
  char **tokens = malloc((count_words(str)+1)*sizeof(char *));
  char *start = word_start(str);
  int i = 0;
  while(start)
    {
      char *end = word_terminator(start);
      tokens[i] = (char *) copy_str(start, end-start);
      i++;
      start = word_start(end);
    }
  tokens[i] = NULL;
  return tokens;
}

