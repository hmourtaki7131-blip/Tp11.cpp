
#include <iostream>
#include <vector>
using namespace std;

// Classe abstraite
class Animal {
public:
    virtual void crier() const = 0;

    void info() const {
        cout << "Je suis un animal." << endl;
    }

    virtual ~Animal() {
    }
};

// Classe Chien
class Chien : public Animal {
public:
    void crier() const override {
        cout << "Wouf !" << endl;
    }
};

// Classe Chat
class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou !" << endl;
    }
};

// Classe Vache
class Vache : public Animal {
public:
    void crier() const override {
        cout << "Meuh !" << endl;
    }
};

int main() {
    vector<Animal*> animaux;

    // Creation des animaux
    animaux.push_back(new Chien());
    animaux.push_back(new Chat());
    animaux.push_back(new Vache());

    cout << "===== GESTION DES ANIMAUX =====" << endl;

    // Affichage
    for (int i = 0; i < animaux.size(); i++) {
        animaux[i]->info();
        animaux[i]->crier();
        cout << "-------------------" << endl;
    }

    // Liberation de la memoire
    for (int i = 0; i < animaux.size(); i++) {
        delete animaux[i];
    }

    animaux.clear();

    return 0;
}
