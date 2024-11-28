#include "ImageRename.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std;
using namespace cv;

vector<string> oldNames;
vector<string> newNames;

void ImageRename::loadCSV(const string& csvFilePath, string directory) {
    ifstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        cerr << "Could not open the CSV file: " << csvFilePath << endl;
        return;
    }

    string line;

    // Read each line from the CSV file
    while (getline(csvFile, line)) {
        stringstream ss(line);
        string oldName, newName;

        // Get the old and new names from the CSV
        if (getline(ss, oldName, ',') && getline(ss, newName, ',')) {
            // Trim whitespace
            oldName.erase(remove_if(oldName.begin(), oldName.end(), ::isspace), oldName.end());
            newName.erase(remove_if(newName.begin(), newName.end(), ::isspace), newName.end());

            // Store names in the respective vectors
            oldNames.push_back(oldName);
            newNames.push_back(newName);
        }
    }
    csvFile.close();
}

////////////////////////////////////////////////////////////////////////////////
void ImageRename::RenameFileName(string directory, string extension)
{
    // Rename
    for (size_t i = 0; i < oldNames.size(); i++) {
        // Construct full file paths
        string oldFilePath = directory + oldNames[i] + extension;
        string newFilePath = directory + "Final\\" + newNames[i] + extension;

        // Attempt to rename the file
        rename(oldFilePath.c_str(), newFilePath.c_str());
    }
}