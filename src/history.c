#include "history.h"
#include <stdio.h>
#include <stdlib.h>
List *init_history()                  /* initializes the history list of tokens, returns pointer */
{
  List *history = malloc(sizeof(List)); /* allocates space for the pointer to the list */
  history -> root = 0;
  return history;
}

void add_history(List *list, char *str)
{
  int itemid = 1;
  if((list->root) == 0){
      Item *newItem = malloc(sizeof(Item));
      newItem -> id = itemid;
      newItem -> next = 0;
      char *sc = str;
      while(*sc++);
      int strindex = 0;
      char *strcopy = malloc((sc-str+1) * sizeof(char));
      char c;
      do
	{
	  c = (*(strcopy+strindex) = *(str+strindex));
	  strindex++;
	} while (c);
      newItem->str = strcopy;
      list->root = newItem;
    }
  else{
    itemid++;
    Item *current = list->root;
    while(current->next){
	current = current->next;
	itemid++;
      }
    Item *newItem = malloc(sizeof(Item));
    newItem -> id = itemid;
    newItem -> next = 0;
    char *sc = str;
    while(*sc++);
    int strindex = 0;
    char *strcopy = malloc((sc-str+1) * sizeof(char));
    char c;
    do
      {
	c = (*(strcopy+strindex) = *(str+strindex));
	strindex++;
      } while (c);
    newItem->str = strcopy;
    current->next = newItem;
  }
}

char *get_history(List *list, int id){
  Item *current = list->root;
  while(current){
      if((current->id) == id){
	  return current->str;
	}
      else{
	  current = current->next;
	}
    }
  return 0;
}

void print_history(List *list){
  Item *current = list->root;
  while(current != 0){
      printf("(%d) %s\n", (current->id), (current->str));
      current = current->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  Item *next;
  while(current){
      next = current->next;
      free(current->str);
      free(current);
      current = next;
    }
  free(list);
}

