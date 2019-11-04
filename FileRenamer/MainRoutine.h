#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#define MAXDEPTH 20
/*
This is the main execution of the program after called by main.cpp

The paths is passed, parsed, and then creates a list of files to start renaming.
Each file will have a RPC call to win32 API to get a unique GUID.
*/
int mainRoutine(std::string rootPath, std::string dependent);
void recursiveSearch(std::experimental::filesystem::path path, std::vector<std::experimental::filesystem::path>& outputFiles, int maxDepth);