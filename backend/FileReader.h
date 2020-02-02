#ifndef COPYLOGINFILE_H
#define COPYLOGINFILE_H

#include <vector>
#include "CopyLogin.h"
#include <map>

class FileReader {

public:
	static std::map<std::string, std::string> OpenDatabase(const char* filePath);

};

#endif

