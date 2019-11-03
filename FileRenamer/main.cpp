#include <string>
#include <iostream>
#include "MainRoutine.h"
#include <stdexcept>
/*
Error Codes
	-1 Invalid amount of arguments
	-2 Arguments too large
	-3 Root path is not a directory
	1 Help context called

*/

int main(int argc, char* argv[])
{
	if (argc > 3 && argc < 2)
	{
		std::cerr << "Invalid argument count, use /?" << std::endl;
		return -1;
	}

	if (std::string(argv[2]) == std::string("/?"))
	{
		std::cout << "Help dialogue enabled" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "All files detected under the filepath given will be renamed with a GUID" << std::endl;
		std::cout << "Arg1 is the root path" << std::endl;
		std::cout << "Arg2 if set to DEPENDENT=TRUE, deactivates output messages" << std::endl;
		return 1;
	}

	// Sanitize, formed to std::string at size
	if (std::string(argv[1]).size() > std::string(argv[1]).max_size() && std::string(argv[2]).size() > std::string(argv[2]).max_size())
	{
		std::cerr << "Input too large" << std::endl;
		return -2;
	}

	int programExit;

	if (argc == 2)
		programExit = mainRoutine(std::string(argv[1]), std::string(argv[2]));
	else
		programExit = mainRoutine(std::string(argv[1]), std::string("DEPENDENT=FALSE"));

	return programExit;
}