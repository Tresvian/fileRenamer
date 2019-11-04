#include <string>
#include <iostream>
#include "MainRoutine.h"
#include <stdexcept>
/*
Purpose of this program is to be a recursive file renamer. Given a path, it will go through all the folders and rename each file with a GUID.

Error Codes
	-1 Invalid amount of arguments
	-2 Arguments too large
	-3 Root path is not a directory
	1 Help context called
*/

int main(int argc, char* argv[])
{
	if (argc > 3 || argc < 2)
	{
		std::cerr << "Invalid argument count, use /?" << std::endl;
		return -1;
	}

	if (std::string(argv[1]) == std::string("/?"))
	{
		std::cout << "Help dialogue enabled" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "All files detected under the filepath given will be renamed with a GUID" << std::endl;
		std::cout << "Arg1 is the root path" << std::endl;
		std::cout << "Arg2 if set to DEPENDENT=TRUE, deactivates output messages" << std::endl;
		return 1;
	}

	int programExit;


	if (argc == 2)
	{
		// Sanitize, formed to std::string at size
		if (std::string(argv[1]).size() > std::string(argv[1]).max_size())
		{
			std::cerr << "Input too large" << std::endl;
			return -2;
		}
		// Program start
		programExit = mainRoutine(std::string(argv[1]), std::string("DEPENDENT=FALSE"));
	}
	else
	{
		// Sanitize, formed to std::string at size
		if (std::string(argv[1]).size() > std::string(argv[1]).max_size() || std::string(argv[2]).size() > std::string(argv[2]).max_size())
		{
			std::cerr << "Input too large" << std::endl;
			return -2;
		}
		// Program start
		programExit = mainRoutine(std::string(argv[1]), std::string(argv[2]));
	}

	return programExit;
}