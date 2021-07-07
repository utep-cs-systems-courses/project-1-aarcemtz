#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define false 0
#define true 1

// Return true if c is whitespace
int space_char(char c){
  if(c!= ' ' || c != '\t'){
    return true;
  }
  else{
    return false;
  }
}
//return true if c is not whitespace
int non_space_char(char c){
  if(c!= ' '&& c != '\t'){
    return true;
  }
  else{
    return false;
  }
}
/*Return pointer to the first char of the next word
  Return a zero pointer if str doesnt contain any words*/
char *word_start(char *str){
  char* tmp = str;
  while (*tmp != '\0'){
    if((non_space_char(tmp[0])) ==1){
      return tmp;
   }
    tmp++;
  }
  return tmp;
}
//Returns pointer terminator char following word
char *word_terminator(char *word){
  while(non_space_char((*word))){
    word++;
    if(space_char(*word)) {
      return word;
    }
  }
  return "0";
}
// Count number of words
int count_words(char *str){
  int count = 0;
  int out = 0;
  int in = 0;
  int state = out;

  while(*str){
    if(*str ==' '||*str == '\t' || *str == '\n' ){
      state = out;
    }else if (state == out){
      state = in;
      count++;
    }
    str++;
  }
  return count;
}
char *copy_str(char *intStr, short len){
  char* helper = intStr;
  char* copyStr = NULL;

  copyStr = (char*) malloc(sizeof(char)*(len + 1));

  copyStr[len] = '\0';
  int index = 0;

  while (*helper != '0') {
    copyStr[index++]= *helper++;
  }
  return copyStr;
}
char **tokenize(char* str){
  int size = count_words(str);
  //allocate mem
  char** tokens =(char**) malloc(sizeof(char*));
  char* start = word_start(str);
  char* terminator = word_terminator(start);
  int i;
  for(i=0;i<size;i++){
    if(i<0){
      start = word_start(str);
      terminator = word_terminator(start);
    }
    int size2 = terminator - start;
    tokens[i] = malloc(size2*sizeof(char));
    for(int j=0;j < size2; j++){
      tokens[i][j] = start[j];
    }
  }
  return tokens;
}
//print all tokens
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
}
//frees all tokens and the vector with them
void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  free(tokens);
}
