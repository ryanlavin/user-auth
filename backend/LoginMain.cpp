#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


int main(){
	std::string Username;
	std::string line;
	std::stringstream current;
	std::ifstream stream;
	std::string Password;
	std::string PasswordPlaceholder;
	std::string UsernamePlaceholder;
	std::vector <std::string> Usernames;
	std::vector <std::string> Passwords;

	stream.open("Login.txt");
	if(!stream){
		std::cout << "Error opening file, please try again" << std::endl;
		return 0;
	}
	while(std::getline(stream,line)){
		current.clear();
	        current << line;
		current >> UsernamePlaceholder;
		current >> PasswordPlaceholder;
		Usernames.push_back(UsernamePlaceholder);
		Passwords.push_back(PasswordPlaceholder);
	}


/*
	while(true){
		int i;
		std::cout << "Enter a username" << std::endl;
		std::cin >> Username;
		if(Username == Usernames.at(i)){
			std::cout << "Enter a password" << std::endl;
			std::cin >> Password;
			if(Password != Passwords.at(i)){
				std::cout << "Password incorrect, please try again" << std::endl;
			}
			else if(Password == Passwords.at(i)){
				std::cout << "Connected" << std::endl;
				break;
			}
		}
		else if(Username != Usernames.at(i) && i >= Usernames.size()){
			std::cout << "Username not in system, please restart and try again" << std::endl;
			return 1;
		}
		else if(Username != Usernames.at(i)){
			i++;
			std::cout << Usernames.size() << std::endl;
		}
*/
	
	bool Register = false;
	bool Login = false;
	char response;
	std::cout << "Do you have an account? (Y/n)" << std::endl;
	std::cin >> response;
	if(response != 'Y' && response != 'n' && response != 'y'){
		std::cout << "Invalid input, restart the program and try again" << std::endl;
		return 0;
	}
	if(response == 'Y' || response == 'y'){
		Login = true;		
	}
	if(response == 'N' || response == 'n'){
		Login = false;
		std::cout << "Would you like to create an account? (Y/n)" << std::endl;
		std::cin >> response;
		if(response != 'Y' && response != 'n' && response != 'y'){
			std::cout << "Invalid input, restart the program and try again" << std::endl;
			return 0;
		}
		if(response == 'Y' || response == 'y'){
			Register = true;
			Login = false;
		}
		if(response == 'N' || response == 'n'){
			std::cout << "Quitting program..." << std::endl;
			return 0;
		}
	}




	if(Login == true){
		do {
			int i;
			std::cout << "Enter a username" << std::endl;
			std::cin >> Username;
			for(int j = 0; j < Usernames.size(); j++){
				if(Username == Usernames.at(j)){
					bool UsernameEntered = true;
					while(UsernameEntered == true){
						int AttemptsLeft = 5;
						std::cout << "Enter a password" << std::endl;
						std::cin >> Password;
						for(int AttemptsLeft = 5; AttemptsLeft > 0; AttemptsLeft--){
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
			if(i >= 5){
				std::cout << "Too many attempts, quitting now" << std::endl;
				return 0;
			}

		}while(Login == true);
	}

	if(Register == true){
		std::cout << "Registering process not computed yet, please try again later" << std::endl;
		return 0;
	}


	return 0;
}




































