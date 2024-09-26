#include"Crypter.h"
#include"iostream"



Crypter::Crypter()
{
	std::cout << "Constructeur par defautl du Hash" << std::endl;
}

Crypter::~Crypter()
{
	std::cout << "Desctructeur par defautl du hasg" << std::endl;
}

void Crypter::AEScrypt(const std::string PathsaveKey, const std::string File, const std::string OutputFile){

	AesGestion AES;

	AES.GenerateAESKey();
	AES.SaveAESKeyToFile(PathsaveKey);

	AES.EncryptFileAES256(File, OutputFile);
	
}
