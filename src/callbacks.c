#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "foyer.h"
#include"tree.h"
#include"CRUD.h"
#include "capteur.h"
#include "produit.h"
#include "fonctionmenu.h"


int x = 1, y=1;
GtkTreeSelection *selection1;

int choix[2]={0,0};
int choixm[2]={0,0};
int a;
int choixn;
utilisateur u;
int nb;
int choixx[]={0,0};
int choixmm[]={0,0};
produit p;


void
on_button_Ajout_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjoutUtilisateur;

AjoutUtilisateur = create_AjoutUtilisateur ();
gtk_widget_show (AjoutUtilisateur);
}




void
on_button_ajouter_submit_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*P,*MDP,*NU,*J,*M,*A,*R,*togglebutton3,*Niv,*pt,*pt1;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20],cin[20],ch[20],chc[20];

int j,m,a; char chj[6],chm[15],cha[6];
int test=0;

C=lookup_widget(objet,"entry_ajout_cin");
strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(C)));
N=lookup_widget(objet,"entry_ajout_nom");
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(N)));
P=lookup_widget(objet,"entry_ajout_prenom");
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(P)));
NU=lookup_widget(objet,"entry_ajout_login");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(NU)));
MDP=lookup_widget(objet,"entry_ajout_password");
strcpy(u.password,gtk_entry_get_text(GTK_ENTRY(MDP)));


J=lookup_widget(objet,"spinbutton1_jj"); 
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj,"%d",j);
M=lookup_widget(objet,"spinbutton1_mm"); 
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm,"%d",m);
A=lookup_widget(objet,"spinbutton1_aa"); 
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha,"%d",a);
strcpy(u.naissance.jour,gtk_entry_get_text(GTK_ENTRY(J)));
strcpy(u.naissance.mois,gtk_entry_get_text(GTK_ENTRY(M)));
strcpy(u.naissance.annee,gtk_entry_get_text(GTK_ENTRY(A)));

Niv=lookup_widget(objet,"entry_ajout_niveau");
strcpy(u.niveau,gtk_entry_get_text(GTK_ENTRY(Niv)));

R=lookup_widget(objet,"comboboxrole1");
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(R)));
pt = lookup_widget(objet,"label_ajouter_sortie");




if (choix[0]==0)
strcpy(u.sexe,"male");
else
strcpy(u.sexe,"female");

test=util_recherche(u.cin,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14,u.login);


if (strlen(u.cin)==0 || strlen(u.nom)==0 || strlen(u.prenom)==0 || strlen(u.login) == 0|| strlen(u.password)==0 ||strlen(u.role)==0) 
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Remplir tous les champs");
}
else
{
if (test==1)
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"CIN ou Nom d'utilisateur existe deja ");
}
else 
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Succees");
util_ajout(u,"utilisateurs.txt");
}
}
}


void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	choix[0]=0;
else
	choix[0]=1;

}




void
on_comboboxrole1_changed               (GtkComboBox     *objet,
                                        gpointer         user_data)
{
GtkWidget *togglebutton3,*T; 
char ch[20];

T=lookup_widget(objet,"comboboxrole1");
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T)));
togglebutton3=lookup_widget(objet,"checkbutton1_niv");
if (strcmp(u.role,"Etudiant")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), FALSE);


}


void
on_button_modifier_submit_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*P,*MDP,*NU,*J,*M,*A,*R,*togglebutton3,*Niv,*pt;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20],cin[20];

int j,m,a; char chj[6],chm[15],cha[6];

C=lookup_widget(objet,"entry_modif_cin");
strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(C)));
N=lookup_widget(objet,"entry_modif_nom");
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(N)));
P=lookup_widget(objet,"entry_modif_prenom");
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(P)));
NU=lookup_widget(objet,"entry_modif_login");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(NU)));
MDP=lookup_widget(objet,"entry_modif_password");
strcpy(u.password,gtk_entry_get_text(GTK_ENTRY(MDP)));
pt = lookup_widget(objet,"label_modifier_valider");


J=lookup_widget(objet,"spinbutton2_jj"); 
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj,"%d",j);
M=lookup_widget(objet,"spinbutton2_mm"); 
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm,"%d",m);
A=lookup_widget(objet,"spinbutton2_aa"); 
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha,"%d",a);
strcpy(u.naissance.jour,gtk_entry_get_text(GTK_ENTRY(J)));
strcpy(u.naissance.mois,gtk_entry_get_text(GTK_ENTRY(M)));
strcpy(u.naissance.annee,gtk_entry_get_text(GTK_ENTRY(A)));


R=lookup_widget(objet,"comboboxentry1");
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(R)));
if (strcmp(u.role,"Etudiant")==0)
{
Niv=lookup_widget(objet,"entry_modif_niveau");
strcpy(u.niveau,gtk_entry_get_text(GTK_ENTRY(Niv)));
}

if (choixm[0]==0)
strcpy(u.sexe,"male");
else
strcpy(u.sexe,"female");
if (util_recherche(u.cin,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14,"")==1)
{
pt = lookup_widget(objet,"label_modifier_valider");
gtk_label_set_text(GTK_LABEL(pt),"Success");
util_supprimer(u.cin);

util_ajout(u,"utilisateurs.txt");
}


}


void
on_button_modif_rechercher_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*P,*MDP,*NU,*J,*M,*A,*R,*Niv,*pt , *togglebutton3,*radiobuttonmale2,*radiobuttonfemale2;

int j,m,a; char chj[6],chm[15],cha[6];
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20],cin[20];
int i = 0;


C=lookup_widget(objet,"entry_modif_cin");
N=lookup_widget(objet,"entry_modif_nom");
P=lookup_widget(objet,"entry_modif_prenom");
NU=lookup_widget(objet,"entry_modif_login");
MDP=lookup_widget(objet,"entry_modif_password");
Niv=lookup_widget(objet,"entry_modif_niveau");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(C)));

if (util_recherche(cin,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14,"")==1)
{
gtk_entry_set_text(GTK_ENTRY(N),ch1);
gtk_entry_set_text(GTK_ENTRY(P),ch2);
gtk_entry_set_text(GTK_ENTRY(NU),ch8);
gtk_entry_set_text(GTK_ENTRY(MDP),ch9);
pt = lookup_widget(objet,"label_modifier_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Trouve");

J=lookup_widget(objet,"spinbutton2_jj"); 
j=atoi(ch4);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(J),j); 
M=lookup_widget(objet,"spinbutton2_mm");
m=atoi(ch5);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(M),m); 
A=lookup_widget(objet,"spinbutton2_aa");
a=atoi(ch6);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(A),a);


