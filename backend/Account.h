#include <string>
#ifndef LOGIN_H
#define LOGIN_H
#include <map>


class Account {

public:
	Account(const char* filePath);
	~Account();
	void Prompt();
	bool Login();
	bool Register();

private:
	std::map<std::string, std::string> MyMap;
	const char* filePath;
};
#endif
