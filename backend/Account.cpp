#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "CopyLogin.h"
#include "CopyLoginFile.h"


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
		std::cout << Account::Login() << " is the answer" << std::endl;;
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
	
	
	std::cout << "Please enter your email: " << std::endl;
	for(int i = 0; i < 5; i++){
		std::cin >> Username;
		if(Username.length() == 0){
			std::cout << "Invalid input, please try again" << std::endl;
			continue;
		}
	}
	it = MyMap.find(Username);
	if(it != MyMap.end()){
		std::cout << "You already have an account, please login now" << std::endl;
		return false;
	}
	
	std::cout << "Please enter a password" << std::endl;
	std::cin >> Password;
	if(Password.length() == 0){
		std::cout << "Invalid input, please try again" << std::endl;
		return false;
	}
	
return true;		
}	