R=lookup_widget(objet,"comboboxentry1");
if (strcmp(ch7,"Administrateur")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),0);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}
else if (strcmp(ch7,"Etudiant")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),1);
gtk_entry_set_text(GTK_ENTRY(Niv),ch14);
}
else if (strcmp(ch7,"AgentDeRestaurant")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),2);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}
else if (strcmp(ch7,"AgentDeFoyer")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),3);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}
else if (strcmp(ch7,"Nutritionniste")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),4);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}
else if (strcmp(ch7,"Technicien")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),5);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}
else if (strcmp(ch7,"ServiceReclamation")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),6);
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}


radiobuttonmale2=lookup_widget (objet,"radiobuttonmale2");
radiobuttonfemale2=lookup_widget (objet,"radiobuttonfemale2");
if (strcmp(ch3,"male")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonmale2),TRUE);
else if (strcmp(ch3,"female")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonfemale2),TRUE);


}
else
{
pt = lookup_widget(objet,"label_modifier_sortie");
gtk_label_set_text(GTK_LABEL(pt),"CIN INEXISTANT");
if (strlen(cin)==0) 
{
pt = lookup_widget(objet,"label_modifier_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Remplir le CIN");

}
}


}

void
on_button_supprimer_submit_clicked     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *C ,*pt ;
char cin[20];
C=lookup_widget(objet_graphique,"entry_supprimer_cin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(C)));
if (util_supprimer(cin)==1)
{
pt=lookup_widget (objet_graphique ,"label_supprimer");
gtk_label_set_text(GTK_LABEL(pt),"Successsss");
}
else
{
pt=lookup_widget (objet_graphique ,"label_supprimer");
gtk_label_set_text(GTK_LABEL(pt),"Echoue");
}
}


void
on_radiobuttonmale2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	choixm[0]=0;
else
	choixm[0]=1;
}

void
on_comboboxentry1_changed              (GtkComboBox     *objet,
                                        gpointer         user_data)
{
GtkWidget *togglebutton3,*T,*Niv; 
char ch[20];

T=lookup_widget(objet,"comboboxentry1");
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T)));
togglebutton3=lookup_widget(objet,"checkbutton2_niv");
if (strcmp(u.role,"Etudiant")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), TRUE);
else
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), FALSE);
Niv=lookup_widget(objet,"entry_modif_niveau");
gtk_entry_set_text(GTK_ENTRY(Niv), "");
}


}

void
on_button_affichage_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *E_treeview,*window_Database;

window_Database=create_database_utilisateurs();
gtk_widget_show (window_Database);
E_treeview=lookup_widget(window_Database,"E_treeview");
util_afficher(E_treeview);
}





void
on_button_niveau_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Niv,*E_treeview,*w1,*window_etudiants,*pt,*objet,*nombre_etudiants;
char niv[20];
char ch[20];
char ch1[20];
w1=lookup_widget(objet_graphique,"database_e");
window_etudiants=create_database_e();
gtk_widget_show (window_etudiants);
gtk_widget_hide(w1);
E_treeview=lookup_widget(window_etudiants,"Etudiant_treeview");
vider(E_treeview);
Niv=lookup_widget(objet_graphique,"entry_afficher_niveau");
strcpy(niv,gtk_entry_get_text(GTK_ENTRY(Niv)));
nb=E_afficher(E_treeview,niv);


}


void
on_button_calculer_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *pt;
char ch[20],ch1[20];
sprintf(ch,"%d",nb);
sprintf(ch1," Etudiants ");
pt=lookup_widget (objet_graphique ,"label_etudiants");
gtk_label_set_text(GTK_LABEL(pt),strcat(ch,ch1));
}






void
on_button_login_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_button_Modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_modifier;
  window_modifier = create_Modifier ();
  gtk_widget_show (window_modifier);
}


void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_Supprimer;
  window_Supprimer = create_Supprimer ();
  gtk_widget_show (window_Supprimer);
}


void
on_button_Etudiants_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *E_treeview,*window_etudiants,*Niv,*pt;
char niv[20];

window_etudiants=create_database_e();
gtk_widget_show (window_etudiants);
E_treeview=lookup_widget(window_etudiants,"Etudiant_treeview");
E_afficher(E_treeview,niv);
}


void
on_button_autres_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_autre;
  window_autre = create_window_taches ();
  gtk_widget_show (window_autre);
}


void
on_E_treeview_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* cin;
gchar* nom;
gchar* prenom;
gchar* login;
gchar* mdp;
gchar* dn;
gchar* sexe;
gchar* role;

GtkWidget* window_modif,*pt;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);


if (gtk_tree_model_get_iter(model, &iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom, 2,&prenom, 3,&login,4,&mdp,5,&dn,6,&role,7,&sexe,-1);

window_modif=create_Modifier();
gtk_widget_show(window_modif);

    
pt=lookup_widget(window_modif,"entry_modif_cin");
gtk_entry_set_text(GTK_ENTRY(pt),cin);


}
}


void
on_button_login_admin_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
FILE* f;
char ch[70],ch1[20],ch2[20]; int test; char role[20];
 GtkWidget* id,*mdp,*window0,*window1,*pt;

id=lookup_widget(objet,"entry_admin_login");
mdp=lookup_widget(objet,"entry_admin_mdp");
pt=lookup_widget(objet,"label_sortie_auth_admin");
 strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(id)));
    strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(mdp)));


test=auth_admin(ch1,ch2,role);
	sprintf(ch,"%d",test);
 gtk_label_set_text(GTK_LABEL(pt),ch);
	
 if (strcmp(role,"Administrateur")==0)
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  
  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_EspaceAdmin ();
		gtk_widget_show(window1);	
		}

else if (strcmp(role,"Etudiant")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_Modifier ();
		gtk_widget_show(window1);	
		}
}
else if (strcmp(role,"AgentDeFoyer")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_Gestion_foyer ();
		gtk_widget_show(window1);	
		}
}
else if (strcmp(role,"Nutritionniste")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_page_d_accueil ();
		gtk_widget_show(window1);	
		}
}
else if (strcmp(role,"AgentDeRestaurant")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_Ajouter_produit ();
		gtk_widget_show(window1);	
		}

}
else if (strcmp(role,"Technicien")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_Accueil ();
		gtk_widget_show(window1);	
		}
}

