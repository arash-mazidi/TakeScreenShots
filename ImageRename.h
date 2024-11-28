#pragma once
#include <string>
#include <vector>

using namespace std;

class ImageRename
{
public:
	string getNextFileName(const string& fileName);
	void loadCSV(const string& csvFilePath, string);
	void RenameFileName(string , string);
};

