#include "history.h"
#include "malloc.h"
Item *root1 = 0;

List* init_history()
{
  List *history = malloc(sizeof(List));
  history -> root = root1;
  return history;
}

void add_history(List *list, char *str)
{
  int itemid = 1;
  if(list -> root == 0)
    {
      Item *newItem = malloc(sizeof(Item));
      newItem -> id = itemid;
      newItem -> next = 0;
      char *sc = str;
      while(*sc++);
      int strindex = 0;
      char *strcopy = malloc((sc-str+1) * sizeof(char)), c;
      do
	{
	  c = *(strcopy+strindex) = *(str+strindex);
	  strindex++;
	} while (c);
      newItem->str = strcopy;
      list -> root = newItem;
    }
  else
    {
      Item *current = list -> root;
      while (current->next != 0)
	{
	  current = current->next;
	  itemid++;
	}
      Item *newItem = malloc(sizeof(Item));
      newItem -> id = itemid;
      newItem -> next = 0;
      char *sc = str;
      while(*sc++);
      int strindex = 0;
      char *strcopy = malloc((sc-str+1) * sizeof(char)), c;
      do
	{
	  c = *(strcopy+strindex) = *(str+strindex);
	  strindex++;
	} while (c);
      newItem->str = strcopy;
      current->next = newItem;
    }
}
