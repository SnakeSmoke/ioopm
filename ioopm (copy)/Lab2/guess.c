#include "utils.h"
#include <time.h>

/*
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
  int  x;
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

*/
int main(void)
{
  int buf_siz = 255,i=0, guess=0;
  char buf[buf_siz], *question;
  srand(time(0));
  int ran = rand()%50+1;
  question = "Skriv in ditt namn:";
  ask_question_string(question, buf, buf_siz);
  printf("Du %s, jag tänker på ett tal ... kan du gissa vilket?\n", buf);
  do{
    scanf("%d", &guess);
    if (guess<ran){
      puts("För litet!");
      i++;
    }
    else if (guess>ran){
      puts("för stort");
      i++;
    }
    else{
      printf("Bingo!\nDet tog %s %d gissningar att komma fram till %d\n", buf, i, ran);
      return 0;
    }
  }
  while (i<=16);
  printf("Nu har du slut på gissningar! Jag tänkte på %d!\n", ran);
  return 0;
}
