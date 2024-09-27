#include "Crypter.h"
#include "iostream"

/**
 * @brief Constructeur de la classe Crypter.
 * Affiche le mot "CONSTRUCTEUR" en utilisant des couleurs spécifiques dans la console.
 */
Crypter::Crypter()
{
    std::cout << "\033[38;5;196mC" // Rouge
        << "\033[38;5;46mO"  // Vert
        << "\033[38;5;226mN" // Jaune
        << "\033[38;5;21mS"  // Bleu
        << "\033[38;5;201mT" // Magenta
        << "\033[38;5;51mR"  // Cyan
        << "\033[38;5;202mU" // Orange
        << "\033[38;5;118mC" // Vert clair
        << "\033[38;5;220mT" // Jaune doré
        << "\033[38;5;33mE"  // Bleu foncé
        << "\033[38;5;207mU" // Rose
        << "\033[38;5;81mR"  // Bleu ciel
        << "\033[0m"         // Réinitialisation des couleurs
        << std::endl;
}

/**
 * @brief Destructeur de la classe Crypter.
 * Affiche le mot "DESTRUCTEUR" en utilisant des couleurs spécifiques dans la console.
 */
Crypter::~Crypter()
{
    std::cout << "\033[38;5;196mD"  // Rouge vif
        << "\033[38;5;46mE"   // Vert vif
        << "\033[38;5;226mS"  // Jaune vif
        << "\033[38;5;21mT"   // Bleu vif
        << "\033[38;5;201mR"  // Magenta
        << "\033[38;5;51mU"   // Cyan
        << "\033[38;5;202mC"  // Orange vif
        << "\033[38;5;118mT"  // Vert clair
        << "\033[38;5;220mE"  // Jaune doré
        << "\033[38;5;33mU"   // Bleu foncé
        << "\033[38;5;207mR"  // Rose vif
        << "\033[0m"          // Réinitialisation des couleurs
        << std::endl;
}

/**
 * @brief Chiffre un fichier en utilisant AES-256.
 *
 * @param PathsaveKey Chemin où enregistrer la clé AES générée.
 * @param File Chemin du fichier à chiffrer.
 * @param OutputFile Chemin du fichier chiffré en sortie.
 */
void Crypter::AEScrypt(const std::string PathsaveKey, const std::string File, const std::string OutputFile) {

    AesGestion AES;

    AES.GenerateAESKey();
    AES.SaveAESKeyToFile(PathsaveKey);

    AES.EncryptFileAES256(File, OutputFile);
}

/**
 * @brief Déchiffre un fichier chiffré avec AES-256.
 *
 * @param PathsaveKey Chemin du fichier contenant la clé AES.
 * @param CryptFile Chemin du fichier chiffré.
 * @param FileDecrypt Chemin du fichier déchiffré en sortie.
 */
void Crypter::AEScryptusingkey(const std::string PathsKey, const std::string File, const std::string OutputFile) {

    AesGestion AES;
    AES.LoadAESKeyFromFile(PathsKey);
    AES.EncryptFileAES256(File, OutputFile);
}
void Crypter::AESDecrypt(const std::string PathsaveKey, const std::string CryptFile, const std::string FileDecrypt) {

    AesGestion AES;
    AES.LoadAESKeyFromFile(PathsaveKey);
    AES.DecryptFileAES256(CryptFile, FileDecrypt);
}

/**
 * @brief Chiffre un fichier en utilisant RSA.
 *
 * @param SavePublic Chemin où enregistrer la clé publique.
 * @param SavePrivate Chemin où enregistrer la clé privée.
 * @param File Chemin du fichier à chiffrer.
 * @param OutputFile Chemin du fichier chiffré en sortie.
 */
void Crypter::RSAcrypt(const std::string SavePublic, const std::string SavePrivate, const std::string File, const std::string OutputFile) {
    RsaGestion RSA;

    RSA.generationClef(SavePublic, SavePrivate, 2048);
    RSA.chiffrementFichier(File, OutputFile, true);
}

void Crypter::RSAcryptusingsave(const std::string SavePublic, const std::string SavePrivate, const std::string File, const std::string OutputFile) {
    RsaGestion RSA;
    RSA.chargementClefs(SavePublic, SavePrivate);
    RSA.chiffrementFichier(File, OutputFile, true);
}

/**
 * @brief Déchiffre un fichier chiffré avec RSA.
 *
 * @param Public Chemin du fichier contenant la clé publique.
 * @param Private Chemin du fichier contenant la clé privée.
 * @param CryptFile Chemin du fichier chiffré.
 * @param OutputFile Chemin du fichier déchiffré en sortie.
 */
void Crypter::RSADcrypt(const std::string Public, const std::string Private, const std::string CryptFile, const std::string OutputFile) {

    RsaGestion RSA;

    RSA.chargementClefs(Public, Private);
    RSA.dechiffrementFichier(CryptFile, OutputFile, true);
}

/**
 * @brief Calcule le hachage SHA-256 d'un fichier.
 *
 * @param inputfile Chemin du fichier à hacher.
 * @return std::string Le hachage SHA-256 du fichier.
 */
std::string Crypter::Hashfile(std::string inputfile) {
    HashGestion HAS;

    return HAS.CalculateFileSHA256(inputfile);
}

/**
 * @brief Vérifie si le hachage d'un fichier correspond au hachage donné.
 *
 * @param inputefile Chemin du fichier à vérifier.
 * @param inputHash Hachage à comparer.
 * @return true Si les hachages correspondent.
 * @return false Si les hachages ne correspondent pas.
 */
bool Crypter::HashVerify(std::string inputefile, std::string inputHash) {

    HashGestion HAS;

    std::string FileHash = HAS.CalculateFileSHA256(inputefile);

    if (inputHash == FileHash) {
        return true;
    }
    else {
        return false;
    }
}
