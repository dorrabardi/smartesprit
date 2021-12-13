#include <gtk/gtk.h>

typedef struct date
{
    char jour[20];
    char mois[20];
    char annee[20];

}date;


typedef struct utilisateur
{
    char nom[30];
    char prenom[30];
    char cin[20];
    date naissance;
    char login[20];
    char password[20];
    char sexe[20];
    char role[20];
    char niveau[20];
}utilisateur;

void util_ajout(utilisateur u,char nomfich[]);
int util_recherche(char cin[],char ch0[],char ch1[],char ch2[],char ch3[],char ch4[],char ch5[],char ch6[],char ch7[],char ch8[],char ch9[],char ch10[],char ch11[]);
util_supprimer(char cin[]);
void util_afficher(GtkWidget *liste);
int E_afficher(GtkWidget *liste,char niv[]);
void vider(GtkWidget* liste);
int auth_admin(char id[], char mdp[],char role []);
