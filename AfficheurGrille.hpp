#ifndef AFFICHEURGRILLE_HPP
#define AFFICHEURGRILLE_HPP

#include "Symbole.hpp"
#include "SSD1308.h"
#include <cstring>

class AfficheurGrille
{
private:
    unsigned char grille_actuel[1024], grille_future[1024];
    I2C i2c;
    SSD1308 oled;
    Thread* thread_clignotement;
    bool thread_en_vie;
    void inserer_symbole_grille(int numero_case, Symbole symbole, unsigned char grille_actuel[], unsigned char grille_future[]);
    void clignotement_thread_fct();
    void stoper_clignotement_symbole();
public:
    AfficheurGrille(PinName sda, PinName scl);
    void afficher_symbole(int numero_case, Symbole symbole);
    void clignoter_symbole(int numero_case, Symbole symbole);  
};

#endif