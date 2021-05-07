#include "filetransfer.h"

void filetransfer::RegisterSrc(std::filesystem::path src){
	filetransfer::src.push_back(src);
}

void filetransfer::RegisterDest(std::filesystem::path destDir) {
	filetransfer::destDir = destDir;
}

int filetransfer::FileTransfer(){
	for (auto p : src) {
		std::filesystem::path newPath = filetransfer::destDir.string() + "\\" + p.filename().string();
		std::filesystem::rename(p, newPath);
	}
	return 0;
}
