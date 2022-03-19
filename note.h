//
// Created by PhantHive on 13/03/2022.
//

#ifndef CPP_NOTE_H
#define CPP_NOTE_H

#endif //CPP_NOTE_H

#include <string>

class note {
private:

    double n;
    int coef;
    string matiere;

public:

    note();
    note(double);
    note(const note &);

    void set_matiere(string);
    string get_matiere();

    void set_n(double);
    double get_n();

    void set_coef(int);
    int get_coef();

    friend istream& operator>>(istream &, note &);

};

note::note() {n=-1, coef=1, matiere="matiere";}
note::note(double a) {n=a, coef=1, matiere="matiere";};
note::note(const note & note) { n=note.n, coef=note.coef, matiere=note.matiere;};

void note::set_matiere(string mat) {
    matiere = mat;
}

string note::get_matiere() {
    return matiere;
}

void note::set_n(double note) {
    n = note;
}

void note::set_coef(int cf) {
    coef = cf;
}

int note::get_coef() {
    return coef;
}

double note::get_n() {
    return n;
}


istream &operator>>(istream & is, note & n) {
    double note;
    int coef;
    string mat;

    cout << "\nMatiere: " << endl;
    cin >> mat;

    do {
        cout << "Saisir une note (0-20):" << endl;
        cin >> note;

    } while( note > 20 || note < 0);

    do {
        cout << "Coefficient: ";
        cin >> coef;
    } while (coef <= 0 || coef > 5);

    n.set_coef(coef);
    n.set_n(note);
    n.set_matiere(mat);

    return is;
}


ostream &operator<<(ostream & os, note & n) {

    cout << "Matiere: " << n.get_matiere() << "\nNote: " << n.get_n() << endl;
    return os;
}