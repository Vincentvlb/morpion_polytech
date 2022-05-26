#ifndef CURSEUR_HPP
#define CURSEUR_HPP

#include "SpeechRecognizerCmd.hpp"
#include "Coup.hpp"

class Curseur 
{
private:
    int ligne, colonne;
    bool droite();
    bool gauche();
    bool haut();
    bool bas();
public:
    Curseur();
    Curseur(int ligne,int colonne);
    bool deplacement(SpeechRecognizerCmd cmd);
    Coup transforme_coup(Symbole symbole_actif);
    void appliquer_coordonnee(int ligne, int colonne);
};

#endif 