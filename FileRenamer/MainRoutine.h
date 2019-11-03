#pragma once
#include <string>
#include <iostream>
#include <filesystem>

int mainRoutine(std::string rootPath, std::string dependent);
void messageConsole(std::string var);
void errorConsole(std::string var);