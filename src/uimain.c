#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main()
{
  List *list = init_history();
  while(1){
    printf("Please enter a sentence to tokenize, or use the following commands:\n!q to quit, !n where n is an id in the history to tokenize that string, !h to view the history.\n\n");
    printf("> ");
    char str[50];
    scanf(" %[^\n]", str, 50);
    puts("\n\n");
    if(str[0] == '!'){
	if(str[1] == 'q'){
	    goto quit;
	  }
	else if(str[1] == 'h'){
	    print_history(list);
	    puts("\n\n");
	  }
	else{
	    char strNum[49];
	    int z = 0;
	    while(str[z+1]){
		strNum[z] = str[z+1];
		z++;
	      }
	    int id = atoi(strNum);
	    char *str1 = get_history(list, id);
	    if(str1 == 0){
		printf("Invalid input.\n");
		continue;
	      }
	    char **tokenized = tokenize(str1);
	    printf("%s\n\n", str1);
	    print_tokens(tokenized);
	    puts("\n\n");
	    free_tokens(tokenized);
	    continue;
	  }
      }
    else{
	add_history(list, str);
	char **tokenized = tokenize(str);
	print_tokens(tokenized);
	puts("\n\n");
	free_tokens(tokenized);
      }
  } 
 quit:
  printf("Goodbye!\n");
  free_history(list);
}