else if (strcmp(role,"SeviceReclamation")==0)
{
if( strlen(ch1)==0 || strlen(ch2)==0 )
	

	{

	sprintf(ch,"ERREUR: veuillez remplir tous les champs.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
  

  else if (test==0)
	{
		sprintf(ch,"ERREUR: Veuillez réessayer de nouveau.");
			    gtk_label_set_text(GTK_LABEL(pt),ch);
	}
	   else
		{ 
		window0=lookup_widget(objet,"window_login");
		gtk_widget_destroy(window0);


	
		window1=create_Accueil ();
		gtk_widget_show(window1);	
		}

}
}


void
on_button_exit_admin_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget* window0=lookup_widget(objet,"window_login");
gtk_widget_destroy(window0);
}
//////////////////////////////////////////gestion de foyer////////////////////////////////////////////////////////////////////////////////////

int xg;
int tg[4]={0,0,0,0};
int xgg;
int tgg[4]={0,0,0,0};
int xy[]={0,0,0,0},sy;




void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelsexe,*labelcin,*labelnt,*labelmail;
foyer o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
int b=1;
No = lookup_widget (objet,"entry10");
Pr = lookup_widget (objet,"entry11");
ci = lookup_widget (objet,"entry12");
Am = lookup_widget (objet,"entry14");
Nt = lookup_widget (objet,"entry13");
jour = lookup_widget (objet,"spinbutton2");
mois = lookup_widget (objet,"spinbutton3");
annee = lookup_widget (objet,"spinbutton4");
se = lookup_widget (objet,"combobox6");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.chambre,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
labelnom=lookup_widget(objet,"label333");
labelprenom=lookup_widget(objet,"label334");
labelsexe=lookup_widget(objet,"label335");
labelcin=lookup_widget(objet,"label336");
labelnt=lookup_widget(objet,"label337");
labelmail=lookup_widget(objet,"label338");




// 
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.chambre,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.Mail,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"saisir chambre !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"");
}
if(b==1){
Ajouter_ch( o);
}

//
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"foyer.txt");



}


void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char sexe[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char chambre[20];
char Mail[20];
lb = lookup_widget (objet,"label332");
dd = lookup_widget (objet,"entry15");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("foyer.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,sexe,CIN,chambre,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");
}

//
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"foyer.txt");
}


void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *dd,*Nm,*Pnom,*cin,*SEXE,*Jour,*Mois,*Num,*Annee,*mail,*lb;

char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char CIN[20];
char chambre[20];
char jour[20];
char mois[20];
char annee[20];
char Mail[20];
char idd[20];
foyer o ;
int x=-1;
FILE *F;

dd = lookup_widget (button,"entry16");
Nm = lookup_widget(button, "entry17");
Pnom = lookup_widget(button, "entry18");
SEXE = lookup_widget(button, "label355");
cin = lookup_widget (button,"entry19");
Num = lookup_widget(button, "entry20");
Jour = lookup_widget(button, "spinbutton6");
Mois = lookup_widget(button, "spinbutton6");
Annee = lookup_widget(button, "spinbutton7");
mail = lookup_widget(button, "entry21");
lb = lookup_widget(button, "label354");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("foyer.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,sexe,CIN,chambre,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(SEXE),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(Num),"");
gtk_entry_set_text(GTK_LABEL(mail),"");
}else
{
     o = rechercher_foyer(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");/* code */


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(SEXE),o.sexe);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(Num),o.chambre);
gtk_entry_set_text(GTK_LABEL(mail),o.Mail);


}

}


void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
foyer o;
char id[20];


dd = lookup_widget (objet_graphique,"entry16");
no = lookup_widget (objet_graphique,"entry17");
pr = lookup_widget (objet_graphique,"entry18");
se = lookup_widget (objet_graphique,"combobox7");
ci = lookup_widget (objet_graphique,"entry19");
nt = lookup_widget (objet_graphique,"entry20");
jour = lookup_widget (objet_graphique,"spinbutton5");
mois = lookup_widget (objet_graphique,"spinbutton6");
annee = lookup_widget (objet_graphique,"spinbutton7");
am = lookup_widget (objet_graphique,"entry21");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.chambre,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(am)));
modi_ch(id,o);

//
 GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
affi_ch(p,"foyer.txt");
}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *Mail;
        gchar *chambre;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;


        gchar *id;//
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&sexe,4,&CIN,5,&chambre,6,&jour,7,&mois,8,&annee,9,&Mail,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry16")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry17")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry18")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry19")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry20")),chambre);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry21")),Mail);

	
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook3")));



labe = lookup_widget(objet_graphique, "label355");
gtk_label_set_text(GTK_LABEL(labe),sexe);




         
}
//

affi_ch(p,"foyer.txt");
}







void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview5");;
        
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

            supp_ch( id);
}

}
int x;
int t[2]={0,0};

void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 

}


void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 


}


void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    

}


void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}  

}


void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" Affecté ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Bloc Fille ");
 else  
strcpy(ch2," Bloc Homme ");
 if (t[0]==1)
 strcat(ch3," Groupe femme "); 
if(t[1]==1)
 strcat (ch3,"  Groupe homme");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(objet, "label356");

gtk_label_set_text(GTK_LABEL(output),ch3);





}


void
on_button7_quiter_ouv_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{



}





void
on_buttonINST_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_buttonFB_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/esprit.tn");
}


void
on_button56_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *message;

char jour[20];
char heure [20];
char type [20];
int temp;
      

  foyer c;
  
   FILE *F, *FW;
  
  
F = fopen ("fumee.txt", "r");
FW = fopen ("fumeeR.txt", "w");


  if ((F!=NULL)&&(FW!=NULL))
 {


    while(fscanf(F,"%s %s %s %d \n",jour,heure,type,&temp)!=EOF)
    if ((temp==1))
     {
	fprintf (FW, "%s %s %s %d \n",jour,heure,type,temp);

     }


  fclose (F);
  fclose (FW);

 GtkWidget* p=lookup_widget(objet,"treeview6");
affi_ad_ch(p,"fumeeR.txt");
}
}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button57_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *message;

char jour[20];
char heure [20];
char type [20];
int temp;
      

  foyer c;
  
   FILE *F, *FW;
  
  
F = fopen ("mouvement.txt", "r");
FW = fopen ("mv.txt", "w");


  if ((F!=NULL)&&(FW!=NULL))
 {


    while(fscanf(F,"%s %s %s %d \n",jour,heure,type,&temp)!=EOF)
    if ((temp==1)&&(1<heure<6))
     {
	fprintf (FW, "%s %s %s %d \n",jour,heure,type,temp);

     }

     

     
     

  fclose (F);
  fclose (FW);

 GtkWidget* p=lookup_widget(objet,"treeview6");
affi_ad_ch(p,"mv.txt");
}
}


