#ifndef GRILLE_HPP
#define GRILLE_HPP

#include "Coup.hpp"
#include "Joueur.hpp"
#include "AfficheurGrille.hpp"
#include <vector>

class Grille
{
private:
    std::vector< std::vector<Symbole> > grille;
    const static int TAILLE_GRILLE = 3;
    Symbole gagnant;
    AfficheurGrille* afficheurGrille;
    bool trio_gagnant(std::vector<Symbole> trio);
    bool ligne_gagnante();
    bool colonne_gagnante();
    bool diagonnale_gagnante();
    bool place_libre(Coup coup);
public:
    Grille(AfficheurGrille* afficheurGrille);
    bool ajouter_coup(Coup coup);
    bool partie_finie();
    Symbole recuperer_gagnant();
    void reinitialiser_grille();
};

#endif 