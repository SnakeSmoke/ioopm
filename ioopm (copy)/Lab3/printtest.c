#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void print (char *str){
 
int i = 0;

 for(i=0; i <= strlen(str); i++)
   putchar(str[i]);
}



void println (char *str){

int j = 0;

 for(j=0; j <= strlen(str); j++)

   putchar(str[j]);
   print("\n");
}




int main (int argc, char *argv[]) {

  println(argv[1]);
  return 0; 

}
