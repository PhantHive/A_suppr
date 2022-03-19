//
// Created by PhantHive on 13/03/2022.
//

#ifndef CPP_ETUDIANT_H
#define CPP_ETUDIANT_H

#endif //CPP_ETUDIANT_H

#include "verif.h"

class date {

private:
    int jour;
    int mois;
    int annee;

public:

    date();
    date(int, int, int); // constructeur
    date(const date &); // constructeur par recopie

    void set_jour(int);
    void set_mois(int);
    void set_annee(int);

    int get_jour();
    int get_mois();
    int get_annee();

    friend istream& operator>>(istream &, date &);
    friend ostream& operator<<(ostream &, date &);



};

date::date() {jour=0, mois=0, annee=0;}
date::date(int j, int m, int a) {jour=j, mois=m, annee=a;}
date::date(const date & d) { jour=d.jour; mois=d.mois, annee=d.annee;}

void date::set_jour(int val) {
    jour = val;
}
void date::set_mois(int val) {
    mois = val;
}
void date::set_annee(int val) {
    annee = val;
}

int date::get_jour() {
    return jour;
}

int date::get_mois() {
    return mois;
}

int date::get_annee() {
    return annee;
}



istream &operator>>(istream & is, date & d) {
    int j, m, a;
    int verif;

    do {
        cout << "\nSaisir la date:" << endl;
        cout << "Jour: ";
        cin >> j;
        cout << "Mois: ";
        cin >> m;
        cout << "Annee: ";
        cin >> a;

        verif = verif_date(j, m, a);
    } while(verif == 0);


    d.set_jour(j);
    d.set_mois(m);
    d.set_annee(a);
    return is;
}

ostream &operator<<(ostream & os, date & d) {

    cout << "Date de naissance: " << d.get_jour() << "/" << d.get_mois() << "/" << d.get_annee() << endl;
    return os;
}

