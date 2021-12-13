#include <gtk/gtk.h>


void
on_button_ajouter_submit_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemale_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_niv_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_comboboxrole1_changed               (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_button_modifier_submit_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modif_rechercher_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_submit_clicked     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonmale2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_comboboxentry1_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_button_affichage_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Ajout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_Etudiants_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_etudiants_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_niveau_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_nombre_etudiants_show               (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_database_e_show                     (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_Etudiant_treeview_columns_changed   (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_EspaceAdmin_hide                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_database_e_hide                     (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_button_calculer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonfemale_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemale2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_login_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Etudiants_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_autres_clicked               (GtkButton       *button,
                                        gpointer         user_data);




/////////////////////////////////////////gestion de foyer//////////////////////////////////////////////////
int i,j,k,l,m,n,h,d,o,q,r,c,g;

                                       
void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affi_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_rec_ouvrier_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button7_quiter_ouv_clicked          (GtkWidget       *button,
                                        gpointer         user_data);


void
on_buttonINST_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFB_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button56_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button57_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonMaps_clicked                  (GtkButton       *button,
                                        gpointer         user_data);


////////////////////////////////gestion des reclamations ///////////////////////////


 GtkWidget *acceuilw;
  GtkWidget *gestionw;
GtkWidget *dialog_service_partie_2;
typedef struct reclamation reclamation ;
struct reclamation{
char cin[30];
char service[30];
char numerochambre[30];
char date[30];
char nometprenom[30];
char reclamation[50];
};

int i,j ;

void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercherreclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_Ajouterreclamation_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierreclamation_clicked           (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_calcule_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_validersomme_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data);





//////////////////gestion des capteurs/////////////////



void
on_toListCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toAddCap_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toEditCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_toDelCap_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toCapAlar_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toCapDef_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioTemp_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioMouve_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioEau_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioFumee_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btnAddCap_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backAdd_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_btnConsult_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioTempE_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioMouvE_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_saveEdit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backEdit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backListCap_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backDel_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_btnDelete_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backCapDef_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioEauE_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioFumeeE_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeListCap_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_toFicheTemp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_backFiche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sauvegardeTemp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_ajouterclicked_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Supprimer_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rupture_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Affichage_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Nourriture_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nettoyage_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Outils_de_cuisine_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_combobox1ajouter_changed            (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_validermodif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_Rechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_combobox2modifier_changed           (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_Outils_de_cuisine1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nettoyage1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nourriture1_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nettoyage_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Outils_de_cuisine_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nettoyage1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Nourriture1_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Quantite2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_supressionvalider_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_Outils_de_cuisine1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
test_clicked                           (GtkButton       *objet,
                                        gpointer         user_data);


///////////////////gestion des menus/////////////////

void
on_button6_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_dechets_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_recl_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1_back1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_conf1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_supp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_back3_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_conf5_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1_cherch2_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_togglebutton3_cherch_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_cherch3_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_affich_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_meilleur_menu_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_exit_admin_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_login_admin_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_disconnect_clicked           (GtkButton       *button,
                                        gpointer         user_data);
