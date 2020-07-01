#include <stdio.h>
#include <stdlib.h>
#ifndef _HISTORY_
#define _HISTORY_
#include "tokenizer.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_list {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history()
{
  Item *head = malloc(sizeof(Item));
  head->id = -1;
  head->str = "null";
  head->next = NULL;

  List *myList = malloc(sizeof(List));                 // Set as root of the list
  myList->root = head;
  return myList;                                       // Return address
}

/* Add a history item to the end of the list.
   List* list - the linked list 
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  char *input = malloc(sizeof(char*) * 100);           // Allocate space and copy word
  copy_str(str,input);

  if (list->root->id == -1){                           // Check if history is empty, if it is
    Item *firstItem = malloc(sizeof(Item));            // set item as root
    firstItem->id = 1;
    firstItem->str = input;
    firstItem->next = NULL;                            // "next" item is set to NULL
    list->root = firstItem;
    return;
  }
  
  Item *myItem = malloc(sizeof(Item));                 // Ready item to be put in
  myItem->id = (list->root->id);
  myItem->str = input;
  myItem->next = NULL;
  int counter = 2;                                     // Use counter as id in item to be created
  Item *tempItem = list->root;                         // Traverse list

  while (tempItem->next != NULL){
    tempItem = tempItem->next;
    counter++;
  }
  tempItem->next = myItem;                             // Insert item to end of list
  myItem->id = counter;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find
*/
char *get_history(List *list, int id)
{
  Item *tempItem = list->root;
  while(tempItem != NULL){                             // Search through list until id is a match
    char *string = tempItem->str;
    if (tempItem->id == id){
      return string;
    }
    tempItem = tempItem->next;
  }
  return NULL;                                         // id is not found; Return NULL
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  if (list->root->id == -1){
    printf("History: Empty\n");
    return;
  }
  Item *tempItem = list->root;

  while (tempItem != NULL){
    printf("%d %s\n" , tempItem->id , tempItem->str);
    tempItem = tempItem->next;
  }
  
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *iter = list->root;                                // Start at root                        
  while (iter != NULL){                                   // Go through list 
    Item *next = iter->next;
    free(iter);                                           // Free current Item in list
    iter = next;
  }
}

#endif
