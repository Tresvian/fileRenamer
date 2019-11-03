#include "MainRoutine.h"
#include "guid.h"

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
		indexOf = toString.find_last_of("\\");

		std::string newName = toString.substr(0, indexOf);
		newName += createGuid();

		std::cout << "Renamed " << toString << " to " << newName << std::endl;
		fs::rename(p, fs::path(newName));
	}

	return 0;
}


static void recursiveSearch(fs::path path, std::vector<fs::path>& outputFiles, int maxDepth)
{
	std::cout << "Searched: " << path << std::endl;

	if (maxDepth == MAXDEPTH)
		std::cerr << "Hit max depth: " << path << std::endl;
	else if (fs::is_directory(path))
		recursiveSearch(path, outputFiles, maxDepth + 1);
	else if (fs::is_regular_file(path))
		outputFiles.push_back(path);
	else
		std::cerr << "Error with: " << path << std::endl;
}