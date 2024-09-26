#pragma once

#include"Aesgestion.h"
#include"HashGestion.h"
#include"RsaGestion.h"
#include"iostream"


class Crypter {


	public:
		Crypter();
		~Crypter();

		void AEScrypt(const std::string PathsaveKey, const std::string File, const std::string OutputFile);
		void RSAcrypt();

		

	private:





	protected:




};
