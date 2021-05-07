#pragma once
#include <vector>
#include <filesystem>

class filetransfer
{
protected:
	std::vector<std::filesystem::path> src;//ファイル
	std::filesystem::path destDir;//ディレクトリ
public:
	void RegisterSrc(std::filesystem::path);
	void RegisterDest(std::filesystem::path);
	int FileTransfer();
};