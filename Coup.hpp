#ifndef COUP_HPP
#define COUP_HPP

#include "Symbole.hpp"
#include <map>

class Coup 
{
private:
    int ligne, colonne;
    Symbole symbole;
    std::map<int, std::map<int, int>> traduction_ligne_colone_id_case = {
        {0, {
            {0,0},
            {1,1},
            {2,2}
        }},
        {1, {
            {0,3},
            {1,3},
            {2,5}
        }},
        {2, {
            {0,6},
            {1,7},
            {2,8}
        }}
    };
public:
    Coup(int ligne,int colonne,Symbole symbole) : ligne(ligne), colonne(colonne), symbole(symbole){}
    Symbole get_symbole(){return symbole;}
    void set_symbole(Symbole symbole){this->symbole=symbole;}
    int get_ligne(){return ligne;}
    int get_colonne(){return colonne;}
    int get_case_id(){return traduction_ligne_colone_id_case[ligne][colonne];};
};

#endif 