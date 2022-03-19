//
// Created by PhantHive on 13/03/2022.
//

#include <iostream>
using namespace std;
//#include "date.h"
//#include "note.h"
#include "etudiant.h"
#include "classe.h"

void menu() {
    cout << "1: Saisir etudiant" << endl;
    cout << "2: Classement bachelor" << endl;
    cout << "3: fin" << endl;
}

int main() {

    classe bachelor[40];

    date d(0, 0, 0);
    note n1(-1);
    note n2(-1);
    note n3(-1);
    etudiant e("nom", "prenom", d, n1, n2, n3, -1);

    int c;
    int i;
    int nb_etud;
    int total_etud = 0;

    do {
        menu();
        cin >> c;
        if (c == 1) {

            cout << "Combien d'etudiants?" << endl;
            cout << "> ";
            cin >> nb_etud;

            for (i=total_etud;i < (total_etud + nb_etud); i++) {
                cin >> e;
                string nom_complet = e.get_nom() + " " + e.get_prenom();
                bachelor[i].set_eleve(nom_complet, e.get_moyenne());
                bachelor[i].set_rang(1);
                cout << e;
            }

            total_etud += nb_etud;

            for (i=0; i < total_etud; i++) {
                int eleve_1 = bachelor[i].get_rang();
                int eleve_2 = bachelor[i + 1].get_rang();
                if (bachelor[i].get_moyenne() > bachelor[i+1].get_moyenne()) {

                    if (eleve_1 > 1 && (eleve_1 == eleve_2)) {
                        bachelor[i].set_rang(eleve_1 - 1);
                        bachelor[i + 1].set_rang(eleve_2 + 1);
                    }
                    else if (eleve_1 == eleve_2) {
                        bachelor[i + 1].set_rang(eleve_1 + 1);
                    }

                }
                else if (bachelor[i].get_moyenne() == bachelor[i+1].get_moyenne()) {
                    if (eleve_1 > 1 && eleve_2 > 1 && (eleve_1 == eleve_2)) {
                        bachelor[i].set_rang(eleve_1 - 1);
                        bachelor[i + 1].set_rang(eleve_2 - 1);
                    }

                }
                else {
                    if (eleve_2 > 1 && (eleve_1 == eleve_2)) {
                        bachelor[i + 1].set_rang(eleve_2 - 1);
                        bachelor[i].set_rang(eleve_1 + 1);
                    }
                    else if (eleve_1 == eleve_2){
                        bachelor[i].set_rang(eleve_1 + 1);
                    }
                }
            }

        }
        else if (c == 2) {
            for (i=0; i < total_etud; i++){
                cout << bachelor[i];
            }

        }




    } while (c != 3);



    return 0;
}