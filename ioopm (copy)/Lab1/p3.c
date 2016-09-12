#include <stdio.h>

int main(void)
{
  int i=0,j=0,f=0;
  
  for(i=1; i <= 10; i++){
    
    for(j=1; j <= i; j++){
      printf("#");
	}
    printf("\n");
    f = f+i;
  }
  printf("Total: %d\n ", f);
  return 0;
}
