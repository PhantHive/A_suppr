//
// Created by PhantHive on 13/03/2022.
//

#ifndef CPP_ETUDIANT_H
#define CPP_ETUDIANT_H

#endif //CPP_ETUDIANT_H

#include "date.h"
#include "note.h"
#include <string>
#include <iostream>

class etudiant {

private:
    string nom, prenom;
    date ddn;
    note n1;
    note n2;
    note n3;
    double moy;

public:

    etudiant(string, string, date, note, note, note, double);

    void set_nom(string);
    void set_prenom(string);
    string get_nom();
    string get_prenom();

    void set_ddn();
    date get_ddn();

    void set_note();
    note get_note(int);

    void set_moyenne(int);
    int get_moyenne();
    void calcul_moyenne();

    friend istream& operator>>(istream &, etudiant &);
    friend ostream& operator<<(ostream &, etudiant &);
};

etudiant::etudiant(string nm, string pren, date d, note a, note b, note c, double m) {
    nom=nm, prenom=pren, ddn=d, n1=a, n2=b, n3=c, moy=m;
};

void etudiant::set_nom(string val) {
    nom = val;
}

void etudiant::set_prenom(string val) {
    prenom = val;
}

string etudiant::get_nom() {
    return nom;
}

string etudiant::get_prenom() {
    return prenom;
}

void etudiant::set_ddn() {
    cin >> ddn;
}

void etudiant::set_note() {
    cin >> n1;
    cin >> n2;
    cin >> n3;
}

note etudiant::get_note(int n) {
    if (n == 1)
        return n1;
    else if (n == 2)
        return n2;
    else
        return n3;
}


void etudiant::set_moyenne(int m) {
    moy = m;
}

void etudiant::calcul_moyenne() {
    int m;
    int c1 = n1.get_coef();
    int c2 = n2.get_coef();
    int c3 = n3.get_coef();
    double n_1 = n1.get_n();
    double n_2 = n2.get_n();
    double n_3 = n3.get_n();

    m = (n_1*c1 + n_2*c2 + n_3*c3) / (c1 + c2 + c3);
    set_moyenne(m);
}

int etudiant::get_moyenne() {
    return moy;
};


date etudiant::get_ddn() {
    return ddn;
}


istream &operator>>(istream & is, etudiant & e) {
    string prenom, nom;

    cout << "Prenom: ";
    cin >> prenom;
    cout << "Nom: ";
    cin >> nom;

    e.set_prenom(prenom);
    e.set_nom(nom);

    e.set_ddn();
    e.get_ddn();

    e.set_note();
    e.calcul_moyenne(); // calcule et set la moyenne

    return is;
}

ostream &operator<<(ostream & os, etudiant & e) {

    date d = e.get_ddn();
    int j = d.get_jour();
    int m = d.get_mois();
    int a = d.get_annee();


    cout << "============================" << endl;
    cout << "ETUDIANT: " << e.get_prenom() << " " << e.get_nom() << endl;
    cout << "\nDate de naissance: ";
    cout << j << "/" << m << "/" << a << endl;
    cout << "\nNotes:" << endl;

    note n1 = e.get_note(1);
    note n2 = e.get_note(2);
    note n3 = e.get_note(3);

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;

    cout << "Moyenne: " << e.get_moyenne() << endl;
    cout << "============================" << endl;

    return os;
}








