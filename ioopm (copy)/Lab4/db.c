#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <time.h>
#include <stdlib.h>

extern char *strcpy (char *__restrict __dest, __const char *__restrict __src);

struct item {

    char  name[50];
    char  desc[50];
    int   price;
    char  shelf[50];
};

typedef struct item item_t;

void print_item(item_t *item){
    
    printf( "Item name  : %s\n", item->name);
    printf( "Item desc  : %s\n", item->desc);
    printf( "Item price : %d.%d kr\n", item->price/100, item->price%100);
    printf( "Item shelf : %s\n", item->shelf);
}

item_t make_item(char* name, char* desc, int price, char* shelf) {
	
    

    //char* itemname  = strdup(name);
    //char* itemdesc  = strdup(desc);
    //int   itemprice = price;
    //char* itemshelf = strdup(shelf);
    
    item_t s;
    strcpy(s.name, name);
    strcpy(s.desc, desc);
    s.price = price;
    strcpy(s.shelf, shelf);


	 //{ .name=itemname, .desc=itemdesc, .price=itemprice, .shelf=itemshelf };
 
    //print_item(&s);   										//Test to check if the make_item() function works
    return s;
}

item_t input_item() {
	
    int buf_siz = 255;
    char buf[buf_siz];


    char* itemname  = strdup(ask_question_string("Item name?: ", buf, buf_siz));
    char* itemdesc  = strdup(ask_question_string("Item desc?: ", buf, buf_siz));
    int   itemprice = ask_question_int("Item price?: ");
    char* itemshelf = strdup(ask_question_string("Item shelf?: ", buf, buf_siz));
    
    item_t item;
    strcpy(item.name, itemname);
    strcpy(item.desc, itemdesc);
    item.price = itemprice;
    strcpy(item.shelf, itemshelf);
	
    make_item(itemname, itemdesc, itemprice, itemshelf);
	
    return item;
    
    
}


char* magick(char* arr1[],char* arr2[],char* arr3[], int i) {

int ran1 = rand() % i;
int ran2 = rand() % i;
int ran3 = rand() % i;

char *buf=malloc(255);  
buf[0] = 0;

strcat(buf, arr1[ran1]);
strcat(buf, "-");
strcat(buf, arr2[ran2]);
strcat(buf, " ");
strcat(buf, arr3[ran3]);


//strcat(buf, );
//strcat(buf, " ");
// = { arr1[ran1], "-", arr2[ran2], " ", arr3[ran3] }; 

puts(buf);
return buf;

}


/*void menu() {

    srand ( time(NULL) );

    char *array1[] = { "Laser",        "Polka",    "Extra" };
    char *array2[] = { "förnicklad",   "smakande", "ordinär" };
    char *array3[] = { "skruvdragare", "kola",     "uppgift" };

    int input;

    printf( "1. input_item()\n" );
    printf( "2. magick()\n" );    
    printf( "2. Exit\n" );
    printf( "Selection: " );
    scanf( "%d", &input );
    switch ( input ) {
        case 1:            
            input_item();
            break;
        case 2:        
            magick(array1, array2, array3);
            break;
        case 3:            
            printf( "Good Bye!\n" );
            break;
        default:            
            printf( "Bad input, quitting!\n" );
            break;
	}
    getchar();
}*/

void list_db(item_t *items, int no_items) {

    printf("%d. %s\n", no_items, items->name);
}



item_t edit_db(item_t *items,int no_items)
{
  char *question = "Vilken vara skall editeras?";
  int vara = ask_question_int(question);
  bool test = false;
  do
    {
      if(vara > 0 && vara < 17)
	test = true;
      else
	vara = ask_question_int(question);
    }
  while(test == false);
  print_item(&items[vara-1]);
  items[vara-1] = input_item();
    for (int i = 0; i < no_items; ++i)
	{
	  print_item(&items[i]);
	}
    return *items;
}


int main(int argc, char *argv[]) {
    
    srand ( time(NULL) );

    char *array1[] = { "Laser",        "Polka",    "Extra" };
    char *array2[] = { "förnicklad",   "smakande", "ordinär" };
    char *array3[] = { "skruvdragare", "kola",     "uppgift" };

  if (argc < 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0;    // Antalet varor i arrayen just nu

    int items = atoi(argv[1]); // Antalet varor som skall skapas

    if (items > 0 && items <= 16)
    {
      for (int i = 0; i < items; ++i)
      {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item;
        ++db_siz;
      }
    }
    else
    {
      puts("Sorry, must have [1-16] items in database.");
      return 1; // Avslutar programmet!
    }

    for (int i = db_siz; i < 16; ++i)
      {
        char *name = magick(array1, array2, array3, 3); /// Lägg till storlek
        char *desc = magick(array1, array2, array3, 3); /// Lägg till storlek
        int price = rand() % 200000;
        char shelf[] = { rand() % ('Z'-'A') + 'A',
                         rand() % 10 + '0',
                         rand() % 10 + '0',
                         '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item;
        ++db_siz;
      }

     // Skriv ut innehållet
     for (int i = 0; i < db_siz; ++i)
     {
       list_db(&db[i], i+1);
     }
       edit_db(db, db_siz);
  }
  return 0;
}




   /* struct items item;

    strcpy(item.name, "Carrot");
    strcpy(item.desc, "Vegetable");
    item.price = 11;
    strcpy(item.shelf, "A25");

    print_item(&item);
    
    //char* d = "123";*/
    
