#pragma once
#include "filetransfer.h"
#include <string>
#include <ctime>

class archiver :public filetransfer
{
private:
	std::filesystem::path currentDir;
	std::filesystem::path exePath;
	std::vector<std::filesystem::path> targetFiles;
public:
	archiver(std::filesystem::path exePath);
	std::string CreateName_Time();
	void CreateDestDir(std::filesystem::path DirName);
	void ElectTargetDir(int);
	//in
	void RegisterTargetDir();
	//out
	std::vector<std::filesystem::path> TargetDirArray();
};

