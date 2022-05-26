#ifndef MORPION_HPP
#define MORPION_HPP

#include "Grille.hpp"
#include "Joueur.hpp"
#include "Curseur.hpp"
#include "PinNames.h"
#include "SpeechRecognizerCmd.hpp"
#include "AfficheurGrille.hpp"
#include "TM1637.h"
#include "mbed.h"
#include <vector>

class Morpion 
{
private:
    Grille grille;
    std::vector<int> score;
    Joueur joueur_actif;
    Curseur curseur;
    SpeechRecognizer speechRecognizer;
    AfficheurGrille afficheurGrille;
    TM1637 afficheur_score;
    vector<unsigned short> chiffre_vers_7_segement;
    SpeechRecognizerCmd recuperation_commande();
    Symbole symbole_du_joueur_actif();
    void jeu();
    int joueur_via_symbole(Symbole symbole);
public:
    Morpion(PinName usbTX, PinName usbRX, PinName oled_sda, PinName oled_scl, PinName afficheur_dio, PinName afficheur_clk);
    void changer_joueur_actif();
    void lancer_jeu();
    void afficher_score();
    void afficher_curseur();
};

#endif 