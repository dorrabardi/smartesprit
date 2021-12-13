#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure menu
typedef struct wmenu
{ char id[200];
  char nom[200];
  char repas[200];
  char date[200];
  char entree[200];
  char dessert[200];
  float dechets ;
  int jour ;
  int temps; 
 } wmenu;

void wajouter(wmenu M);
void wsupprimer(char id[]);
wmenu wchercher(char id[]);
void wafficher();
int verif_w(char id[]);
void calculdechets(char dec,char rep);
wmenu wdechets();

