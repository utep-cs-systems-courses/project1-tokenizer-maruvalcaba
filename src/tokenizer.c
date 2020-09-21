#include <stdio.h>
#include <stdlib.h>

int space_char(char c)       /* return 1 if c is a space character and not '\0', 0 otherwise */
{
  if(((c == ' ') || (c == '\t')) && (c != '\0')){
    return 1;
  }
  return 0;
}

int non_space_char(char c)   /* return 1 if c is not a space character and not '\0', 0 otherwise */
{
  if ((c != ' ') && (c != '\t') && (c != '\0')){
    return 1;
  }
  return 0;
}

char *word_start(char *str)  /* returns a char pointer to the start of the next word. */
{
  int i = 0;
  while(space_char(*(str+i))){  /* while there current character is a space, move forward */
    i++;
  }
  if(str[i] == '\0'){        /* returns a zero pointer if there is no word found */
    return 0;                 
  }
  return str+i; 
}

char *word_terminator(char *word)  /* returns a char pointer to the space after the word */
{
  int i = 0;
  while(non_space_char(*(word+i))){  /* while the current is a character, move forward */
    i++;
  }
  return word+i;
}

int count_words(char *s)   /* returns the number of words in a string */
{
  int i = 0;
  char *str = s;
  while((*word_terminator(str) != '\0')){  /* while there is still words */
    str = word_start(word_terminator(str));   
      if(str ==  0){   /* if there is only white space remaining */
	break;
	}
      i++;
  }
  i++;
  return i;
}

char *copy_str(char *inStr, short len)  /* returns a pointer to a copy of the string */
{
  char *str_copy = (char *)malloc(len+1);  /* allocates space for the word */
  int i;
  for(i = 0; i < len; i++){  /* copies each character in a given length from the input string */
    str_copy[i] = inStr[i];
  }
  str_copy[i] = '\0';
  return str_copy;
}

void print_tokens(char **tokens)  /* prints the tokens in a given token array */
{
  int i = 0;
  while(tokens[i] != NULL){       /* while there are still tokens */
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens)  /* frees the memory allocated for the tokens */
{
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);       /* frees each of the strings */
    i++;
  }
  free(tokens);            /* frees the space allocated for the token pointers */
}

char **tokenize(char* str)  /* tokenizes the input string and returns a pointer to the tokens */
{
  char **tokens = malloc((count_words(str)+1)*sizeof(char *));  /* allocates space for tokens */
  char *start = word_start(str);   /* pointer to the start of the word */
  int i = 0;
  while(start){
    char *end = word_terminator(start);  /* pointer to the end of the word */
    tokens[i] = (char *) copy_str(start, end-start);
    i++;
    start = word_start(end);
  }
  tokens[i] = NULL;
  return tokens;
}

