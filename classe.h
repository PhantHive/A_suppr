//
// Created by PhantHive on 14/03/2022.
//

#ifndef CPP_CLASSE_H
#define CPP_CLASSE_H

#endif //CPP_CLASSE_H
#include <string>
#include <iostream>

class classe {

    string nom_complet;
    int moyenne;
    int rang;
    //static int compteur;

public:


    classe();

    void set_eleve(string, int);
    void set_rang(int);
    int get_rang();
    int get_moyenne();
    string get_nom();
    //int get_compteur();

    friend ostream& operator<<(ostream &, classe &);


    //static void nombre_d_eleves() {cout << "La classe comporte " << classe::compteur << " eleves" << endl;}
};

//classe::classe(string nm) {nom_complet=nm, compteur++; nombre_d_eleves();}

classe::classe() {nom_complet = "Nom"; moyenne=0; rang=0;};

void classe::set_eleve(string nom, int moy) {
    nom_complet = nom;
    moyenne = moy;
}

void classe::set_rang(int rg) {
    rang = rg;
}

int classe::get_rang() {
    return rang;
}

int classe::get_moyenne() {
    return moyenne;
}

string classe::get_nom() {
    return nom_complet;
}


ostream &operator<<(ostream & os, classe & c) {
    cout << c.get_nom() << endl;
    cout << "Moyenne> " << c.get_moyenne() << " Rang> " << c.get_rang() << endl;
    cout << "\n" << endl;

    return os;
}








