#include "MainRoutine.h"
#include "guid.h"

/*
This is the main execution of the program after called by main.cpp

The paths is passed, parsed, and then creates a list of files to start renaming.
Each file will have a RPC call to win32 API to get a unique GUID.
*/
namespace fs = std::experimental::filesystem;
int mainRoutine(std::string rootPath, std::string dependent)
{
	fs::path root = rootPath;

	unsigned long long int byteCounter = 0;
	int max = 0;
	std::vector<fs::path> fileList;

	recursiveSearch(rootPath, fileList, max);

	for (auto& p : fileList)
	{
		std::string toString = p.string();

		int indexOf = 0;
		indexOf = toString.find_last_of("/\\");

		byteCounter += fs::file_size(p);

		// Requires fixing stream, I believe.
		std::string fileType = "." + toString.substr(indexOf+1);

		std::string newName = "\\" + toString.substr(0, indexOf) + createGuid() + fileType;

		std::cout << "Renamed " << toString << " to " << newName << std::endl;
		fs::rename(p, fs::path(newName));
	}

	std::cout << "Total file sizes processed " << byteCounter << std::endl;

	return 0;
}


void recursiveSearch(fs::path path, std::vector<fs::path>& outputFiles, int maxDepth)
{
	// Recursion safe here. Max depth defined on MainRoutine.h in case symbolic links are occuring.
	std::cout << "Searched: " << path << std::endl;

	if (maxDepth == MAXDEPTH)
		std::cerr << "Hit max depth: " << path << std::endl;
	else if (fs::is_directory(path))
	{
		for (auto& p : fs::directory_iterator(path))
		{
			// Go one level deeper
			recursiveSearch(p, outputFiles, maxDepth + 1);
		}
	}
	// Found file, add to list for renaming.
	else if (fs::is_regular_file(path))
		outputFiles.push_back(path);
	else
		std::cerr << "Error with: " << path << std::endl;
}