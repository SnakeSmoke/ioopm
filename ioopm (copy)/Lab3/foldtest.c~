#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int(*int_fold_func)(int, int);



int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f) {
  int result = 0;
  int i = 0;	

  // Loopa över arrayen och för varje element e utför result = f(result, e)
  for (i = 0; i < numbers_siz; ++i)
  {
    result = f(result, numbers[i]);
  }

  return result;
}


int add(int a, int b) {
  return a + b;
}
