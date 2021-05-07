#pragma once
#include <filesystem>
#include <vector>

class filedelivery
{
private:
	std::filesystem::path dest;
	std::filesystem::path person;
	std::filesystem::path town;
	std::vector<std::filesystem::path> from;
	std::vector < std::filesystem::path> baggage;
	std::vector<std::filesystem::path> candidate;

public:
	filedelivery(int argc, std::vector < std:: string > argv);
	std::vector<std::filesystem::path> CandidateArray();
	std::vector<std::filesystem::path> BaggageArray();
	std::vector<std::filesystem::path> FromArray();
	std::filesystem::path Destination();
	void DestSet(int );
	void DestSet(std::filesystem::path);
	void SendBaggage();
	bool CheckBaggage();
};

