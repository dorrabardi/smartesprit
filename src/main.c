/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *EspaceAdmin;
  GtkWidget *AjoutUtilisateur;
  GtkWidget *Modifier;
  GtkWidget *Supprimer;
  GtkWidget *database_utilisateurs;
  GtkWidget *database_etudiants;
  GtkWidget *nombre_etudiants;
  GtkWidget *window_login;
  GtkWidget *Gestion_foyer;
  GtkWidget *acceuilw;
  GtkWidget *gestionw;
  GtkWidget *dialog_service_partie_2;
  GtkWidget *Accueil;
  GtkWidget *addCap;
  GtkWidget *editCap;
  GtkWidget *listCap;
  GtkWidget *delCap;
  GtkWidget *defCap;
  GtkWidget *ficheVal;
  GtkWidget *anas;
  GtkWidget *Ajouter_produit;
  GtkWidget *Modifier_produit;
  GtkWidget *Supprimer_produit;
  GtkWidget *Affichage_produit;
  GtkWidget *Repture_Stock;
  GtkWidget *page_d_accueil;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  
/*EspaceAdmin = create_EspaceAdmin ();
  gtk_widget_show (EspaceAdmin);


  AjoutUtilisateur = create_AjoutUtilisateur ();
  gtk_widget_show (AjoutUtilisateur);
  Modifier = create_Modifier ();
  gtk_widget_show (Modifier);
  Supprimer = create_Supprimer ();
  gtk_widget_show (Supprimer);
  database_utilisateurs = create_database_utilisateurs ();
  gtk_widget_show (database_utilisateurs);
  database_etudiants = create_database_e ();
  gtk_widget_show (database_etudiants);*/
  window_login = create_window_login();
  gtk_widget_show(window_login);
 /* Gestion_foyer = create_Gestion_foyer();
  gtk_widget_show(Gestion_foyer);





gestionw = create_gestionw();
  gtk_widget_show(gestionw);

  acceuilw = create_acceuilw();
  gtk_widget_show(acceuilw);



  anas = create_anas ();
  gtk_widget_show (anas);


 Accueil = create_Accueil();
  gtk_widget_show(Accueil);

page_d_accueil = create_page_d_accueil();
  gtk_widget_show(page_d_accueil);*/

  gtk_main ();
  return 0;
}
