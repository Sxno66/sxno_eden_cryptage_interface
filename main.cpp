#include "Crypter.h"
#include <iostream>

/**
 * @brief Affiche le menu pour tester les différentes fonctionnalités du programme.
 */
void afficherMenu() {
    std::cout << "\n===== Menu de Test Crypter =====" << std::endl;
    std::cout << "1. Chiffrer un fichier avec AES" << std::endl;
    std::cout << "2. Déchiffrer un fichier avec AES" << std::endl;
    std::cout << "3. Chiffrer un fichier avec RSA" << std::endl;
    std::cout << "4. Déchiffrer un fichier avec RSA" << std::endl;
    std::cout << "5. Hacher un fichier (SHA-256)" << std::endl;
    std::cout << "6. Vérifier le hachage d'un fichier (SHA-256)" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "Choisissez une option: ";
}

int main() {
    Crypter crypter;
    int choix = -1;

    while (choix != 0) {
        afficherMenu();
        std::cin >> choix;
        std::cin.ignore();  // Ignore le caractère de nouvelle ligne restant dans le tampon

        switch (choix) {
        case 1: {
            std::string cheminCle, fichierEntree, fichierSortie;
            std::cout << "Entrez le chemin pour enregistrer la clé AES : ";
            std::getline(std::cin, cheminCle);
            std::cout << "Entrez le chemin du fichier à chiffrer : ";
            std::getline(std::cin, fichierEntree);
            std::cout << "Entrez le chemin du fichier chiffré en sortie : ";
            std::getline(std::cin, fichierSortie);
            crypter.AEScrypt(cheminCle, fichierEntree, fichierSortie);
            std::cout << "Chiffrement AES terminé !" << std::endl;
            break;
        }
        case 2: {
            std::string cheminCle, fichierChiffre, fichierDechiffre;
            std::cout << "Entrez le chemin de la clé AES : ";
            std::getline(std::cin, cheminCle);
            std::cout << "Entrez le chemin du fichier chiffré : ";
            std::getline(std::cin, fichierChiffre);
            std::cout << "Entrez le chemin du fichier déchiffré en sortie : ";
            std::getline(std::cin, fichierDechiffre);
            crypter.AESDecrypt(cheminCle, fichierChiffre, fichierDechiffre);
            std::cout << "Déchiffrement AES terminé !" << std::endl;
            break;
        }
        case 3: {
            std::string clePublique, clePrivee, fichierEntree, fichierSortie;
            std::cout << "Entrez le chemin pour enregistrer la clé publique : ";
            std::getline(std::cin, clePublique);
            std::cout << "Entrez le chemin pour enregistrer la clé privée : ";
            std::getline(std::cin, clePrivee);
            std::cout << "Entrez le chemin du fichier à chiffrer : ";
            std::getline(std::cin, fichierEntree);
            std::cout << "Entrez le chemin du fichier chiffré en sortie : ";
            std::getline(std::cin, fichierSortie);
            crypter.RSAcrypt(clePublique, clePrivee, fichierEntree, fichierSortie);
            std::cout << "Chiffrement RSA terminé !" << std::endl;
            break;
        }
        case 4: {
            std::string clePublique, clePrivee, fichierChiffre, fichierDechiffre;
            std::cout << "Entrez le chemin de la clé publique : ";
            std::getline(std::cin, clePublique);
            std::cout << "Entrez le chemin de la clé privée : ";
            std::getline(std::cin, clePrivee);
            std::cout << "Entrez le chemin du fichier chiffré : ";
            std::getline(std::cin, fichierChiffre);
            std::cout << "Entrez le chemin du fichier déchiffré en sortie : ";
            std::getline(std::cin, fichierDechiffre);
            crypter.RSADcrypt(clePublique, clePrivee, fichierChiffre, fichierDechiffre);
            std::cout << "Déchiffrement RSA terminé !" << std::endl;
            break;
        }
        case 5: {
            std::string fichierEntree;
            std::cout << "Entrez le chemin du fichier à hacher : ";
            std::getline(std::cin, fichierEntree);
            std::string hachage = crypter.Hashfile(fichierEntree);
            std::cout << "Hachage du fichier (SHA-256) : " << hachage << std::endl;
            break;
        }
        case 6: {
            std::string fichierEntree, hachageEntree;
            std::cout << "Entrez le chemin du fichier à vérifier : ";
            std::getline(std::cin, fichierEntree);
            std::cout << "Entrez le hachage à vérifier : ";
            std::getline(std::cin, hachageEntree);
            bool valide = crypter.HashVerify(fichierEntree, hachageEntree);
            if (valide) {
                std::cout << "Vérification du hachage réussie !" << std::endl;
            }
            else {
                std::cout << "Échec de la vérification du hachage !" << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Fermeture..." << std::endl;
            break;
        default:
            std::cout << "Option invalide, essayez à nouveau." << std::endl;
        }
    }

    return 0;
}
