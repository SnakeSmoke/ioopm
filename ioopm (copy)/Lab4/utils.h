#ifndef __UTILS_H__
#define __UTILS_H__

typedef union {
  int   i;
  float f;
  char *s;
} answer_t;
typedef bool(*check_func)(char *);
typedef answer_t(*convert_func)(char *);

int read_string(char *buf, int buf_siz);
int ask_question_int(char *question);
char *ask_question_string(char *question, char *buf, int buf_siz);
answer_t ask_question(char *question, check_func check, convert_func convert);
bool not_empty(char *str);
bool is_number(char *str);
#endif



