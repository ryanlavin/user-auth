#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "FileReader.h"
#include <map>


std::map<std::string, std::string> FileReader::OpenDatabase(const char* filePath){
	std::fstream fstream;
	std::map<std::string, std::string> MyMap;
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
		MyMap.insert(std::pair<std::string,std::string>(Username,Password));
	}
	
#ifdef DEBUG
	for(std::map<std::string, std::string>::iterator it = MyMap.begin();it != MyMap.end(); it++){
		std::string word = it->first;
		std::string word1 = it->second;

		std::cout << word << " " << word1 << std::endl;
	}	
#endif	
	return MyMap;
}

void FileReader::WriteToDatabase(std::map<std::string, std::string> MyMap){
	std::fstream fstream;
	std::map<std::string, std::string>::iterator it;
	fstream.open("Login.txt");
	if(!fstream){
		throw "File failed to open";
	}
	for(std::map<std::string, std::string>::iterator it = MyMap.begin();it != MyMap.end(); it++){
		std::string word = it->first;
		std::string word1 = it->second;
		fstream << word + " " + word1 + "\n";
	}	
	

}
