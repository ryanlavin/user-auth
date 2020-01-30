#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int main(){
	std::string Username;
	std::string line;
	std::stringstream current;
	std::fstream fstream;
	std::ofstream ofstream;
	std::string Password;
	std::string PasswordPlaceholder;
	std::string UsernamePlaceholder;
	std::vector <std::string> Usernames;
	std::vector <std::string> Passwords;
	int VectorSize;
	int* ptr = &(VectorSize);
	
	fstream.open("Login.txt");
	if(!fstream){
		std::cout << "Error opening file, please try again" << std::endl;
		return 0;
	}
	while(std::getline(fstream,line)){
		current.clear();
	        current << line;
		VectorSize++;
		current >> UsernamePlaceholder;
		current >> PasswordPlaceholder;
		std::cout << UsernamePlaceholder << " " << PasswordPlaceholder << std::endl;
		Usernames.push_back(UsernamePlaceholder);
		Passwords.push_back(PasswordPlaceholder);
	}
	fstream.close();


// For testing the file stream
/*
	for(int i = 0; i < Usernames.size(); i++){
		std::cout << Usernames.at(i) << " " << Passwords.at(i) << std::endl;
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

	int i;
	std::cout << "Enter a username" << std::endl;
	if(Login == true){
		do {
			if(Username != Usernames.at(sqrt(i)) && i > 0){
				std::cout << "Please enter a valid email" << std::endl;
			}
			std::cin >> Username;
			for(int j = 0; j <= *ptr-1; j++){
				if(Username != Usernames.at(j)){
					i++;
				}
				else if(Username == Usernames.at(j)){
					bool UsernameEntered = true;
					while(UsernameEntered == true){
						int AttemptsLeft;
						std::cout << "Enter a password" << std::endl;
						std::cin >> Password;
						for(AttemptsLeft = *ptr; AttemptsLeft >= 0; AttemptsLeft--){
							if(Password !=Passwords.at(j)){
								if(AttemptsLeft == 1){
									std::cout << "Too many incorrect attempts, please restart the program and try again" << std::endl;
									return 0;
								}
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
				else if(Username != Usernames.at(j) && j < *ptr){
					std::cout << "Username incorrect, please try again" << std::endl;
					continue;
				}
			}
			if(i >= pow(*ptr, 2)){
				std::cout << "Too many attempts, quitting now" << std::endl;
				return 0;
			}

		}while(Login == true);
	}

	if(Register == true){
		std::cout << "Please enter your email: ";
		std::cin >> Username;
		std::cout << "Now please enter your password: ";
		std::cin >> Password;
		fstream.open("Login.txt");
		if(!fstream){
			std::cout << "File failed to open, please try again" << std::endl;
			return 0;
		}
		else if(fstream){
			for(int i = 0; i < Usernames.size(); i++){
				int VectorSizeCopy;
				while(std::getline(fstream, line)){
					VectorSizeCopy++;
					if(VectorSizeCopy == *ptr){
						fstream << Username << " " << Password << "\n";
						fstream.close();
						break;
					}	
				}
			}
		}
	}

	std::ifstream ifstream;	
	ifstream.open("Login.txt");
	if(!ifstream){
		std::cout << "Error opening file, please try again" << std::endl;
		return 0;
	}
	while(std::getline(ifstream,line)){
		current.clear();
	        current << line;
		current >> Username;
		current >> Password;
		std::cout << Username << " " << Password << std::endl;
	}
	ifstream.close();

		
	return 0;
}






















