void
on_buttonMaps_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.google.com/maps/place/Esprit+Pr%C3%A9pa/@36.8992878,10.1871734,17z/data=!3m1!4b1!4m5!3m4!1s0x12e2cb7454c6ed51:0x683b3ab5565cd357!8m2!3d36.8992878!4d10.1893674");
}


///////////////////////////////////gestion des reclamations////////////////////////////////////


void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *pu;
gtk_widget_hide (acceuilw);
gestionw = create_gestionw ();
pu=lookup_widget(gestionw,"treeview2w");
Afficherreclamation(pu,"reclamation.txt");
gtk_widget_show (gestionw);
}


void
on_Ajouterreclamation_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 reclamation t;
GtkWidget *entryservicew;
GtkWidget *entryIdw;
GtkWidget *entrynumerochambrew;

GtkWidget *entrynometprenomw;
GtkWidget *labelIdw;
GtkWidget *labelservicew;
GtkWidget *labelnumerochambrew;
GtkWidget *labelDatew;
GtkWidget *labelnometprenomw;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
GtkWidget *entryreclamation;
GtkWidget *labelreclamation;
int b=1;
int jj1,mm1,aa1;

FILE*f=NULL;


entryIdw=lookup_widget(gestionw,"entry5w");
entryservicew=lookup_widget(gestionw,"combobox1w");
entrynumerochambrew=lookup_widget(gestionw,"combobox2w");
entryreclamation=lookup_widget(gestionw,"entryreclamation");


entrynometprenomw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelservicew=lookup_widget(gestionw,"label7w");
labelnumerochambrew=lookup_widget(gestionw,"label8w");


labelreclamation=lookup_widget(gestionw,"labellabel");


labelnometprenomw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");
successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(t.cin,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) );
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryservicew)));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynumerochambrew)));

        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(entrynometprenomw) ) );
        strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(entryreclamation) ) );
 gtk_widget_hide (successw);

 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);
 gtk_widget_hide (successw);



if(strcmp(t.cin,"")==0){
		  gtk_widget_show (labelIdw);
b=0;
}
else {
		  gtk_widget_hide(labelIdw);
}

if(strcmp(t.service,"")==0){
		  gtk_widget_show (labelservicew);
b=0;
}
else {
		  gtk_widget_hide(labelservicew);
}
if(strcmp(t.numerochambre,"")==0){
		  gtk_widget_show (labelnumerochambrew);
b=0;
}
else {
		  gtk_widget_hide(labelnumerochambrew);
}

if(strcmp(t.nometprenom,"")==0){
		  gtk_widget_show (labelnometprenomw);
b=0;
}
else {
		  gtk_widget_hide(labelnometprenomw);
}

if(strcmp(t.reclamation,"")==0){
		  gtk_widget_show (labelreclamation);
b=0;
}
else {
		  gtk_widget_hide(labelreclamation);
}


if(b==1){

        if(exist_reclamation(t.cin)==1)
        {

				  gtk_widget_show (existew);
                }
                else {
                     gtk_widget_hide (existew);

       f=fopen("reclamation.txt","a+");

fprintf(f,"%s %s %s  %d/%d/%d %s %s\n",t.cin,t.service,t.numerochambre, jj1,mm1+1,aa1 ,t.nometprenom,t.reclamation);
fclose(f);
     

                  gtk_widget_show (successw);



      GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherreclamation(p,"reclamation.txt");
}

}
}



void
on_Modifierreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 reclamation t;

        strcpy(t.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));
	strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec"))));
        supprimer_reclamation(t.cin);
        ajouter_reclamation(t);
 
        Afficherreclamation(lookup_widget(gestionw,"treeview1"),"reclamation.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}





void
on_chercherreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char cin[30];
char chnb[30];
int b=0,nb;  
entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(cin,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherreclamation(p1w,"reclamation.txt",cin);

 

sprintf(chnb,"%d",nb);        
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);
}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pu;
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

 Afficherreclamation(pu,"reclamation.txt");

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);//recuperer les information de la ligne selectionneé
        // //remplir les champs de entry
               
   //gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox3w")),service);
                //gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox4w")),numerochambre);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nometprenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec")),reclamation);
                GtkWidget* msgId=lookup_widget(gestionw,"label20w");
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_label_set_text(GTK_LABEL(msgId),cin);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w")); //afficher le bouton modifier
		GtkTreeSelection *selection1;
              //  gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));//redirection vers la page precedente
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                
             
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *cin;
    gchar *service;
    gchar *numerochambre;
    gchar *date;
    gchar *nometprenom;
    gchar *reclamation;
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);//recuperer les information de la ligne selectionneé
            supprimer_reclamation(cin);
            Afficherreclamation(lookup_widget(gestionw,"treeview2w"),"reclamation.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    	gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}










void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *b;
int nbr=0,nbh=0 ;
FILE*f=NULL;
reclamation t;
char max[30];



f=fopen("reclamation.txt","r");// ouverture du fichier reclamation en  mode lecture 

while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
	{
		if(strcmp(t.service,"restauration")==0)
		nbr++;
		else
		nbh++;
	}
fclose(f);

if (nbr>nbh)
strcpy(max,"restauration");
else
strcpy(max,"hebergement");



b=lookup_widget (button,"label_service_tache_2");
gtk_label_set_text(GTK_LABEL(b),max);



}


void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_hide (acceuilw);
dialog_service_partie_2 = create_dialog_service_partie_2 ();
gtk_widget_show (dialog_service_partie_2);
}



/////////////////gestion des capteurs///////////////////////



/* ------------------ NAVIGATION ACCUEIL -------------------- */ 
void
on_toListCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_listCap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
	GtkWidget *treeview;	
	treeview = lookup_widget(window2,"treeListCap");
		
	afficher_capteur(treeview,"capteur.txt");

}


void
on_toAddCap_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_addCap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

/*
void
on_toEditCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_editCap();
  	gtk_widget_show (window2);
	gtk_widget_hide(window1);
	

}


*/
void
test_clicked                           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_editCap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

void
on_toDelCap_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_delCap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_toCapDef_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview ;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_defCap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

	treeview = lookup_widget(window2,"treeviewCapDef");
	list_id_capteur_defectueux();	
	capteur_defectueux();
	afficher_capteur(treeview,"captDefectueux.txt");
}

