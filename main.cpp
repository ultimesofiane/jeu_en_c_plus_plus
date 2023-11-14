#include "Personnage.h"
#include "Berserker.h"
#include "SnowQueen.h"


int main() {

int vie;
 // Création des variables
      MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    int j = 0;

    // Connexion et vérification des problèmes
    conn = mysql_init(NULL);
    if (conn == NULL) {
        cerr << "mysql_init() failed" << endl;
        return 1;
    }

    // Connexion à la base de données
    if (mysql_real_connect(conn, "localhost", "sofiane", "", "cardgame", 0, NULL, 0) == NULL) {
        cerr << "mysql_real_connect() failed" << endl;
        mysql_close(conn);
        return 1;
    }

    string requete = "SELECT name, pv, attaque, defense, vitesse FROM equipement"; // Sélection de tous les champs nécessaires

    // Exécuter la requête SQL
    if (mysql_query(conn, requete.c_str())) {
        cerr << "SELECT * FROM equipement failed" << endl;
        mysql_close(conn);
        return 1;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        cerr << "mysql_store_result() failed" << endl;
        mysql_close(conn);
        return 1;
    }

    cout << endl;
string name;
    // Création des personnages
    cout<<"Perso 1: ";
    cin>>name;
    Personnage sofiane(name, 100);
    cout<<"Berserker 2 : ";
    cin>>name;  
    Berserker berserker(name, 120);
    SnowQueen queen("Rukia", 500);

    Personnage* joueur1;
    Personnage* joueur2;

    // Déterminez le joueur qui commence en fonction de la vitesse
    if (sofiane.getVitesse() > berserker.getVitesse()) {
        joueur1 = &sofiane;
        joueur2 = &berserker;
    } else {
        joueur1 = &berserker;
        joueur2 = &sofiane;
    }

    cout<<endl;
    cout << joueur1->getName() << " a "<<joueur1->getPtDeVie() <<" pv."<< endl;
    cout << joueur2->getName() << " a "<<joueur2->getPtDeVie() <<" pv.  "<< endl;
    cout<<endl;

    while (sofiane.estVivant() && berserker.estVivant()) {
        cout << joueur1->getName() << ", choisissez une action :" << endl;
        cout << "1. Attaque de base" << endl;
        cout << "2. Attaque améliorée" << endl;
        if(joueur1->getEnergie()>100)
        cout << "3. Action spéciale" << endl;

        int choix;
        cin >> choix;

        switch (choix) {
            case 1:
                joueur1->attaqueDeBase(*joueur2);
                break;
            case 2:
                joueur1->attaqueAmelioree(*joueur2);
                break;
            case 3:
                if (joueur1->actionSpeciale(*joueur2)) {
                    cout << joueur1->getName() << " a utilisé son action spéciale !" << endl;
                } else {
                    cout << "Impossible d'utiliser l'action spéciale. Vous n'avez pas assez d'énergie." << endl;
                }
                break;
            default:
                cout << "Choix invalide. Choisissez 1, 2 ou 3." << endl;
        }

// Échange des rôles des joueurs
        swap(joueur1, joueur2);

        cout << joueur1->getName() << " a maintenant " << joueur1->getPtDeVie() << " PV." << endl;
        cout << joueur2->getName() << " a maintenant " << joueur2->getPtDeVie() << " PV." << endl;
        cout << "-----------------------" << endl;
    }

    if (joueur1->estVivant()) {
        cout <<joueur1->getName()<< " a gagné !" << endl;
    } else {
        cout <<joueur2->getName()<< " a gagné !" << endl;
    }

    return 0;
}
