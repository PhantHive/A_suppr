//
// Created by PhantHive on 13/03/2022.
//

#ifndef CPP_SAISIS_H
#define CPP_SAISIS_H

#endif //CPP_SAISIS_H

#include <iostream>
using namespace std;

int verif_date(int j, int m, int a) {

    time_t seconds=time(nullptr);
    struct tm * current_time=localtime(&seconds);
    int y = current_time->tm_year + 1900;

    int date_valide = 0;

    if (m <= 12 && m > 0 && a >= (y - 35) && j <= 31 && j > 0 && a <= (y - 15)) {
        if (m == 2 && (a % 4 == 0) && (a % 100 != 0)) {
            if (j <= 29) {
                date_valide = 1;
            }
            else {
                cout << "A l'annee " << a << ", le mois de fevrier comporter 29 jours\n" << a << endl;
            }

        }
        else if ((m == 2 && (a % 4 == 0) && (a % 100 == 0) && (a % 400 == 0))){
            if (j <= 29) {
                date_valide = 1;
            }
            else {
                cout << "A l'annee " << a << ", le mois de fevrier comporter 29 jours\n"<< a << endl;
            }
        }
        else if (m == 2){
            if (j <= 28) {
                date_valide = 1;
            }
            else {
                cout << "A l'annee " << a << ", le mois de fevrier comporter 28 jours\n" << a << endl;
            }
        }
        else {
            date_valide = 1;
        }

    }
    else {
        cout << "Merci de ressaisir la date (probleme survenue sur la saisie du mois, du jours ou de l'annee)\n" << endl;
    }


    return date_valide;

}