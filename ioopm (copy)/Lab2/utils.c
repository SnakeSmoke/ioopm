#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int print(char *string){
  int y=0;
  do{
    putchar(string[y]);
    y++;
  }
  while (string[y]!='\0');
  return 0;
}
    

int clear_input_buffer(){
  char c;
  do
  {
    c = getchar();
  }
  while (c != '\n' && c!=EOF);
  return 0;
}

int read_string(char *buf, int buf_siz){
  char c;
  for(int i=0;(i<buf_siz) && (c != '\n' && c!=EOF);i++)
  {
    c = getchar();
    if (c=='\n'){
      return strlen(buf);
    }
    else{
      buf[i] = c;
    }
  }
  clear_input_buffer();
  return strlen(buf);
}

char *ask_question_string(char *question, char *buf, int buf_siz){
  do{
    printf("%s\n", question);
  }
  while (read_string(buf, buf_siz)==0);
return buf;
}



int ask_question_int(){
  int result = -1; // godtyckligt valt nummer
  scanf("%d", &result);
  clear_input_buffer();
  return result;
}


#endif
