#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionmenu.h"
#include <gtk/gtk.h>

enum
{
	id,
	nom,
	repas,
	date,
	entree,
	dessert,
	COLUMNS
};
void wajouter(wmenu M)
{
FILE *f=NULL;
f=fopen("menu.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n",M.id,M.nom,M.repas,M.date,M.entree,M.dessert);
fclose(f);
}
}





void wsupprimer(char id[])


{
  
  FILE *F, *FW;
  wmenu M ;
 
F = fopen ("menu.txt", "r");
FW = fopen ("trp.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf(F,"%s %s %s %s %s %s \n",M.id,M.nom,M.repas,M.date,M.entree,M.dessert)!=EOF)
    if  (strcmp(M.id,id)!=0) 
      {
fprintf (FW, "%s %s %s %s %s %s \n",M.id,M.nom,M.repas,M.date,M.entree,M.dessert);
}
}
  fclose (F);
  fclose (FW);
remove("menu.txt");
rename("trp.txt", "menu.txt");



}






wmenu wchercher(char id[])

{
wmenu M;
wmenu N;
char ch[200];
FILE *f=NULL;
f=fopen("menu.txt","r");

if (f!=NULL)
{
	
	
		while(fscanf(f,"%s %s %s %s %s %s \n",M.id,M.nom,M.repas,M.date,M.entree,M.dessert)!=EOF)
		{
			if (strcmp(id,M.id)==0)
			{
			strcpy(N.nom,M.nom);
			strcpy(N.repas,M.repas);
			strcpy(N.date,M.date);	
			strcpy(N.entree,M.entree);
			strcpy(N.dessert,M.dessert);
			
			}
		}
return(N);
	
fclose(f);


}


}




int verif_w(char id[])
{

int trouve=-1;
wmenu M;
FILE *f=NULL;
f=fopen("menu.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",M.id,M.nom,M.repas,M.date,M.entree,M.dessert)!=EOF)
     {if (strcmp(id,M.id)==0)
         {trouve=1;
          break;}
     }

fclose(f);
}
return trouve;
}


void wafficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter *iter;
GtkListStore *store;


char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200],ch6[200];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",id,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("repas",renderer,"text",repas,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",date,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entree",renderer,"text",entree,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",dessert,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *a=NULL;
a=fopen("menu.txt","r");
if(a!=NULL)
{
a=fopen("menu.txt","a+");
while(fscanf(a,"%s %s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter, id,ch1,nom,ch2,repas,ch3,date,ch4,entree,ch5,dessert,ch6,-1);
}
fclose(a);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
void calculdechets(char dec,char rep)
{FILE *f=NULL;
f=fopen("dechets.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s  \n",rep,dec);
fclose(f);

}
}

wmenu wdechets()
{
    
    int j,t,jt,tt;
    float d,y,dt;
    wmenu m;
    y=100;
    
    FILE *f;
    f = fopen("dechets.txt","r");
    while(fscanf(f,"%d %d %f \n",&j,&t,&d) != EOF)
        if (y>d){
        y=d;

        dt=d;jt=j;tt=t;
        
                }
    

    m.dechets=dt;
    m.jour=jt;
    m.temps=tt;
    /*printf("jour %d temp %d dechet %f ",jt,tt,dt);*/
    fclose(f);
    return m;
}
	








