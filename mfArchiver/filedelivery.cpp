#include "filedelivery.h"

#define NODATA "Data does not exist"

filedelivery::filedelivery(int argc, std::vector<std::string> vArgv) {
	//‰×•¨‚ª‘¶İ‚·‚é?
	if (argc < 2) {
		//‚µ‚È‚¢
		filedelivery::person = vArgv[0];
		filedelivery::town = person.parent_path();

		for (const std::filesystem::directory_entry& p : std::filesystem::directory_iterator(filedelivery::town)) {
			if (p.is_directory()) {
				candidate.push_back(p);
			}
		}
	}else {
		//‚·‚é
		filedelivery::person = vArgv[0];
		filedelivery::town = person.parent_path();
		
		for (int i = 1; i < argc; i++) {
			baggage.push_back(vArgv[i]);
		}
		for (int i = 1; i < argc; i++) {
			from.push_back(vArgv[i]);
		}
		for (const std::filesystem::directory_entry& p : std::filesystem::directory_iterator(filedelivery::town)) {
			if (p.is_directory()) {
				candidate.push_back(p);
			}
		}
	}
	return;
}

std::vector<std::filesystem::path> filedelivery::CandidateArray() {
	return candidate;
}

std::vector<std::filesystem::path> filedelivery::BaggageArray()
{
	return filedelivery::baggage;
}

std::vector<std::filesystem::path> filedelivery::FromArray() {
	return filedelivery::from;
}

std::filesystem::path filedelivery::Destination() {
	return filedelivery::dest;
}

void filedelivery::DestSet(int x) {
	filedelivery::dest = candidate[x];
	return;
}

void filedelivery::DestSet(std::filesystem::path p) {
	filedelivery::dest = p;
	return;
}

void filedelivery::SendBaggage() {
	for (int i = 0; i < filedelivery::baggage.size();i++) {
		std::string fileName = "\\";
		fileName += filedelivery::baggage[i].filename().string();
		filedelivery::baggage[i] = filedelivery::dest;
		filedelivery::baggage[i] += fileName;
		std::filesystem::rename(filedelivery::from[i], filedelivery::baggage[i]);
	}
	return;
}

bool filedelivery::CheckBaggage() {
	for (std::filesystem::path p : filedelivery::baggage) {
		if (!std::filesystem::exists(p)) {
			return false;
		}
	}
	return true;
}