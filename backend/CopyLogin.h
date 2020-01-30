#include <string>
#ifndef LOGIN_H
#define LOGIN_H



class Account {

public:
	Account(std::string Username, std::string Password);
	std::string GetUsername();
	std::string GetPassword();
	~Account();
	void static Prompt();

private:
	std::string Username;
	std::string Password;
};
#endif
