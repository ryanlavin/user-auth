#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include "Account.h"
#include <map>

class FileReader {

public:
	static std::map<std::string, std::string> OpenDatabase(const char* filePath);
	static void WriteToDatabase(std::map<std::string, std::string> MyMap);

};
#endif

