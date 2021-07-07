#include <stdio.h>
#include <stdlib.h>
#include "history.h"

//Initialize LL
List* init_history(){
  List *history = (List*) malloc(sizeof(List) * 300);
  return history;
}

//add history to the list
void add_history(List *list, char *str){
  Item* addItem = (Item*) malloc(sizeof(Item)*300);
  addItem->str = str;
  if(list->root == NULL){
    addItem->id = 1;
    list->root = addItem;
  }
  else{
    Item* history_item = list->root;
    addItem->id=1;
    while(history_item->next!=NULL){
      addItem->id++;
      history_item=history_item->next;
    }
    history_item=history_item->next;
    addItem->str = str;
    addItem->id++;
  }
}
//retrieve string stored in the node
char *get_history(List *list, int id){
  if (list->root == NULL){
    return "List is empty.";
  }else{
    Item* temp = list->root;
    while(temp != NULL){
      if(temp->id == id){
	return temp->str;
      }
      temp = temp->next;
    }
    return("Item not found.");
  }
}
//print contents of the list
void print_history(List *list){
  int i=0;
  Item *tmp = list->root;
  while (tmp!=NULL){
    printf("Item[%d]: %s\n", tmp->id, tmp->str);
    tmp = tmp->next;
  }
}
//free the history
void free_history(List *list){
  Item* tmp;
  Item* tmp2 = list->root;
  while(tmp2 != NULL){
    tmp = tmp2;
    tmp2 = tmp2->next;
    free(tmp);
    free(tmp->str);
  }
  free(list);
}