void
on_toFicheTemp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Accueil");
	window2 = create_ficheVal();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}



void
on_toCapAlar_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
}
/* -------------------------------------------------------------------- */ 


/* ------------  	BACK BUTTON	  ---------------------------*/

void
on_backAdd_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"addCap");
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

void
on_backEdit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window2;
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	
}


void
on_backListCap_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"listCap");
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_backDel_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"delCap");
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

void
on_backCapDef_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"defCap");
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_backFiche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"ficheVal");
	window2 = create_Accueil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

/*-----------------------------------------------------------------

 */ 
void
on_btnAddCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*j,*m,*a;
	GtkWidget *output;
	char message[200];


	char min[20],max[20];
	capteur c;
	input1 = lookup_widget(objet,"idAdd");
	input2 = lookup_widget(objet,"comboboxMarqA");
	input3 = lookup_widget(objet,"valMinA");
	input4 = lookup_widget(objet,"valMaxA");
	input5 = lookup_widget(objet,"blocA");
	input6 = lookup_widget(objet,"etageA");
	j = lookup_widget(objet,"spinJA");
	m = lookup_widget(objet,"spinMA");
	a = lookup_widget(objet,"spinAA");

	if (x == 1){
		strcpy(c.type,"temperature");
	}
	else if(x == 2){
		strcpy(c.type,"mouvement");
	}
	else if(x == 3){
		strcpy(c.type,"eau");
	}
	else{
		strcpy(c.type,"fumee");
	}

	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
	

	strcpy(min,gtk_entry_get_text(GTK_ENTRY(input3)));
	c.valMin = (float) atoll(min);
	strcpy(max,gtk_entry_get_text(GTK_ENTRY(input4)));
	c.valMax = (float) atoll(max);

	c.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	c.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	c.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
	
	strcpy(c.bloc,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(c.etage,gtk_entry_get_text(GTK_ENTRY(input6)));


	output = lookup_widget(objet,"outputAdd");
	if(idExiste(c.id) == 1){
		
		sprintf(message,"ID Déja existe");		
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Votre ajout à été effectué avec succés !");		
		gtk_label_set_text(GTK_LABEL(output),message);
		ajouter_capteur(c);
	}


}


void
on_radioTemp_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x = 1;
    	}
}


void
on_radioMouve_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x = 2;
    	}
}


void
on_radioEau_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x = 3;
    	}
}


void
on_radioFumee_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x = 4;
    	}
}

/* ------------------------------------------------------- */ 



/* ------------ BUTTON DELETE ------------------- */ 

void
on_btnDelete_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *id, *output ;
	
	char identifiant[20];
	char message[200];

	
	id = lookup_widget(objet,"idDel");
	output = lookup_widget(objet,"outputDel");

	strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
	if(idExiste(identifiant)){
		sprintf(message,"Votre suppression à été effectué avec succés !");		
		gtk_label_set_text(GTK_LABEL(output),message);
		supprimer_capteur(identifiant);	
	}
	else{
		sprintf(message,"ID non existant ! ");		
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}

/* -------------------------------------------------------- */

/* ----------- MAQUETTE MODIFICATION ------------------- */ 
void
on_btnConsult_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*j,*m,*a;
	GtkWidget *mouv,*eau,*fumee;
	char id[20],message[200];
	
	input1 = lookup_widget(objet,"idEdit");
	output = lookup_widget(objet,"outputEdit");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(idExiste(id) == 0){
		sprintf(message,"ID non existant ! ");		
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		capteur c ;
		capteur y ; 
		
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

		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");		
		gtk_label_set_text(GTK_LABEL(output),message);
		


		input2 = lookup_widget(objet,"comboMarqueE");
		input3 = lookup_widget(objet,"valMinE");
		input4 = lookup_widget(objet,"valMaxE");
		input5 = lookup_widget(objet,"blocE");
		input6 = lookup_widget(objet,"etageE");


		mouv = lookup_widget(objet,"radioMouvE");
		eau = lookup_widget(objet,"radioEauE");
		fumee = lookup_widget(objet,"radioFumeeE");

		j = lookup_widget(objet,"spinJE");
		m = lookup_widget(objet,"spinME");
		a = lookup_widget(objet,"spinAE");
		
		/* -------- SET COMBO_BOX VALUE ------- */ 
		if(strcmp(c.marque,"M1") == 0){
			gtk_combo_box_set_active(input2,0);
		}
		else if(strcmp(c.marque,"M2") == 0){
			gtk_combo_box_set_active(input2,1);
		}
		else if(strcmp(c.marque,"M3") == 0){
			gtk_combo_box_set_active(input2,2);
		}
		else if(strcmp(c.marque,"M4") == 0){
			gtk_combo_box_set_active(input2,3);
		}
		else{
			gtk_combo_box_set_active(input2,4);
		}
		
		/* --------- SET RADIO BUTTON VALUE ------------ */ 

		if(strcmp(c.type,"mouvement") == 0){	
			gtk_toggle_button_set_active (mouv,"TRUE");
		}
		else if(strcmp(c.type,"eau") == 0){
			gtk_toggle_button_set_active (eau,"TRUE");
		}
		else if(strcmp(c.type,"fumee") == 0){
			gtk_toggle_button_set_active (fumee,"TRUE");
		}



		/*	----------------------------	*/
		char valMin[20],valMax[20],bloc[20],etage[20];
		
		sprintf(valMin,"%f",c.valMin);
		gtk_entry_set_text(GTK_ENTRY(input3),valMin);

		sprintf(valMax,"%f",c.valMax);
		gtk_entry_set_text(GTK_ENTRY(input4),valMax);


		sprintf(bloc,"%s",c.bloc);
		gtk_entry_set_text(GTK_ENTRY(input5),bloc);

		sprintf(etage,"%s",c.etage);
		gtk_entry_set_text(GTK_ENTRY(input6),etage);

		gtk_spin_button_set_value(j,c.d.j);
		gtk_spin_button_set_value(m,c.d.m);
		gtk_spin_button_set_value(a,c.d.a);

		


	}
	
}

void
on_radioTempE_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y = 1;
    	}
}


void
on_radioMouvE_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y = 2;
    	}
}


void
on_radioEauE_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y = 3;
    	}
}


void
on_radioFumeeE_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y = 4;
    	}
}

