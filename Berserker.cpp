#include "Berserker.h"
#include "Personnage.h"

Berserker::Berserker(const string& name, int health) : Personnage(name, health) {
    attaque = 20;
    defense = 5;
    energie = 0;
    vitesse = 70;
}

void Berserker::frappePunitive(Personnage& cible) {
    int degats = getPtDeVie() * 0.3;
    int coutVie = getPtDeVie() * 0.1;
    cible.recevoirDegats(degats);
    utiliserEnergie(40);
    ptDeVie -= coutVie;
}

void Berserker::coupDechaine(Personnage& cible) {
    int degats = getPtDeVie() * 0.5;
    int coutVie = getPtDeVie() * 0.15;
    cible.recevoirDegats(degats);
    utiliserEnergie(30);
    ptDeVie -= coutVie;
}

bool Berserker::actionSpecialeMovementAlpha(Personnage& cible) {
    if (getEnergie() >= 100) {
        int degats = getPtDeVie() * 0.75;
        ptDeVie += getPtDeVie() * 0.5;
        utiliserEnergie(100);
        cible.recevoirDegats(degats);
        return true;
    }
    return false;
}
