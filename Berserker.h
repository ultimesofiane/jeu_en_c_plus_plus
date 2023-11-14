#ifndef BERSERKER_H
#define BERSERKER_H

#include "Personnage.h"

class Berserker : public Personnage {
public:
    Berserker(const string& name, int health);

    void frappePunitive(Personnage& cible);
    void coupDechaine(Personnage& cible);
    bool actionSpecialeMovementAlpha(Personnage& cible);
};

#endif // BERSERKER_H
