#include "mbed.h"
#include "Morpion.hpp"
 
#define OLED_SDA   PC_1
#define OLED_SCL   PC_0
#define PC_TX   USBTX
#define PC_RX   USBRX
#define AFFICHEUR_DIO   PB_13
#define AFFICHEUR_CLK   PB_15

int main() {
    Morpion morpion(PC_TX, PC_RX, OLED_SDA, OLED_SCL, PB_13, PB_15);
    morpion.lancer_jeu();
}
