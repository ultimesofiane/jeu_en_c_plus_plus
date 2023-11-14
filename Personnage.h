#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <iostream>
#include <string>
#include <mysql/mysql.h>
using namespace std;


class Personnage {
protected:
    const string name;
    int ptDeVie;
    int attaque;
    int defense;
    int vitesse;
    int energie;
    
    
public:
    Personnage(string, int);
//attaque 
    void attaqueDeBase(Personnage& cible);
    void attaqueAmelioree(Personnage& cible);
    bool actionSpeciale(Personnage& cible);

//methode de la classe
    bool estVivant();
    void recevoirDegats(int degats);
    void utiliserEnergie(int quantite);
    void addstats();
    void information();
    void showstats();
   // void addStatsToDatabase();

//mutateurs et assesseur
    int getPtDeVie();
    int getAttaque();
    int getDefense();
    int getVitesse();
    int getEnergie();
    string getName();


};

#endif // PERSONNAGE_H
