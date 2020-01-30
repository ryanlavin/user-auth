#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "CopyLoginFile.h"

LoginFile::LoginFile(const char* filePath){
	//std::vector<std::string> Usernames;
	//std::vector<std::string> Passwords;

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
		//(Usernames.push_back(Username));
		//(Passwords.push_back(Password));
		list.push_back(newAccount);
	}

	std::cout << list.size() << std::endl;
/*
	for(int i = 0; i < Usernames.size(); i++){
		std::cout <<  << std::endl;
	}
	*/
}

