#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Account.h"
#include "FileReader.h"


Account::Account(const char* filePath){
	this->MyMap = FileReader::OpenDatabase(filePath);
	this->filePath = filePath;
}


Account::~Account(){
//Nothing to delete
}

void Account::Prompt(){
	char response;
	std::cout << "Do you have an account? (Y/n)" << std::endl;
	std::cin >> response;
	if(response != 'Y' && response != 'n' && response != 'y'){
		std::cout << "Invalid input, restart the program and try again" << std::endl;
		return;
	}
	if(response == 'Y' || response == 'y'){
		bool bool_login = Account::Login();
		if(bool_login == true){
			std::cout << "Connected" << std::endl;
			return;
		}	
		return;
	}
	if(response == 'N' || response == 'n'){
		std::cout << "Would you like to create an account? (Y/n)" << std::endl;
		std::cin >> response;
		if(response != 'Y' && response != 'n' && response != 'y'){
			throw "Invalid input, restart the program and try again";
		}
		if(response == 'Y' || response == 'y'){
			std::cout << Account::Register() << " yo yo yo" << std::endl;
			return;
		}
		if(response == 'N' || response == 'n'){
			throw "Quitting program...";
		}
	}
}


bool Account::Login(){
	std::string Username;
	std::string Password;
	std::map<std::string, std::string>::iterator it;

	std::cout << "Enter a username" << std::endl;
	std::cin >> Username;

	it = MyMap.find(Username);
	if(it == MyMap.end())
		return false;
	std::cout << "Enter a password" << std::endl;
	std::cin >> Password;

	if(MyMap[Username] != Password)
		return false;
	return true;

}


bool Account::Register(){
	std::string Username;
	std::string Password;
	std::map<std::string, std::string>::iterator it;
	std::fstream fstream;
	std::stringstream current;
	std::string line;
	
	std::cout << "Please enter your email: " << std::endl;
	for(int i = 0; i < 5; i++){
		std::cin >> Username;
		if(Username.empty()){
			std::cout << "Invalid input, please try again" << std::endl;
			continue;
		}
		else
			break;
	}
	it = MyMap.find(Username);
	if(it != MyMap.end()){
		std::cout << "You already have an account, please login now" << std::endl;
		return false;
	}
	
	std::cout << "Please enter a password" << std::endl;
	std::cin >> Password;
	if(Password.empty()){
		std::cout << "Invalid input, please try again" << std::endl;
		return false;
	}
	MyMap.insert(std::pair<std::string,std::string>(Username,Password));
	fstream.open("Login.txt");
	if(!fstream){
		std::cout << "File failed to open" << std::endl;
		return false;
	}
	for(std::map<std::string, std::string>::iterator it = MyMap.begin();it != MyMap.end(); it++){
		std::string word = it->first;
		std::string word1 = it->second;
		fstream << word + " " + word1 + "\n";
	}	
	


//	fstream << "\n";
//	line = Username + " " + Password;
//	fstream << line + "\n";
/*
	while(std::getline(fstream, line)){
		if(fstream.eof()){
			current.clear();
			current << line;
			current >> Username;
			current >> Password;	
			std::cout << current << std::endl;
			current << fstream;
			fstream.close();
			break;
	       	} 
	}	
*/		
		
		/* for(std::map<std::string, std::string>::iterator it = MyMap.end(); it > MyMap.end(); it++){
		
	}
*/	


#ifdef DEBUG
	for(std::map<std::string, std::string>::iterator it = MyMap.begin();it != MyMap.end(); it++){
		std::string word = it->first;
		std::string word1 = it->second;
		std::cout << word << " " << word1 << std::endl;
	}	
#endif
	return true;		
}	

