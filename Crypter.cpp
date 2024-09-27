#include "Crypter.h"
#include "iostream"

/**
 * @brief Constructeur de la classe Crypter.
 * Affiche le mot "CONSTRUCTEUR" en utilisant des couleurs sp�cifiques dans la console.
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
        << "\033[38;5;220mT" // Jaune dor�
        << "\033[38;5;33mE"  // Bleu fonc�
        << "\033[38;5;207mU" // Rose
        << "\033[38;5;81mR"  // Bleu ciel
        << "\033[0m"         // R�initialisation des couleurs
        << std::endl;
}

/**
 * @brief Destructeur de la classe Crypter.
 * Affiche le mot "DESTRUCTEUR" en utilisant des couleurs sp�cifiques dans la console.
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
        << "\033[38;5;220mE"  // Jaune dor�
        << "\033[38;5;33mU"   // Bleu fonc�
        << "\033[38;5;207mR"  // Rose vif
        << "\033[0m"          // R�initialisation des couleurs
        << std::endl;
}

/**
 * @brief Chiffre un fichier en utilisant AES-256.
 *
 * @param PathsaveKey Chemin o� enregistrer la cl� AES g�n�r�e.
 * @param File Chemin du fichier � chiffrer.
 * @param OutputFile Chemin du fichier chiffr� en sortie.
 */
void Crypter::AEScrypt(const std::string PathsaveKey, const std::string File, const std::string OutputFile) {

    AesGestion AES;

    AES.GenerateAESKey();
    AES.SaveAESKeyToFile(PathsaveKey);

    AES.EncryptFileAES256(File, OutputFile);
}

/**
 * @brief D�chiffre un fichier chiffr� avec AES-256.
 *
 * @param PathsaveKey Chemin du fichier contenant la cl� AES.
 * @param CryptFile Chemin du fichier chiffr�.
 * @param FileDecrypt Chemin du fichier d�chiffr� en sortie.
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
 * @param SavePublic Chemin o� enregistrer la cl� publique.
 * @param SavePrivate Chemin o� enregistrer la cl� priv�e.
 * @param File Chemin du fichier � chiffrer.
 * @param OutputFile Chemin du fichier chiffr� en sortie.
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
 * @brief D�chiffre un fichier chiffr� avec RSA.
 *
 * @param Public Chemin du fichier contenant la cl� publique.
 * @param Private Chemin du fichier contenant la cl� priv�e.
 * @param CryptFile Chemin du fichier chiffr�.
 * @param OutputFile Chemin du fichier d�chiffr� en sortie.
 */
void Crypter::RSADcrypt(const std::string Public, const std::string Private, const std::string CryptFile, const std::string OutputFile) {

    RsaGestion RSA;

    RSA.chargementClefs(Public, Private);
    RSA.dechiffrementFichier(CryptFile, OutputFile, true);
}

/**
 * @brief Calcule le hachage SHA-256 d'un fichier.
 *
 * @param inputfile Chemin du fichier � hacher.
 * @return std::string Le hachage SHA-256 du fichier.
 */
std::string Crypter::Hashfile(std::string inputfile) {
    HashGestion HAS;

    return HAS.CalculateFileSHA256(inputfile);
}

/**
 * @brief V�rifie si le hachage d'un fichier correspond au hachage donn�.
 *
 * @param inputefile Chemin du fichier � v�rifier.
 * @param inputHash Hachage � comparer.
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
