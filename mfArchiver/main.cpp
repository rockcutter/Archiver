#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "Archiver.h"

#define VERSION "2.1"

#define APPNAME "Archiver"

#define DEBUG

//コマンド一覧
#define CMD_FILEOPEN "open"
#define CMD_EXIT "exit"

//プロトタイプ宣言
bool isNumber(std::string );
void CommandMode(char* argv[]);

int main(int argc, char* argv[]) {

	//初期表示--------------------------------------------------------------------------------------------
	std::cout << "Archiver by mf/rc" << std::endl << "version " << VERSION << std::endl;
	for (int i = 1; i < argc; i++) {
		std::cout << "argv: " << argv[i] << std::endl;
	}

#ifdef DEBUG
	std::cout << "argc: " << argc << std::endl;
#endif
	//-------------------------------------------------------------------------------------------------

	if (argc < 2) {
		CommandMode(argv);
		return 0;
	}

	int targetFileNum = -1;
	std::string in_buf;

	archiver arc(argv[0]);
	for (int i = 1; i < argc; i++) {
		arc.RegisterSrc(argv[i]);
	}
	if (arc.TargetDirArray().size() == 0) {
		std::cerr << "Target directory does not exitst" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < arc.TargetDirArray().size(); i++) {
		std::cout << "[" << i << "]: " << arc.TargetDirArray()[i].filename() << std::endl;
	}

	while (0 > targetFileNum && targetFileNum >= arc.TargetDirArray().size()) {
		std::cin >> in_buf;
		
		if (isNumber(in_buf)) {
			targetFileNum = std::stoi(in_buf);
		}
	}

	try {
		arc.ElectTargetDir(targetFileNum);
		arc.FileTransfer();
	}
	catch (std::filesystem::filesystem_error& err) {
		std::cerr << err.what() << std::endl;
		std::cout << "終了するにはEnterキーを押してください..." ;
		getchar();
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

bool isNumber(std::string str) {
	for (auto p : str) {
		if (!isdigit(p)) {
			return 0;
		}
	}
	return 1;
}

void CommandMode(char* argv[]) {
	std::string cmd;
	std::cout << "設定モード" << std::endl;

	while (cmd != CMD_EXIT) {
		std::cout << "command: ";
		std::cin >> cmd;

		if (cmd == CMD_FILEOPEN) {
			std::filesystem::path openPath = "explorer ";
			openPath += argv[0];
			std::system("explorer .");
			continue;
		}
	}
}