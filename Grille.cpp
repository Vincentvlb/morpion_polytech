#include "Grille.hpp"

Grille::Grille(AfficheurGrille* afficheurGrille): afficheurGrille(afficheurGrille){
    reinitialiser_grille(); 
}

void Grille::reinitialiser_grille(){
    for(int ligne=0; ligne < TAILLE_GRILLE ;ligne++){
        for(int colonne=0; colonne < TAILLE_GRILLE ;colonne++){
            grille[ligne][colonne] = Symbole::VIDE;
        }
    }
}

bool Grille::trio_gagnant(std::vector<Symbole> trio){
    if(trio[0] == trio[1] == trio[2]){
        gagnant = trio[0];
        return true;
    }
    return false;
}

bool Grille::ligne_gagnante(){
    for (std::vector<Symbole> grille1D : this->grille){
        if(trio_gagnant(grille1D)) return true;   
    }
    return false;
}

bool Grille::colonne_gagnante(){
    std::vector<Symbole> colonne_1, colonne_2, colonne_3;
    for (std::vector<Symbole> grille1D : this->grille){
        for(int colonne=0; colonne < grille1D.size() ;colonne++){
            colonne_1[colonne] = grille1D[colonne];
        }
    }
    return (trio_gagnant(colonne_1) || trio_gagnant(colonne_2) || trio_gagnant(colonne_3));
}

bool Grille::diagonnale_gagnante(){
    std::vector<Symbole> diagonnale_1, diagonnale_2;
    diagonnale_1.push_back(grille[0][0]);
    diagonnale_1.push_back(grille[1][1]);
    diagonnale_1.push_back(grille[2][2]);
    diagonnale_2.push_back(grille[0][2]);
    diagonnale_2.push_back(grille[1][1]);
    diagonnale_2.push_back(grille[2][0]);
    return (trio_gagnant(diagonnale_1) || trio_gagnant(diagonnale_2));
}

bool Grille::partie_finie(){
    return (ligne_gagnante() || colonne_gagnante() || diagonnale_gagnante());
}

bool Grille::place_libre(Coup coup){
    return grille[coup.get_ligne()][coup.get_colonne()] == Symbole::VIDE;
}

bool Grille::ajouter_coup(Coup coup){
    if(place_libre(coup)){
        grille[coup.get_ligne()][coup.get_colonne()] = coup.get_symbole();
        afficheurGrille->afficher_symbole(coup.get_case_id(), coup.get_symbole());
    }
    return false;
}

Symbole Grille::recuperer_gagnant(){
    return gagnant;
}