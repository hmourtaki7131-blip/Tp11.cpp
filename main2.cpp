
#include <iostream>
using namespace std;

// Classe abstraite
class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;

    virtual ~Paiement() {
    }
};

// Paiement par carte
class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH par carte bancaire." << endl;
    }
};

// Paiement en especes
class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH en especes." << endl;
    }
};

int main() {
    // Tableau de pointeurs
    Paiement* paiements[3];

    // Creation des objets
    paiements[0] = new PaiementCarte();
    paiements[1] = new PaiementEspece();
    paiements[2] = new PaiementCarte();

    double montant;

    cout << "===== SYSTEME DE PAIEMENT =====" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nDonner le montant du paiement "
             << i + 1 << " : ";
        cin >> montant;

        paiements[i]->effectuerPaiement(montant);
    }

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete paiements[i];
    }

    return 0;
}
