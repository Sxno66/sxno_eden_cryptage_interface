#pragma once

#include"Aesgestion.h"
#include"HashGestion.h"
#include"RsaGestion.h"
#include"iostream"
//#include<sqlite3.h>


class Crypter {


	public:
		Crypter();
		~Crypter();

		void AEScrypt(const std::string PathsaveKey, const std::string File, const std::string OutputFile);
		void AESDecrypt(const std::string PathsaveKey, const std::string CryptFile, const std::string FileDecrypt);
		void AEScryptusingkey(const std::string PathsaveKey, const std::string File, const std::string OutputFile);

		void RSAcrypt(const std::string SavePublic, const std::string SavePrivate, const std::string File, const std::string OutputFile);
		void RSADcrypt(const std::string Public, const std::string Private, const std::string CryptFile, const std::string OutputFile);
		void RSAcryptusingsave(const std::string SavePublic, const std::string SavePrivate, const std::string File, const std::string OutputFile);

		std::string Hashfile(const std::string inputFile);
		bool HashVerify(const std::string inputeFile, const std::string InputHash);




	private:





	protected:




};
