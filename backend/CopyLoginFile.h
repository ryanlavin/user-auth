#ifndef COPYLOGINFILE_H
#define COPYLOGINFILE_H

#include <vector>
#include "CopyLogin.h"
#include <map>

class LoginFile {

public:
	LoginFile(const char* filePath);


private:
	std::map<std::string, std::string> MyMap;

};


/*
template <Key ID, std::string Username, std::string Password>
class MappedAccount { 

public:
	MappedAccount(Key ID, std::string Username, std::string Password);
	~MappedAccount();
	virtual void clear() = 0;

	virtual void insert(const Key& ID, const Password& Username, const std::string& Password) = 0;



private:
	Key ID;
	std::string Username;
	std::string Password;
};
*/
#endif

