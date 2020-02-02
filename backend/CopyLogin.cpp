#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "CopyLoginFile.h"
#include "CopyLogin.h"

Account::Account(std::string Username, std::string Password){
	this->Username = Username;
	this->Password = Password;
}

Account::~Account(){
//Nothing to delete
}

std::string Account::GetUsername(){
	return this->Username;
}

std::string Account::GetPassword(){
	return this->Password;
}


/*
void Account::Prompt(){
	char response;
	std::cout << "Do you have an account? (Y/n)" << std::endl;
	std::cin >> response;
	if(response != 'Y' && response != 'n' && response != 'y'){
		std::cout << "Invalid input, restart the program and try again" << std::endl;
		return;
	}
	if(response == 'Y' || response == 'y'){
		std::cout << "Account::Login will go here" << std::endl;
		return;
	}
	if(response == 'N' || response == 'n'){
		std::cout << "Would you like to create an account? (Y/n)" << std::endl;
		std::cin >> response;
		if(response != 'Y' && response != 'n' && response != 'y'){
			throw "Invalid input, restart the program and try again";
		}
		if(response == 'Y' || response == 'y'){
			std::cout << "Account::Register would go here" << std::endl;
			return;
		}
		if(response == 'N' || response == 'n'){
			throw "Quitting program...";
		}
	}
*/

/*
void Account::Login(){
		do {
			int i;
			std::cout << "Enter a username" << std::endl;
			std::cin >> Username;
			if(std::map<
*/
/*	
			for(int j = 0; j < Usernames.size(); j++){
				if(Username == Usernames.at(j)){
					bool UsernameEntered = true;
					while(UsernameEntered == true){
						int AttemptsLeft;
						std::cout << "Enter a password" << std::endl;
						std::cin >> Password;
						for(AttemptsLeft = Usernames.size()+1; AttemptsLeft > 0; AttemptsLeft--){
							if(Password !=Passwords.at(j)){
								std::cout << "Password incorrect, please try again" << std::endl;
								std::cin >> Password;
								continue;
							}
							else if(Password == Passwords.at(j)){
								std::cout << "Connected" << std::endl;
								return 0;
							}
						}
						UsernameEntered = false;
					}
				}
				else if(Username != Usernames.at(j)){
					i++;
					continue;
				}
				else if(Username != Usernames.at(j) && j >= Usernames.size()){
					std::cout << "Username incorrect, please try again" << std::endl;
					break;
				}
			}


			if(i >= Usernames.size()+1){
				std::cout << "Too many attempts, quitting now" << std::endl;
				return 0;
			}

		}while(Login == true);
	}
*/
//}
/*
void Account::Register(){
	if(Register == true){
		int VectorSize;
		std::cout << "Please enter your email: ";
		std::cin >> UsernamePlaceholder;
		std::cout << "Now please enter your password: ";
		std::cin >> PasswordPlaceholder;
		fstream.open("Login.txt", std::ios::in | std::ios::out);
		if(!fstream){
			std::cout << "File failed to open, please try again" << std::endl;
			return 0;
		}
		fstream.open("Login.txt");
		for(int i = 0; i < Usernames.size(); i++){
			while(std::getline(fstream, line)){
				VectorSize++;
				if(VectorSize == Usernames.size()){
					fstream << UsernamePlaceholder << " " << PasswordPlaceholder;
					fstream.close();
				}
			}
		}
	}
}
*/

/*
void GetFstream(std::fstream fstream){
	this->fstream = fstream;
	return;
}
*/
