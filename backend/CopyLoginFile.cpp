#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "CopyLoginFile.h"

LoginFile::LoginFile(const char* filePath){
	std::fstream fstream;

	fstream.open(filePath);
	if(!fstream){
		throw "Error opening file, please try again";
	}
	std::string line;
	std::stringstream current;
	std::string Username;
	std::string Password;
	while(std::getline(fstream,line)){
		current.clear();
	        current << line;
		current >> Username;
		current >> Password;
		Account newAccount(Username, Password);
		list.push_back(newAccount);
	}

	std::cout << list.size() << std::endl;
}

