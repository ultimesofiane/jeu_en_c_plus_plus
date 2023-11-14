#ifndef SNOWQUEEN_H
#define SNOWQUEEN_H

#include "Personnage.h"

class SnowQueen : public Personnage {
public:
    SnowQueen(const string& , int );

    void javelotDeGlace(Personnage& cible);
    void ventGlacial(Personnage& cible);
    bool actionSpecialeLetItGo(Personnage& cible);
};

#endif // SNOWQUEEN_H
