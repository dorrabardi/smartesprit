#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produit.h"
#include <gtk/gtk.h>
#include "interface.h"


enum
{
	Eref,
	Enom,
	Epoids,
	Equantite,
	Edate_achat,
	Edate_expiration,
	EType,
	COLUMNS,
};



/////////////////////////////////////////
void produit_ajout(produit p,char nomfich[])
{
FILE* f;
FILE* fw;

f = fopen("produit.txt","a+");
fw = fopen("stock.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.ref,p.nom,p.poids,p.Quantite,p.Date_achat.jour,p.Date_achat.mois,p.Date_achat.annee, p.Date_expiration.jour,p.Date_expiration.mois,p.Date_expiration.annee,p.Type );
}
if (fw!=NULL)
if (strcmp (p.Quantite,"0")==0)
{
fprintf(fw,"%s %s \n",p.ref,p.nom);
}
fclose(f);
fclose(fw); 
}
///////////////////////////


//////////////////////////
int prd_supprimer(char ref[])
{
	FILE *fw;

    	FILE *f;

    	FILE *fww;

    	FILE *fwww;

    int test=0;

    char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[30],ch9[20],ch10[20],ch11[20];

    f=fopen("produit.txt","r"); fw=fopen("produit_aux.txt","a");fww=fopen("stock.txt","r");fwww=fopen("stock_aux.txt","a");

    if (fw!=NULL && f!=NULL)

    {

        if (produit_recherche(ref,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11)==1)

        {

         while (fscanf (f, "%s %s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)

            {

                if (strcmp (ch1, ref) != 0)

                fprintf (fw,"%s %s %s %s %s %s %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);

                else

                {

                	test=1; 

                	strcpy(ch11,ch4);

                }



            }

        if (strcmp(ch11,"0")==0)

            while (fscanf (fww, "%s %s",ch1,ch2)!=EOF)

                    {

                if (strcmp (ch1, ref) != 0)

                fprintf (fwww,"%s %s \n",ch1,ch2);

                    }

        }

        else

        {

        test=0;
        fclose(fw);
        fclose(f);
        remove("produit_aux.txt");
        fclose (fww);
        fclose (fwww);
        remove("stock_aux.txt");
        return;
        

        }



    }

    else

        return ;

    fclose(fw);
    fclose(f);

    remove("produit.txt");
    rename("produit_aux.txt","produit.txt");
        fclose (fww);
        fclose (fwww);
        remove("stock.txt");
        rename("stock_aux.txt","stock.txt");
return test;

}

int produit_recherche(char ref[],char ch0[],char ch1[],char ch2[],char ch3[],char ch4[],char ch5[],char ch6[],char ch7[],char ch8[],char ch9[],char ch10[])

{

	FILE* f;
	 int test=0;

	f=fopen("produit.txt","r");

if (f!=NULL)

{

	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10)!=EOF)

		{

			if (strcmp(ref,ch0)==0)

            {

            test=1;

            break;

            }

		}

}

fclose(f);

return test;

}

void Afficher(GtkWidget *liste )
{

FILE *f;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore  *store;
store = NULL;

char ref[30];
char nom[30];
char poids[20];
char Quantite[20];
char jj[20],mm[20],aa[20];
char jj1[20],mm1[20],aa1[20];
char Type[20];
	
	
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ref",renderer ,"text",Eref,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Enom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("poids",renderer,"text",Epoids,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Quantite",renderer,"text",Equantite,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date d achat",renderer ,"text",Edate_achat,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date d expiration",renderer ,"text",Edate_expiration,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",EType ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); 
	f=fopen("produit.txt","r");
	if (f==NULL)
	{
	  return ;
	}
	else
	{
		
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",ref,nom,poids,Quantite,jj,mm,aa,jj1,mm1,aa1,Type)!=EOF)
		{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,Eref,ref,Enom,nom,Epoids,poids,Equantite,Quantite,Edate_achat,strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa),Edate_expiration,strcat(strcat(strcat(strcat(jj1,"/"),mm1),"/"),aa1),EType,Type, -1);
			  												    			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	 	}

		}

int repture_stock(GtkWidget *liste)
{
FILE *f;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore  *store;
store = NULL;

char ref[20];
char nom[20];

	
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ref",renderer ,"text",Eref,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Enom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("stock.txt","r");
	if (f==NULL)
	{
	  return ;
	}
	else
	{
		
		while(fscanf(f,"%s %s \n",ref,nom)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			  												    				  gtk_list_store_set(store,&iter,Eref,ref,Enom,nom,-1) ;
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	 	}
		
	}



