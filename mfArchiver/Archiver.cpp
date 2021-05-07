#include "Archiver.h"

archiver::archiver(std::filesystem::path exePath) {
	archiver::exePath = exePath;
	archiver::currentDir = exePath.parent_path();

	archiver::RegisterTargetDir();
}

void archiver::RegisterTargetDir() {
	for (const std::filesystem::directory_entry& p : std::filesystem::directory_iterator(archiver::currentDir)) {
		if (p.is_directory()) {
			targetFiles.push_back(p);
		}
	}
}

void archiver::ElectTargetDir(int fileNum) {
	std::filesystem::path dest = archiver::targetFiles[fileNum].string() + "\\" + CreateName_Time();
	CreateDestDir(dest);
	filetransfer::RegisterDest(dest);
}

void archiver::CreateDestDir(std::filesystem::path DirName) {
	std::filesystem::create_directory(DirName);
}
 
std::vector<std::filesystem::path> archiver::TargetDirArray() {
	return targetFiles;
}

std::string archiver::CreateName_Time() {
	std::string name;

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	name += std::to_string(timeinfo.tm_year + 1900) + "_";
	name += std::to_string(timeinfo.tm_mon + 1) + "_";
	name += std::to_string(timeinfo.tm_mday) + "_";
	name += std::to_string(timeinfo.tm_hour) + "_";
	name += std::to_string(timeinfo.tm_min) + "_";
	name += std::to_string(timeinfo.tm_sec) + "_";

	return name;
}