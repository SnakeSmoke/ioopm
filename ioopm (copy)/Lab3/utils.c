#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "utils.h" 
#include <stdlib.h>
#include <time.h>



int clear_input_buffer()
{ 
  int c;
  do
    {
      c = getchar();
    }
  while (c != '\n');
  return 0;
}
int read_string(char *buf, int buf_siz)
{
  int i;
  char c;
  for(i = 0; i < buf_siz; i++)
    {
      c = getchar();
      if(c != '\n' && c != EOF) 
	{
        buf[i] = c;
      }
      else
	{
      break;  
	}
    }
  buf[i] = '\0';
  if ( c != '\n')
    {
      clear_input_buffer();
    }
 int read = strlen(buf);
  return read;
}

bool is_number(char *str)
{

  int length = strlen(str);
  int i = 0;
  if (length == 0)
    {
      return false;
    }
  else
    {
      if (str[0] == '-')
        i = 1;
      for(; i <= (length - 1); i++)
        if (!isdigit(str[i]))
          {
            return false;

          }
    }
  return true;
}

bool not_empty(char *str)
{
  return strlen(str) > 0;
}

answer_t ask_question(char *question, check_func check, convert_func convert)
{
  int buf_siz = 255;
  char buf[buf_siz];
  char *retur;
  do
    retur = ask_question_string(question, buf, buf_siz);
  while( check(retur) == false);
  return (answer_t) convert(retur);
}

char *ask_question_string(char *question, char *buf, int buf_siz)
{
 
  int len; //read_string(buf , buf_siz);

  do
    {
      printf("%s\n", question);
      len = read_string(buf, buf_siz);
    }
  while (len == 0);
  return buf;
}

int ask_question_int(char *question)
{

  int result = 0;
  int conversions = 0;
  do
    {
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      clear_input_buffer();
     }    
  while (conversions < 1);
  return result;
}











/*int main(void)
{
  int tal;
  int buf_siz = 255;
  int read = 0;
  char *namn;
  char buf[buf_siz];
  char *question = ("Vad heter du?");
  tal = ask_question_int("Första talet:");
  printf("Du skrev '%d'\n", tal);

  tal = ask_question_int("Andra talet:");
  printf("Du skrev '%d'\n", tal);
  
  puts("Läs in en sträng:");
  read = read_string(buf, buf_siz);
  printf("'%s' (%d tecken)\n", buf, read);

  puts("Läs in en sträng till:");
  read = read_string(buf, buf_siz);
  printf("'%s' (%d tecken)\n", buf, read);

  puts("Vad heter du?");;
  
  namn = ask_question_string(question, buf, buf_siz);
  printf("Hej,%s\n", buf);
  return 0;
  }*/























