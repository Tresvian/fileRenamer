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

		byteCounter += fs::file_size(p);

		std::string newName = toString.substr(0, indexOf);
		newName += createGuid();

		std::cout << "Renamed " << toString << " to " << newName << std::endl;
		fs::rename(p, fs::path(newName));
	}

	std::cout << "Total file sizes processed " << byteCounter << std::endl;

	return 0;
}


void recursiveSearch(fs::path path, std::vector<fs::path>& outputFiles, int maxDepth)
{
	std::cout << "Searched: " << path << std::endl;

	if (maxDepth == MAXDEPTH)
		std::cerr << "Hit max depth: " << path << std::endl;
	else if (fs::is_directory(path))
	{
		for (auto& p : fs::directory_iterator(path))
		{
			recursiveSearch(p, outputFiles, maxDepth + 1);
		}
	}
	else if (fs::is_regular_file(path))
		outputFiles.push_back(path);
	else
		std::cerr << "Error with: " << path << std::endl;
}