void
on_saveEdit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*j,*m,*a;
	GtkWidget *output;
	char message[200];


	char min[20],max[20];
	capteur c;
	input1 = lookup_widget(objet,"idEdit");
	input2 = lookup_widget(objet,"comboMarqueE");
	input3 = lookup_widget(objet,"valMinE");
	input4 = lookup_widget(objet,"valMaxE");
	input5 = lookup_widget(objet,"blocE");
	input6 = lookup_widget(objet,"etageE");
	j = lookup_widget(objet,"spinJE");
	m = lookup_widget(objet,"spinME");
	a = lookup_widget(objet,"spinAE");

	if (y == 1){
		strcpy(c.type,"temperature");
	}
	else if(y == 2){
		strcpy(c.type,"mouvement");
	}
	else if(y == 3){
		strcpy(c.type,"eau");
	}
	else{
		strcpy(c.type,"fumee");
	}

	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
	

	strcpy(min,gtk_entry_get_text(GTK_ENTRY(input3)));
	c.valMin = (float) atoll(min);
	strcpy(max,gtk_entry_get_text(GTK_ENTRY(input4)));
	c.valMax = (float) atoll(max);

	c.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	c.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	c.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
	
	strcpy(c.bloc,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(c.etage,gtk_entry_get_text(GTK_ENTRY(input6)));


	output = lookup_widget(objet,"outputEdit");
	if(!idExiste(c.id)){
		
		sprintf(message,"ID non existant");		
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Votre modification à été effectué avec succés !");		
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_capteur(c);
	}

}

/* -------------------------------------------------------- */



void
on_treeListCap_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_sauvegardeTemp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*input2,*input3; 
	int j,m,a;
	GtkWidget *calendar;
	GtkWidget *output;

	char id[20],val[20];
	int h;
	float valeur;
	char message[200];


	input1 = lookup_widget(objet,"id_fiche");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));


	input2 = lookup_widget(objet,"spinHeure");
	input3 = lookup_widget(objet,"valFiche");
	calendar = lookup_widget(objet,"calendarTemp");
	output = lookup_widget(objet,"outputTemp");

	if(idExiste(id)){
		if(strcmp(chercher_capteur(id).type,"temperature") == 0){
			h = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
			gtk_calendar_get_date(GTK_CALENDAR(calendar),&a,&m,&j);			
			
			strcpy(val,gtk_entry_get_text(GTK_ENTRY(input3)));
			valeur = (float) atoll(val);
			ajouter_temperature(id,j,h,valeur);
			sprintf(message,"Votre sauvegared a été effectué avec succés !");		
			gtk_label_set_text(GTK_LABEL(output),message);
			}
		
		else{
			sprintf(message,"Le capteur avec L'id %s n'est pas un capteur \n\tdu temperature ! ",id);		
			gtk_label_set_text(GTK_LABEL(output),message);
		}
	}
	else{
		sprintf(message,"ID non existant");		
		gtk_label_set_text(GTK_LABEL(output),message);
	}

}



void
on_ajouterclicked_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*P,*J,*M,*A,*J1,*M1,*A1,*R,*togglebutton3,*Niv,*pt,*pt1;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20],ref[20],ch[20],chc[20];

int j,m,a; char chj[6],chm[15],cha[6];
int j1,m1,a1; char chj1[6],chm1[15],cha1[6];
int test=0 ;
N=lookup_widget(objet,"entry13ref");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(N)));

C=lookup_widget(objet,"entry6nom");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(C)));

P=lookup_widget(objet,"entry15quantite");
strcpy(p.Quantite,gtk_entry_get_text(GTK_ENTRY(P)));


J=lookup_widget(objet,"jour_spinbouton"); 
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj,"%d",j);
M=lookup_widget(objet,"mois_spinbouton"); 
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm,"%d",m);
A=lookup_widget(objet,"anne_spinbouton"); 
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha,"%d",a);
strcpy(p.Date_achat.jour,gtk_entry_get_text(GTK_ENTRY(J)));
strcpy(p.Date_achat.mois,gtk_entry_get_text(GTK_ENTRY(M)));
strcpy(p.Date_achat.annee,gtk_entry_get_text(GTK_ENTRY(A)));

J1=lookup_widget(objet,"jour1_spinbouton"); 
j1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj1,"%d",j1);
M1=lookup_widget(objet,"mois1_spinbouton"); 
m1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm1,"%d",m1);
A1=lookup_widget(objet,"anne1_spinbouton"); 
a1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha1,"%d",a1);
strcpy(p.Date_expiration.jour,gtk_entry_get_text(GTK_ENTRY(J1)));
strcpy(p.Date_expiration.mois,gtk_entry_get_text(GTK_ENTRY(M1)));
strcpy(p.Date_expiration.annee,gtk_entry_get_text(GTK_ENTRY(A1)));


R=lookup_widget(objet,"combobox1ajouter");
strcpy(p.poids,gtk_combo_box_get_active_text(GTK_COMBO_BOX(R)));
pt = lookup_widget(objet,"label_ajouter_sortie");





if (choixx[0]==0)
strcpy(p.Type,"Nourriture");
else 
strcpy(p.Type,"Outils_de_cuisine");

test=produit_recherche(p.ref,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14);
if (strlen(p.ref)==0 || strlen(p.nom)==0 || strlen(p.poids)==0 ||strlen(p.Quantite)==0) 
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Remplir tous les champs");
}
else
{
if (test==1)
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Referance existe deja ");
}
else 
{
pt = lookup_widget(objet,"label_ajouter_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Succees");
produit_ajout(p,"produit.txt");
}
}
}


void
on_Ajouter_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter;

Ajouter = create_Ajouter_produit ();
gtk_widget_show (Ajouter);
}


void
on_Modifier_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier;

Modifier = create_Modifier_produit ();
gtk_widget_show (Modifier);
}


void
on_Supprimer_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer;

 Supprimer = create_Supprimer_produit ();
 gtk_widget_show (Supprimer);
}


void
on_button_rupture_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview2,*window_Database;

window_Database=create_Repture_Stock();
gtk_widget_show (window_Database);
treeview2=lookup_widget(window_Database,"treeview2");
Afficher(treeview2);
}


void
on_Affichage_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*window_database;

window_database=create_Affichage_produit();
gtk_widget_show (window_database);
treeview1=lookup_widget(window_database,"treeview1");
Afficher(treeview1);
}


void
on_Nourriture_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	choixx[0]=0;
else
	choixx[0]=1;
}


void
on_Nettoyage_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}




