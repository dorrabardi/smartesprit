#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>
#include "interface.h"


enum
{
	CIN,
	NOM,
	PRENOM,
	ROLE,
	SEXE,
	LOGIN,
	MDP,
	DATE,
	COLUMNS,
};


void util_ajout(utilisateur u,char nomfich[])
{
FILE* f;
FILE* fw;
f = fopen("utilisateurs.txt","a+");
fw = fopen("etudiants.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s \n", u.cin,u.nom,u.prenom,u.sexe,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.role,u.login,u.password);
}
if (fw!=NULL)
if (strcmp (u.role,"Etudiant")==0)
{
fprintf(fw,"%s %s %s %s %s \n", u.cin,u.nom,u.prenom,u.sexe,u.niveau);
}
fclose(f);
fclose(fw);
}




int util_recherche(char cin[],char ch0[],char ch1[],char ch2[],char ch3[],char ch4[],char ch5[],char ch6[],char ch7[],char ch8[],char ch9[],char ch14[],char ch16[])
{
	FILE* f;
	FILE*fw ;
 	int test=0; char ch11[20],ch12[10],ch13[20],ch10[20],ch15[20];
	f=fopen("utilisateurs.txt","r"); fw=fopen("etudiants.txt","r");
if (fw!=NULL && f!=NULL)
{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9)!=EOF)
		{
			if (strcmp(cin,ch0)==0 || strcmp(ch16,ch8)==0)
            {
            test=1;

            break;
            }
		}
if (strcmp(ch7,"Etudiant")==0)
          while (fscanf (fw, "%s %s %s %s %s",ch10,ch11,ch12,ch13,ch14)!=EOF)
              {
              if (strcmp (ch0,  ch10) == 0)
              break;
              }
}
fclose(f);
fclose(fw);
return test;
}





int util_supprimer(char cin[])
{
    FILE* fw;
    FILE* f;
    FILE* fww;
    FILE* fwww;
    int test=0;
    int a,b;
    char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[10],ch7[20],ch8[30],ch9[20],ch10[20],ch11[20];
    f=fopen("utilisateurs.txt","r"); fw=fopen("utilisateurs_aux.txt","a"); fww=fopen("etudiants.txt","r");fwww=fopen("etudiants_aux.txt","a");
    if (fw!=NULL && f!=NULL)
    {
        if (util_recherche(cin,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,"")==1)
        {
         while (fscanf (f, "%s %s %s %s %s %s %s %s %s %s",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10)!=EOF)
            {
                if (strcmp (ch1, cin) != 0)
                fprintf (fw,"%s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10);
                else
                {
                  test=1; //suppression etablie.
		  strcpy(ch11,ch8);
                }

            }
        if (strcmp(ch11,"Etudiant")==0)
            while (fscanf (fww, "%s %s %s %s %s",ch1,ch2,ch3,ch4,ch5)!=EOF)
                    {
                if (strcmp (ch1,  cin) != 0)
                fprintf (fwww,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
                    }
        }
        else
        {
	test=0;
        fclose(fw);
        fclose(f);
        remove("utilisateurs_aux.txt");
        fclose (fww);
        fclose (fwww);
        remove("etudiants_aux.txt");
        return;
        }

    }
    else
        return ;
    fclose(fw);
    fclose(f);

    remove("utilisateurs.txt");
    rename("utilisateurs_aux.txt","utilisateurs.txt");
        fclose (fww);
        fclose (fwww);
        remove("etudiants.txt");
        rename("etudiants_aux.txt","etudiants.txt");
return test;
}


void util_afficher(GtkWidget *liste)
{
FILE* f;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore  *store;
store = NULL;

char cin[20];
char nom[20];
char prenom[20];
char role[20];
char sexe[20];
char jj[20],mm[20],aa[20];
char login[20];
char password[20];





store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


}


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("utilisateurs.txt","r");
if (f==NULL)
{
	return;
}

else
{
	while( fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",cin,nom,prenom,sexe,jj,mm,aa,role,login,password)!=EOF)
	{
	gtk_list_store_append(store,&iter);

	gtk_list_store_set(store,&iter,CIN,cin, NOM,nom, PRENOM,prenom, SEXE,sexe, DATE, strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa), ROLE,role, LOGIN,login, MDP,password,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}




int E_afficher(GtkWidget *liste,char niv[])
{
FILE* f;
FILE* fw;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore  *store;
store = NULL;

char cin[20];
char nom[20];
char prenom[20];
char role[20];
char sexe[20];
char jj[20],mm[20],aa[20];
char login[20];
char password[20];

char cin1[20];
char nom1[20];
char prenom1[20];
char role1[20];
char sexe1[20];
char jj1[20],mm1[20],aa1[20];
char login1[20];
char password1[20];
char niveau[20];

int nb=0;
int c;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


}


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("utilisateurs.txt","r");
if (f==NULL)
{
	return;
}

else if (f!=NULL && strlen(niv)==0)
{
f=fopen("utilisateurs.txt","a+");
	while( fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",cin,nom,prenom,sexe,jj,mm,aa,role,login,password)!=EOF)
	{
	if (strcmp(role,"Etudiant")==0)
	{
	nb++;
	gtk_list_store_append(store,&iter);

	gtk_list_store_set(store,&iter,CIN,cin, NOM,nom, PRENOM,prenom, SEXE,sexe, DATE, strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa), ROLE,role, LOGIN,login, MDP,password,-1);
	}
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
else if ( strlen(niv)!=0)
{
f=fopen("utilisateurs.txt","r");
fw=fopen("etudiants.txt","r");
if (f==NULL && fw == NULL )
{
	return;
}

else if (f!=NULL && fw != NULL)
{
	while( fscanf(fw,"%s %s %s %s %s \n",cin,nom,prenom,sexe,niveau)!=EOF)
	{
	if (strcmp(niv,niveau)==0)
    {
	nb++;
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",cin1,nom1,prenom1,sexe1,jj1,mm1,aa1,role1,login1,password1)!=EOF)
	{
	if (strcmp(cin,cin1)==0)
	{
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,CIN,cin1, NOM,nom1, PRENOM,prenom1, SEXE,sexe1, DATE, strcat(strcat(strcat(strcat(jj1,"/"),mm1),"/"),aa1), ROLE,role1, LOGIN,login1, MDP,password1,-1);
	rewind(f);
	break;
	}
	}
	}
	}
	fclose(f);
	fclose(fw);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
return nb;
}

void vider(GtkWidget* liste)
{
FILE* f;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore  *store;
store = NULL;

char cin[20];
char nom[20];
char prenom[20];
char role[20];
char sexe[20];
char jj[20],mm[20],aa[20];
char login[20];
char password[20];


store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


}


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
}














int auth_admin(char id[], char mdp[],char role [])
{
FILE* f; int test=0;

 char ch1[20],ch2[20];
f=fopen("utilisateurs.txt","r");
if (f!=NULL)
{
	while( fscanf(f,"%*s %*s %*s %*s %*s %*s %*s %s %s %s \n",role,ch1,ch2)!=EOF)
		{
			if ( (strcmp(ch1,id)==0) && (strcmp(ch2,mdp)==0))
{
				test=1;
break;
}
		}
}
fclose(f);
return test;
}

