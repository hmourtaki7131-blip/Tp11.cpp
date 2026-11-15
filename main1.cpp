
#include <iostream>
using namespace std;

// Classe abstraite
class Forme {
public:
    virtual double aire() const = 0;

    virtual ~Forme() {
    }
};

// Classe Cercle
class Cercle : public Forme {
private:
    double rayon;

public:
    Cercle(double r) {
        rayon = r;
    }

    double aire() const override {
        return 3.14 * rayon * rayon;
    }
};

// Classe Rectangle
class Rectangle : public Forme {
private:
    double longueur;
    double largeur;

public:
    Rectangle(double l, double w) {
        longueur = l;
        largeur = w;
    }

    double aire() const override {
        return longueur * largeur;
    }
};

int main() {
    const int N = 2;
    Forme* formes[N];

    double rayon, longueur, largeur;

    // Saisie du cercle
    cout << "Donner le rayon du cercle : ";
    cin >> rayon;

    formes[0] = new Cercle(rayon);

    // Saisie du rectangle
    cout << "Donner la longueur du rectangle : ";
    cin >> longueur;

    cout << "Donner la largeur du rectangle : ";
    cin >> largeur;

    formes[1] = new Rectangle(longueur, largeur);

    // Affichage des aires
    cout << "\n===== AIRES DES FORMES =====" << endl;

    for (int i = 0; i < N; i++) {
        cout << "Aire de la forme " << i + 1
             << " : " << formes[i]->aire() << endl;
    }

    // Liberation de la memoire
    for (int i = 0; i < N; i++) {
        delete formes[i];
    }

    return 0;
}
