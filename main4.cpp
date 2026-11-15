
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe abstraite
class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;

    virtual ~NoeudFichier() {
    }
};

// Classe Fichier
class Fichier : public NoeudFichier {
private:
    string nomFichier;
    int tailleFichier;

public:
    Fichier(string n, int t) {
        nomFichier = n;
        tailleFichier = t;
    }

    string nom() const override {
        return nomFichier;
    }

    int taille() const override {
        return tailleFichier;
    }
};

// Classe Dossier
class Dossier : public NoeudFichier {
private:
    string nomDossier;
    vector<NoeudFichier*> enfants;

public:
    Dossier(string n) {
        nomDossier = n;
    }

    string nom() const override {
        return nomDossier;
    }

    void ajouter(NoeudFichier* element) {
        enfants.push_back(element);
    }

    int taille() const override {
        int total = 0;

        for (int i = 0; i < enfants.size(); i++) {
            total += enfants[i]->taille();
        }

        return total;
    }

    void afficher() const {
        cout << "\nDossier : " << nomDossier << endl;

        for (int i = 0; i < enfants.size(); i++) {
            cout << enfants[i]->nom()
                 << " : " << enfants[i]->taille()
                 << " Ko" << endl;
        }

        cout << "Taille totale : " << taille()
             << " Ko" << endl;
    }

    ~Dossier() {
        for (int i = 0; i < enfants.size(); i++) {
            delete enfants[i];
        }
    }
};

int main() {
    Dossier* racine = new Dossier("Documents");

    int choix;
    string nom;
    int taille;

    do {
        cout << "\n===== SYSTEME DE FICHIERS =====" << endl;
        cout << "1. Ajouter un fichier" << endl;
        cout << "2. Creer un sous-dossier" << endl;
        cout << "3. Afficher la taille totale" << endl;
        cout << "4. Afficher les elements" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            cout << "Nom du fichier : ";
            cin >> nom;

            cout << "Taille du fichier (Ko) : ";
            cin >> taille;

            if (taille < 0) {
                cout << "Taille invalide !" << endl;
                break;
            }

            racine->ajouter(new Fichier(nom, taille));
            cout << "Fichier ajoute !" << endl;
            break;

        case 2: {
            cout << "Nom du sous-dossier : ";
            cin >> nom;

            Dossier* sousDossier = new Dossier(nom);

            int nb;
            cout << "Combien de fichiers dans ce dossier ? ";
            cin >> nb;

            for (int i = 0; i < nb; i++) {
                string nomF;
                int tailleF;

                cout << "Nom du fichier " << i + 1 << " : ";
                cin >> nomF;

                cout << "Taille (Ko) : ";
                cin >> tailleF;

                if (tailleF < 0) {
                    cout << "Taille invalide, fichier ignore." << endl;
                    continue;
                }

                sousDossier->ajouter(
                    new Fichier(nomF, tailleF)
                );
            }

            racine->ajouter(sousDossier);
            cout << "Sous-dossier ajoute !" << endl;
            break;
        }

        case 3:
            cout << "Taille totale du dossier "
                 << racine->nom() << " : "
                 << racine->taille() << " Ko" << endl;
            break;

        case 4:
            racine->afficher();
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    delete racine;

    return 0;
}
