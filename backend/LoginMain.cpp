#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


int main(){
	std::string Username;
	std::string line;
	std::stringstream current;
	std::ifstream ifstream;
	std::string Password;
	std::string PasswordPlaceholder;
	std::string UsernamePlaceholder;
	std::vector <std::string> Usernames;
	std::vector <std::string> Passwords;

	ifstream.open("Login.txt");
	if(!ifstream){
		std::cout << "Error opening file, please try again" << std::endl;
		return 0;
	}
	while(std::getline(ifstream,line)){
		current.clear();
	        current << line;
		current >> UsernamePlaceholder;
		current >> PasswordPlaceholder;
		Usernames.push_back(UsernamePlaceholder);
		Passwords.push_back(PasswordPlaceholder);
	}

	for(int i = 0; i < Usernames.size(); i++){
		std::cout << Usernames.at(i) << " " << Passwords.at(i) << std::endl;
	}

	ifstream.close();


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

	if(Register == true){
		int VectorSize;
		std::cout << "Please enter your email: ";
		std::cin >> UsernamePlaceholder;
		std::cout << "Now please enter your password: ";
		std::cin >> PasswordPlaceholder;
		std::fstream ofstream;
		ofstream.open("Login.txt", std::ios::in | std::ios::out);
		if(!ofstream){
			std::cout << "File failed to open, please try again" << std::endl;
			return 0;
		}
		ifstream.open("Login.txt");
		for(int i = 0; i < Usernames.size(); i++){
			while(std::getline(ofstream, line)){
				VectorSize++;
				if(VectorSize == Usernames.size()){
					ofstream << UsernamePlaceholder << " " << PasswordPlaceholder;
					ofstream.close();
				}	
			}
		}
	//	ofstream << UsernamePlaceholder << " " << PasswordPlaceholder;

	}


	return 0;
}




