void
on_combobox1ajouter_changed            (GtkComboBox     *objet,
                                        gpointer         user_data)
{
GtkWidget *togglebutton3,*T; 
char ch[20];

T=lookup_widget(objet,"combobox1ajouter");
strcpy(p.poids,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T)));
togglebutton3=lookup_widget(objet,"Quantite");
if (strcmp(p.poids,"0")!=0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), FALSE);

}


void
on_validermodif_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*P,*J,*M,*A,*J1,*M1,*A1,*R,*togglebutton3,*Niv,*pt;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20],ref[20];

int j,m,a; char chj[6],chm[15],cha[6];
int j1,m1,a1; char chj1[6],chm1[15],cha1[6];

N=lookup_widget(objet,"entry14");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(N)));

C=lookup_widget(objet,"entry7");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(C)));

P=lookup_widget(objet,"entry16");
strcpy(p.Quantite,gtk_entry_get_text(GTK_ENTRY(P)));
pt = lookup_widget(objet,"label_modifier_valider");


J=lookup_widget(objet,"jour2_spinbouton"); 
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj,"%d",j);
M=lookup_widget(objet,"jour2_spinbouton"); 
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm,"%d",m);
A=lookup_widget(objet,"annee2_spinbouton"); 
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha,"%d",a);
strcpy(p.Date_achat.jour,gtk_entry_get_text(GTK_ENTRY(J)));
strcpy(p.Date_achat.mois,gtk_entry_get_text(GTK_ENTRY(M)));
strcpy(p.Date_achat.annee,gtk_entry_get_text(GTK_ENTRY(A)));

J1=lookup_widget(objet,"jour3_spinbouton"); 
j1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(J)); sprintf(chj1,"%d",j1);
M1=lookup_widget(objet,"mois3_spinbouton"); 
m1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm1,"%d",m1);
A1=lookup_widget(objet,"annee3_spinbouton"); 
a1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha1,"%d",a1);
strcpy(p.Date_expiration.jour,gtk_entry_get_text(GTK_ENTRY(J1)));
strcpy(p.Date_expiration.mois,gtk_entry_get_text(GTK_ENTRY(M1)));
strcpy(p.Date_expiration.annee,gtk_entry_get_text(GTK_ENTRY(A1)));


R=lookup_widget(objet,"combobox2modifier");
strcpy(p.poids,gtk_combo_box_get_active_text(GTK_COMBO_BOX(R)));




if (choixx[0]==0)
strcpy(p.Type,"Nourriture");
else 
strcpy(p.Type,"Outils_de_cuisine");
if (produit_recherche(p.ref,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14)==1)
{
pt = lookup_widget(objet,"label_modifier_valider");
gtk_label_set_text(GTK_LABEL(pt),"Success");
prd_supprimer(p.ref);
produit_ajout(p,"produit.txt");
}
}


void
on_modif_Rechercher_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *C,*N,*p,*NU,*J,*M,*A,*J1,*M1,*A1,*R,*Niv,*pt,*togglebutton3,*Nourriture1,*Nettoyage1,*Outils_de_cuisine1;

int j,m,a; char chj[6],chm[15],cha[6];
int j1,m1,a1; char chj1[6],chm1[15],cha1[6];
char ref[20],ch10[20],ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20],ch9[20],ch0[20],ch14[20];
int i = 0;
C=lookup_widget(objet,"entry14");
N=lookup_widget(objet,"entry7");

p=lookup_widget(objet,"entry16");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(C)));

if (produit_recherche(ref,ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch14)==1)
{
gtk_entry_set_text(GTK_ENTRY(N),ch1);
pt = lookup_widget(objet,"label_modifier_sortie");
J=lookup_widget(objet,"jour2_spinbouton"); 
j=atoi(ch4);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(J),j); 
M=lookup_widget(objet,"mois2_spinbouton");
m=atoi(ch5);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(M),m); 
A=lookup_widget(objet,"annee2_spinbouton");
a=atoi(ch6);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(A),a);

J1=lookup_widget(objet,"jour3_spinbouton"); 
j1=atoi(ch7);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(J1),j1); 
M1=lookup_widget(objet,"mois3_spinbouton");
m1=atoi(ch8);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(M1),m1); 
A1=lookup_widget(objet,"annee3_spinbouton");
a1=atoi(ch9);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(A1),a1);


R=lookup_widget(objet,"combobox2modifier");
if (strcmp(ch2,"0")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),0);
gtk_entry_set_text(GTK_ENTRY(p), "");
}
else if (strcmp(ch2,"1-->10kg")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),1);
gtk_entry_set_text(GTK_ENTRY(p),ch3);
}
else if (strcmp(ch2,"10-->20kg")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),2);
gtk_entry_set_text(GTK_ENTRY(p),ch3);
}
else if (strcmp(ch2,"30-->40kg")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),3);
gtk_entry_set_text(GTK_ENTRY(p),ch3);
}
else if (strcmp(ch2,"50-->60kg")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(R),4);
gtk_entry_set_text(GTK_ENTRY(p),ch3);
}




Nourriture1=lookup_widget (objet,"Nourriture1");
Outils_de_cuisine1=lookup_widget (objet,"Outils_de_cuisine1");


if (strcmp(ch14,"Nourriture")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(Nourriture1),TRUE);

else if (strcmp(ch14,"Outils de cuisine")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(Outils_de_cuisine1),TRUE);

}
else
{
pt = lookup_widget(objet,"label_modifier_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Reférence INEXISTANT");
if (strlen(ref)==0) 
{
pt = lookup_widget(objet,"label_modifier_sortie");
gtk_label_set_text(GTK_LABEL(pt),"Remplir la Référance");

}
}
}


void
on_combobox2modifier_changed           (GtkComboBox     *objet,
                                        gpointer         user_data)
{
GtkWidget *togglebutton3,*T,*k; 
char ch[20];

T=lookup_widget(objet,"combobox2modifier");
strcpy(p.poids,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T)));
togglebutton3=lookup_widget(objet,"Quantite2");
if (strcmp(p.poids,"0")!=0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), TRUE);
else
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (togglebutton3), FALSE);
k=lookup_widget(objet,"entry16");
gtk_entry_set_text(GTK_ENTRY(k), "");
}
}









void
on_Nourriture1_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	choixmm[0]=0;
else
	choixmm[0]=1;

}


