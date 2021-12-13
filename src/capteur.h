#ifndef __CAPTEUR__H__
#define __CAPTEUR__H__


typedef struct{
    int j;
    int m;
    int a;
}datesw;

typedef struct{
	char id[20];
	char type[20];
	char marque[20];
	char bloc[20];
	char etage[20];
	datesw d;
	float valMin;
	float valMax;
}capteur;

/*----------------------CRUD-----------------------*/
void ajouter_capteur(capteur c);
void supprimer_capteur(char id[]);
void modifier_capteur(capteur y);
void afficher_capteur(GtkWidget *liste, char *fname);
/*-----------------------------------------------------*/
int idExiste(char id[]);
capteur chercher_capteur(char id[]);
void ajouter_temperature(char id[],int j,int h,float valeur);
void list_id_capteur_defectueux();
void capteur_defectueux();
int isCapDefExiste(char id_d[]);




#endif
