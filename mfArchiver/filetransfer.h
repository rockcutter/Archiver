#pragma once
#include <vector>
#include <filesystem>

class filetransfer
{
protected:
	std::vector<std::filesystem::path> src;//�t�@�C��
	std::filesystem::path destDir;//�f�B���N�g��
public:
	void RegisterSrc(std::filesystem::path);
	void RegisterDest(std::filesystem::path);
	int FileTransfer();
};