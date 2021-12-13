#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "capteur.h"

enum{
	EID,
	EDATE,
	ETYPE,
	EMARQUE,
	EBLOC,
	EETAGE,
	EVALMIN,
	EVALMAX,
	ECOLUMNS,
};

/* -------------------------- CRUD ---------------------------- */ 
void ajouter_capteur(capteur c){
    FILE *f;
    f = fopen("capteur.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,c.d.j,c.d.m,c.d.a,c.valMin,c.valMax);
    }
    fclose(f);
}

void modifier_capteur(capteur y){
    capteur c;
    FILE *f;
    FILE *g;
    f = fopen("capteur.txt","r");
    g = fopen("tmp.txt","a");
if(f != NULL && g != NULL){
    while(fscanf(f,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,&(c.d.j),&(c.d.m),&(c.d.a),&(c.valMin),&(c.valMax)) != EOF){
        if(strcmp(c.id,y.id) == 0){
           fprintf(g,"%s %s %s %s %s %d/%d/%d %f %f \n",y.id,y.type,y.marque,y.bloc,y.etage,y.d.j,y.d.m,y.d.a,y.valMin,y.valMax);
        }
        else{
            fprintf(g,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,c.d.j,c.d.m,c.d.a,c.valMin,c.valMax);
	        }
	    }
}
    fclose(f);
    fclose(g);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
}


void supprimer_capteur(char id[]){
    capteur c;
    FILE *f1;
    FILE *f2;
    f1 = fopen("capteur.txt","r");
    f2 = fopen("tmp.txt","a+");
    if(f1 != NULL && f2 != NULL){
        while(fscanf(f1,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,&(c.d.j),&(c.d.m),&(c.d.a),&(c.valMin),&(c.valMax)) != EOF){
        if(strcmp(c.id,id) != 0){
            fprintf(f2,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,c.d.j,c.d.m,c.d.a,c.valMin,c.valMax);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
    }
}

/* ----------------------------------------------------------------------------- */ 



void afficher_capteur(GtkWidget *liste,char *fname){
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char id[20],type[20],marque[20],bloc[20],etage[20];
    int j,m,a;
    float valMin,valMax;

char date[30],valMX[20],valMN[20];

    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);

    if(store == NULL){
   
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("   ID   ",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date D'installation",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",EMARQUE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Bloc",renderer,"text",EBLOC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",EETAGE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Valeur min",renderer,"text",EVALMIN,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Valeur Max",renderer,"text",EVALMAX,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %d/%d/%d %f %f \n",id,type,marque,bloc,etage,&(j),&(m),&(a),&(valMin),&(valMax)) != EOF){
			sprintf(valMN,"%.2f",valMin);
			sprintf(valMX,"%.2f",valMax);
			sprintf(date,"%d/%d/%d",j,m,a);          		
			gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EID,id,EDATE,date,ETYPE,type,EMARQUE,marque,EBLOC,bloc,EETAGE,etage,EVALMIN,valMN,EVALMAX,valMX,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}

/*------------------------------------------------------------------------ */ 
int idExiste(char id[]){
    capteur c;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,&(c.d.j),&(c.d.m),&(c.d.a),&(c.valMin),&(c.valMax)) != EOF){
        	if(strcmp(c.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;

}

/* ------------------------------------------------------------------------------ */ 

capteur chercher_capteur(char id[]){
	capteur c;
	FILE *f;
	f = fopen("capteur.txt","r");
	if(f != NULL){
    		while(fscanf(f,"%s %s %s %s %s %d/%d/%d %f %f 		\n",c.id,c.type,c.marque,c.bloc,c.etage,&(c.d.j),&(c.d.m),&(c.d.a),&(c.valMin),&(c.valMax)) != EOF){
        	if(strcmp(c.id,id) == 0){
       		     return c;
        	}
    	}
}
    fclose(f);
    return;	
}

/* ------------------------------------------------------------------------------ */ 

void ajouter_temperature(char id[],int j,int h,float valeur){
	FILE *f;
	f = fopen("temperature.txt","a");
	if(f != NULL){
		fprintf(f,"%s %d %d %f \n",id,j,h,valeur);
	}
	fclose(f);
	
}

/* --------------------------------------------------------- */ 

void list_id_capteur_defectueux(){

	char id[20];
	int j,h;
	float valeur;
	FILE *f,*g;
	f = fopen("temperature.txt","r");
	g = fopen("listIdDefct.txt","a");

	if(f != NULL && g != NULL){
		while(fscanf(f,"%s %d %d %f \n",id,&j,&h,&valeur) != EOF){
			if(idExiste(id)){
				float valMin,valMax;
				valMin = chercher_capteur(id).valMin;
				valMax = chercher_capteur(id).valMax;
				if((valeur < valMin) || (valeur > valMax)){
					if(isCapDefExiste(id) == 0){
						fprintf(g,"%s \n",id);
					}
				}
			}
		}
	}
	fclose(f);
	fclose(g);

}

/* --------------------------------------------------------- */ 


void capteur_defectueux(){
	FILE *f,*g,*h;
	char id[20];
	f = fopen("listIdDefct.txt","r");
	g = fopen("captDefectueux.txt","a");
	remove("captDefectueux.txt");
	fclose(g);
	h = fopen("captDefectueux.txt","a");

	if(f != NULL && g != NULL){
		while(fscanf(f,"%s \n",id) != EOF){
			if(idExiste(id)){
				 capteur c ; 
				strcpy(c.id,chercher_capteur(id).id);
				strcpy(c.type,chercher_capteur(id).type);
				strcpy(c.marque,chercher_capteur(id).marque);
				strcpy(c.bloc,chercher_capteur(id).bloc);
				strcpy(c.etage,chercher_capteur(id).etage);
				c.d.j = chercher_capteur(id).d.j;
				c.d.m = chercher_capteur(id).d.m;
				c.d.a = chercher_capteur(id).d.a;

				c.valMin = chercher_capteur(id).valMin;
				c.valMax = chercher_capteur(id).valMax;


				fprintf(h,"%s %s %s %s %s %d/%d/%d %f %f \n",c.id,c.type,c.marque,c.bloc,c.etage,c.d.j,c.d.m,c.d.a,c.valMin,c.valMax);
				
			
			}

		}
		
	}

	fclose(f);
	fclose(h);
}

/* --------------------------------------------------------- */ 
int isCapDefExiste(char id_d[]){
	FILE *f;	
	char id[20];

	f = fopen("listIdDefct.txt","r");	
	while(fscanf(f,"%s \n",id) != EOF){
		if(strcmp(id,id_d) == 0){
			return 1;
		}
	}
	fclose(f);

	return 0;
}

