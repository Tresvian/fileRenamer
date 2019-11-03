#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#define MAXDEPTH 20

int mainRoutine(std::string rootPath, std::string dependent);
void recursiveSearch(std::experimental::filesystem::path path, std::vector<std::experimental::filesystem::path>& outputFiles, int maxDepth);