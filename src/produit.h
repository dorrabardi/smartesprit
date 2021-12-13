#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct date1
{
    char jour[20];
    char mois[20];
    char annee[20];

}date1;



typedef struct produit
{
    char ref[30];
    char nom[30];
    char poids[20];
    char Quantite[20];
	date1 	Date_achat;
	date1 	Date_expiration ;
	char Type[20];
    
}produit;

void produit_ajout(produit p,char nomfich[]);
int produit_recherche(char ref[],char ch0[],char ch1[],char ch2[],char ch3[],char ch4[],char ch5[],char ch6[],char ch7[],char ch8[],char ch9[],char ch10[]);
int prd_supprimer(char ref[]);
void Afficher(GtkWidget *Liste);
int repture_stock(GtkWidget *liste);

