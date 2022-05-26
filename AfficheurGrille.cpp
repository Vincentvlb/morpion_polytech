#include "AfficheurGrille.hpp"

#include "ThisThread.h"
#include "grilles.hpp"
#include <cstring>


void AfficheurGrille::inserer_symbole_grille(int numero_case, Symbole symbole, unsigned char grille_actuel[1024], unsigned char grille_future[1024]){
    if (symbole == Symbole::ROND){
        switch(numero_case){
            case 0 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_gauche_haut[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_gauche_haut[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 1 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_haut_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_haut_milieu[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 2 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_droite_haut[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_droite_haut[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 3 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_gauche_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_gauche_milieu[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 4 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_milieu_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_milieu_milieu[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 5 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_droite_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_droite_milieu[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 6 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_gauche_bas[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_gauche_bas[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 7 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_milieu_bas[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_milieu_bas[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 8 :
            for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_rond_droite_bas[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_rond_droite_bas[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
        }
    }
    else if (symbole == Symbole::CROIX) { 
        switch(numero_case){
            case 0 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_haut_gauche[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_haut_gauche[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            
            case 1 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_centre_haut[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_centre_haut[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 2 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_haut_droit[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_haut_droit[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 3 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_milieu_gauche[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_milieu_gauche[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 4 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_milieu_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_milieu_milieu[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 5 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_milieu_droit[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_milieu_droit[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 6 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_bas_gauche[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_bas_gauche[i];
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 7 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_bas_milieu[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_bas_milieu[i]; 
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
            case 8 :
                for (int i=0;i< sizeof(grille);i++){
                    if ((grille_actuel[i]!= grille_croix_bas_droit[i])&(grille_actuel[i] == 0)){
                        grille_future[i] = grille_croix_bas_droit[i]; 
                    }
                    else{
                        grille_future[i] = grille_actuel[i];
                    }
                };
                break;
        }
    };
}

AfficheurGrille::AfficheurGrille(PinName sda, PinName scl): i2c(sda, scl), oled(&i2c){
    std::memcpy(&grille_actuel, &grille, sizeof(grille));
    oled.setDisplayOn();
    oled.clearDisplay();                                        
    oled.writeBitmap((uint8_t*) grille);
    thread_en_vie = false;
}

void AfficheurGrille::afficher_symbole(int numero_case, Symbole symbole){
    if(thread_en_vie) stoper_clignotement_symbole();
    inserer_symbole_grille(numero_case, symbole, grille_actuel, grille_future);
    memcpy(grille_actuel, grille_future, sizeof(grille_future));
    oled.writeBitmap((uint8_t*) grille_actuel);
}

void AfficheurGrille::clignoter_symbole(int numero_case, Symbole symbole){
    if(thread_en_vie) stoper_clignotement_symbole();
    inserer_symbole_grille(numero_case, symbole, grille_actuel, grille_future);
    thread_en_vie = true;
    thread_clignotement = new Thread();
    thread_clignotement->start(callback(this, &AfficheurGrille::clignotement_thread_fct));
}

void AfficheurGrille::clignotement_thread_fct(){
    while(thread_en_vie){
        oled.writeBitmap((uint8_t*) grille_actuel);
        ThisThread::sleep_for(300ms);
        oled.writeBitmap((uint8_t*) grille_future);
    } 
}

void AfficheurGrille::stoper_clignotement_symbole(){
    thread_en_vie = false;
    thread_clignotement->join();
    delete thread_clignotement;
    oled.writeBitmap((uint8_t*) grille_actuel);
}