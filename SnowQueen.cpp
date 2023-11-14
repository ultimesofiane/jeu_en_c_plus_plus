#include "SnowQueen.h"
#include "Personnage.h"

SnowQueen::SnowQueen(const string& name, int health) : Personnage(name, health) 
{
    attaque = 8;
    defense = 15;
    energie = 40;
    vitesse = 90;
}

void SnowQueen::javelotDeGlace(Personnage& cible) {
    int degats = getAttaque() * 1.25;
    utiliserEnergie(20);
    cible.recevoirDegats(degats);
}

void SnowQueen::ventGlacial(Personnage& cible) {
    int degats = getAttaque() * 1.5;
    utiliserEnergie(30);
    cible.recevoirDegats(degats);
}

bool SnowQueen::actionSpecialeLetItGo(Personnage& cible) {
    if (getEnergie() >= 100) {
        int degats = getAttaque() * 1.75;
        utiliserEnergie(100);
        cible.recevoirDegats(degats);
        return true;
    }
    return false;
}
