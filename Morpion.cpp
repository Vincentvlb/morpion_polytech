#include "Morpion.hpp"

Morpion::Morpion(PinName usbTX, PinName usbRX, PinName oled_sda, PinName oled_scl, PinName afficheur_dio, PinName afficheur_clk): 
speechRecognizer(usbTX, usbRX), afficheurGrille(oled_sda, oled_scl), grille(&afficheurGrille), afficheur_score(afficheur_dio, afficheur_clk){
    curseur = Curseur();
    joueur_actif = Joueur::JOUEUR_1;
    score = {0, 0};
    chiffre_vers_7_segement = {C7_0, C7_1, C7_2, C7_3, C7_4, C7_5, C7_6, C7_7, C7_8, C7_9};
}

void Morpion::changer_joueur_actif(){
    if(joueur_actif==Joueur::JOUEUR_1) joueur_actif = Joueur::JOUEUR_2;
    else joueur_actif = Joueur::JOUEUR_1;
}

Symbole Morpion::symbole_du_joueur_actif(){
    if(joueur_actif==Joueur::JOUEUR_1) return Symbole::CROIX;
    else return Symbole::ROND;
}

int Morpion::joueur_via_symbole(Symbole symbole){
    if(symbole==Symbole::CROIX) return Joueur::JOUEUR_1;
    else return Joueur::JOUEUR_2;
}

void Morpion::jeu(){
    while(1){
        while(!grille.partie_finie()){
            SpeechRecognizerCmd cmd = recuperation_commande();
            if(cmd!=SpeechRecognizerCmd::VALIDE){
                if(curseur.deplacement(cmd)) afficher_curseur();
                else printf("Coup non valide !\n");
            }else{
                if(grille.ajouter_coup(curseur.transforme_coup(symbole_du_joueur_actif()))){
                    changer_joueur_actif();
                }else{
                    printf("Coup non valide !!\n");
                }
            }
        }
        grille.reinitialiser_grille();
        curseur.appliquer_coordonnee(1,1);
        Symbole symbole_gagnant = grille.recuperer_gagnant();
        score[joueur_via_symbole(symbole_gagnant)] += 1;
        //afficher_score();
    }
}

void Morpion::lancer_jeu(){
    afficher_curseur();
    jeu();
}

SpeechRecognizerCmd Morpion::recuperation_commande(){
    return speechRecognizer.recuperation_commande();
}

void Morpion::afficher_curseur(){
    afficheurGrille.clignoter_symbole(curseur.transforme_coup(symbole_du_joueur_actif()).get_case_id(), symbole_du_joueur_actif());
}

void Morpion::afficher_score(){
    //Score joueur 1
    afficheur_score.writeData(chiffre_vers_7_segement[score[0]/10],0x40);
    afficheur_score.writeData(chiffre_vers_7_segement[score[0]%10],0x41);
    //Score joueur 2
    afficheur_score.writeData(chiffre_vers_7_segement[score[1]/10],0x42);
    afficheur_score.writeData(chiffre_vers_7_segement[score[1]%10],0x43);
}
