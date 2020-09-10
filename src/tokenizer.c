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

char *word_start(char *s)
{
  int i = 0;
  while(space_char(*(s+i)))
    {
      i++;
    }
  if(i == 0)
    {
      return 0;
    }
  return s+i;
}

char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(*(word+i)))
    {
      i++;
    }
  printf("Number: %d\n", i);
  return word+i;
}

int count_words(char *s)
{
  int i = 0;
  char *str = s;
  while(*word_terminator(str) != '\0')
    {
      i++;
      str = word_start(word_terminator(str));
    }
  i++;
  return i;
}

int main()
{
  int value;
  
  value = space_char(' ');
  printf("%d\n", value);
  value = space_char('\t');
  printf("%d\n", value);
  value = space_char('c');
  printf("%d\n", value);
  value = space_char('0');
  printf("%d\n", value);
  value = space_char('\0');
  printf("%d\n", value);
  puts("");
  
  value = non_space_char(' ');
  printf("%d\n", value);
  value = non_space_char('\t');
  printf("%d\n", value);
  value = non_space_char('c');
  printf("%d\n", value);
  value = non_space_char('0');
  printf("%d\n", value);
  value = non_space_char('\0');
  printf("%d\n", value);
  puts("");
  
  char *str = "   hello";
  int x = (&str[3] == word_start(str));
  printf("Did it work? %d\n", x);
  puts("");

  char *str3 = "happy joy";
  int x1 = (&str3[5] == word_terminator(str3));
  printf("Did it work? %d\n", x1);
  puts("");

  int x2 = (count_words(str3));
  printf("Number of words in 'happy joy: %d\n", x2);

}

