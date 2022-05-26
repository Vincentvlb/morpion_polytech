#include "Curseur.hpp"

Curseur::Curseur() : Curseur(1,1){}

Curseur::Curseur(int ligne,int colonne) : ligne(ligne), colonne(colonne){}

void Curseur::appliquer_coordonnee(int ligne, int colonne){
    this->ligne = ligne;
    this->colonne = colonne;
};

bool Curseur::deplacement(SpeechRecognizerCmd cmd){
    switch (cmd){
        case SpeechRecognizerCmd::DROITE:
            return droite();
        case SpeechRecognizerCmd::GAUCHE:
            return gauche();
        case SpeechRecognizerCmd::HAUT:
            return haut();
        case SpeechRecognizerCmd::BAS:
            return bas();
        default:
            return false;
    }
}

Coup Curseur::transforme_coup(Symbole symbole_actif){
    return Coup(ligne, colonne, symbole_actif);
}

bool Curseur::droite(){
    if(this->ligne + 1 > 3) return false;
    else{
        this->ligne += 1;
        return true;
    }
}

bool Curseur::gauche(){
    if(this->ligne - 1 < 0) return false;
    else{
        this->ligne -= 1;
        return true;
    }
}

bool Curseur::haut(){
    if(this->colonne - 1 < 0) return false;
    else{
        this->colonne -= 1;
        return true;
    }
}

bool Curseur::bas(){
    if(this->colonne + 1 > 3) return false;
    else{
        this->colonne += 1;
        return true;
    }
}