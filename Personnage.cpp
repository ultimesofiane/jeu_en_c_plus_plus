#include "Personnage.h"

Personnage::Personnage(string name, int health) : name(name), ptDeVie(health), attaque(10), defense(5), vitesse(18), energie(80) {
    // srand(time(NULL));
    // vitesse=rand() % (60-8);
    
}

void Personnage::attaqueDeBase(Personnage& cible) {
    int degats = attaque;
    cible.recevoirDegats(degats);
    energie += 10;
}

void Personnage::attaqueAmelioree(Personnage& cible) {
    int degats = attaque * 1.5;
    cible.recevoirDegats(degats);
    energie += 15;
}

bool Personnage::actionSpeciale(Personnage& cible) {
    if (energie >= 100) {
        int degats = attaque * 3.5;
        cible.recevoirDegats(degats);
        utiliserEnergie(100);
        return true;
    }
    return false;
}

bool Personnage::estVivant()  {
    return ptDeVie > 0;
}

void Personnage::recevoirDegats(int degats) {
    ptDeVie -= max(0, degats - defense);
}

void Personnage::utiliserEnergie(int quantite) {
    energie += quantite;
    energie = max(0, energie);
}

int Personnage::getPtDeVie()  {
    return ptDeVie;
}

int Personnage::getAttaque()  {
    return attaque;
}

int Personnage::getDefense()  {
    return defense;
}

int Personnage::getVitesse()  {
    return vitesse;
}

int Personnage::getEnergie()  {
    return energie;
}

string Personnage::getName()  {
    return name;
}

void Personnage::addStatsToDatabase() {


//        // Construction de la requête SQL
//         string query = "INSERT INTO equipement (attaque, energie, vitesse, defense) VALUES ("to_string(attaque) + ", " to_string(energie) + ", " to_string(vitesse) + ", "to_string(defense) + ") WHERE utilisateur = 'sofiane';";

//         // Exécution de la requête
//         int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

//         // Vérification du résultat de l'exécution
//         if (result != SQLITE_OK) {
//             cerr << "Erreur lors de l'ajout des statistiques à la base de données." <<endl;
//         }
    }

void Personnage::information(){
cout<<"Nom : "<<name<<endl;
cout<<"pv : "<<ptDeVie<<endl;
cout<<"attaque : "<<attaque<<endl;
cout<<"defense : "<<defense<<endl;
cout<<"vitesse : "<<vitesse<<endl;
cout<<"energie : "<<energie<<endl<<endl;
}

void Personnage::showstats( MYSQL *conn,MYSQL_RES *res){
 while ((row = mysql_fetch_row(res))) {
        j++;
        cout << "Name " << j << " : " << row[0] << endl; // Affichage du champ "name"
        cout << "Pv " << j << " : " << row[1] << endl; // Affichage du champ "pv"
        cout << "Attaque " << j << " : " << row[2] << endl; // Affichage du champ "attaque"
        cout << "Defense " << j << " : " << row[3] << endl; // Affichage du champ "defense"
        cout << "Vitesse " << j << " : " << row[4] << endl; // Affichage du champ "energie"
        cout << endl;
    }
}
