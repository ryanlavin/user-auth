#ifndef COPYLOGINFILE_H
#define COPYLOGINFILE_H

#include <vector>
#include "CopyLogin.h"


class LoginFile {

public:
	LoginFile(const char* filePath);


private:
//	std::vector<Usernames>;
//	std::vector<Passwords>;
	std::vector<Account> list;



};
#endif

