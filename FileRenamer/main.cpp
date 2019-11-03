#include <string>
#include <iostream>
#include "MainRoutine.h"
#include <stdexcept>
/*
Error Codes
	-1 Invalid amount of arguments
	-2 Arguments too large
	1 Help context called

*/

int main(int argc, char* argv[])
{
	if (argc > 3 && argc < 2)
	{
		messageConsole("Invalid argument count, use /?");
		return -1;
	}

	if (std::string(argv[2]) == std::string("/?"))
	{
		messageConsole("Help dialogue enabled");
		messageConsole("Usage:");
		messageConsole("All files detected under the filepath given will be renamed with a GUID");
		messageConsole("Arg1 is the root path");
		messageConsole("Arg2 if set to DEPENDENT=TRUE, deactivates output messages");
		return 1;
	}

	// Sanitize, formed to std::string at size
	if (std::string(argv[1]).size() > std::string(argv[1]).max_size() && std::string(argv[2]).size() > std::string(argv[2]).max_size())
	{
		messageConsole("Input too large");
		return -2;
	}

	int programExit;
	programExit = mainRoutine(std::string(argv[1]), std::string(argv[2]));

	return programExit;
}