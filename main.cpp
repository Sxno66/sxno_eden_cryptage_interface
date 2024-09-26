
#include <iostream>
#include"Crypter.h"
#include <fstream>

int main()
{

	Crypter crp;
	crp.AEScrypt("key.txt", "TEST.txt", "msg.txt");



}