void
on_Quantite2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_supressionvalider_clicked           (GtkButton  *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *C,*pt ;
char ref[20];
C=lookup_widget(objet_graphique,"entry12");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(C)));
if (prd_supprimer(ref)==1)
{
pt=lookup_widget (objet_graphique ,"label_supprimer");
gtk_label_set_text(GTK_LABEL(pt),"Successsss");
}
else
{
pt=lookup_widget (objet_graphique ,"label_supprimer");
gtk_label_set_text(GTK_LABEL(pt),"Echoue");
}
}


//////////gestion des menus//////////
void
on_button6_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifierb ;
windowmodifierb=create_modifierb();
gtk_widget_show(windowmodifierb);
}


void
on_button5_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimerb ;
windowsupprimerb=create_supprimerb();
gtk_widget_show(windowsupprimerb);
}


void
on_button4_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouterb ;
windowajouterb=create_ajouterb();
gtk_widget_show(windowajouterb);
}


void
on_button9_dechets_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdechetsb ;
windowdechetsb=create_dechetsb();
gtk_widget_show(windowdechetsb);
}


void
on_button8_recl_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *id,*nom,*date,*entree,*dessert,*radiobutton1,*radiobutton2,*radiobutton3;
wmenu M;
radiobutton1=lookup_widget (objet_graphique,"radiobutton1");
radiobutton2=lookup_widget (objet_graphique,"radiobutton2");
radiobutton3=lookup_widget (objet_graphique,"radiobutton3");
id=lookup_widget(objet_graphique,"entry3_id");
nom=lookup_widget(objet_graphique,"entry1");
date=lookup_widget(objet_graphique,"entry2");
entree=lookup_widget(objet_graphique,"entry8_entr");
dessert=lookup_widget(objet_graphique,"entry9_dess");
strcpy(M.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(M.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(M.date,gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(M.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(M.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (radiobutton1)))
strcpy(M.repas,"petit dej");
else if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (radiobutton2)))
strcpy(M.repas,"dejeuner");
       else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (radiobutton3)))
       strcpy(M.repas,"diner");

wajouter(M);



}
void
on_button1_back1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowpage_d_accueil;
windowpage_d_accueil=create_page_d_accueil();
gtk_widget_show(windowpage_d_accueil);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowpage_d_accueil;
windowpage_d_accueil=create_page_d_accueil();
gtk_widget_show(windowpage_d_accueil);
}



void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowpage_d_accueil;
windowpage_d_accueil=create_page_d_accueil();
gtk_widget_show(windowpage_d_accueil);
}



void
on_button3_conf1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*nom,*date,*repas,*entree,*dessert;
wmenu N;


id=lookup_widget(objet_graphique,"entry5_id");
nom=lookup_widget(objet_graphique,"entry3_nom2");
date=lookup_widget(objet_graphique,"entry4_date2");
repas=lookup_widget(objet_graphique,"entry5_repas2");
entree=lookup_widget(objet_graphique,"entry6_entree2");
dessert=lookup_widget(objet_graphique,"entry7_dessert2");

strcpy(N.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(N.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(N.date,gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(N.repas,gtk_entry_get_text(GTK_ENTRY(repas)));
strcpy(N.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(N.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
if 
(verif_w(N.id)==1)
{
wsupprimer(N.id);
wajouter(N);

}
}


void
on_button2_supp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *id;
char iden[200];
id=lookup_widget(objet_graphique,"entry10_ids");
strcpy(iden,gtk_entry_get_text(GTK_ENTRY(id)));
if 
(verif_w(iden)==1)
{
wsupprimer(iden);
}
}


void
on_button2_back3_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowpage_d_accueil;
windowpage_d_accueil=create_page_d_accueil();
gtk_widget_show(windowpage_d_accueil);
}


void
on_button1_conf5_clicked               (GtkWidget       *objet_graphique,
                                       gpointer         user_data)
{
GtkWidget *repas,*dechets,*jour,*mois;
char jour1[50],mois1[50];
char rep[200];
char dec[200];
jour=lookup_widget (objet_graphique,"spinbutton1");
mois=lookup_widget (objet_graphique,"spinbutton2");
sprintf(jour1,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
sprintf(mois1,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
repas=lookup_widget (objet_graphique,"comboboxentry1");
dechets=lookup_widget(objet_graphique,"entry3_dechets");
strcpy(rep,gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)));
strcpy(dec,gtk_entry_get_text(GTK_ENTRY(dechets)));
FILE *f=NULL;
f=fopen("dechets.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s \n",jour1,mois1,rep,dec);
fclose(f);
}
}

void
on_button1_cherch2_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
wmenu M;
GtkWidget *id,*nom,*repas,*date,*entree,*dessert,*output1;
char id1[200];
char nom1[200];
char repas1[200];
char date1[200];
char entree1[200];
char dessert1[200];
int x =-1;
char ch1[200];
FILE *f=NULL;
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
id=lookup_widget(objet_graphique,"entry3_id4");
output1=lookup_widget(objet_graphique,"label2_message");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
FILE *F=NULL;
F = fopen ("menu.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id1,nom1,repas1,date1,entree1,dessert1) != EOF)
  {
  
    if (strcmp (id1,id) == 0)
      {
      x=1;
strcpy(ch1,M.id);
strcpy(ch1,M.nom);
strcpy(ch1,M.repas);
strcpy(ch1,M.date);
strcpy(ch1,M.dessert);
gtk_label_set_text(GTK_LABEL(output1),ch1);

}
}
}
}

///void
///on_togglebutton3_cherch_clicked        (GtkButton       *button,
///                                        gpointer         user_data)
///{

///}


void
on_button1_cherch3_clicked             (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *windowchercherb ;
windowchercherb=create_chercherb();
gtk_widget_show(windowchercherb);
}


void
on_button1_affich_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *page_d_accueil;

GtkWidget *treeview2_affich;
page_d_accueil=lookup_widget(objet,"page_d_accueil");


treeview2_affich=lookup_widget(page_d_accueil,"treeview2_affich");
wafficher(treeview2_affich);
}




void
on_button1_meilleur_menu_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *meilleur_menu ;
	
	GtkWidget *out;
	
	
	wmenu l ;
	char c[100] ;
   
	meilleur_menu=create_meilleur_menu();

	gtk_widget_show (meilleur_menu);
	
	
	out = lookup_widget(objet,"label1889");
	
	
        strcpy(c,"hello");

	
	gtk_label_set_text(GTK_LABEL(out),c);

	
}





void
on_button_disconnect_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window0,*window1;
window0=lookup_widget(objet,"EspaceAdmin");
gtk_widget_destroy(window0);
	window1=create_window_login();

	gtk_widget_show (window1);
}

