#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h" 
#include "history.h"
#define MAX 2041

int compareStrings(const char *temp1, const char *temp2){
  while(*temp1 && *temp2){
    if(*temp1 == *temp2){
      temp1++;
      temp2++;
    }else{
      if(*temp1 < *temp2){
	return -1; //returning negative value
      }else{
	return 1; //returning positive value
      }
    }
  }
  return 0; //return if strings are the same
}
int main(void){
  char buffer[2041];
  int condition = 1;

  List* test_history = init_history();
  printf("%s\n", get_history(test_history, 1)); //should be empty
  add_history(test_history, "happy");
  add_history(test_history, "joy");

  printf("%s\n", get_history(test_history, 0));//print not found
  printf("%s\n", get_history(test_history, 1));//print happy

  List* list = init_history();
  while(condition == 1){
    printf("$ ");//ready for input
    fgets(buffer, MAX, stdin);
    char** tokens = tokenize(buffer);
    print_tokens(tokens);

    if(compareStrings(tokens[0], "history") == 0){
      print_history(list);
    }else if(tokens[0][0] - '!' == 0){
      int x = tokens[0][1] - '0';
      if(x >= 1){
	printf("%s\n", get_history(list, x));
      }
    }else{
      add_history(list, buffer);
    }
  }
  return 0;
}
