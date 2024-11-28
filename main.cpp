// ImageCropper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ImageCropper.h"
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

Mat image;
Mat cropped_image;
string directory = ""; // Add a directory for your screenshots
int FileName = 1;
string extension = ".png";
int CroppedName = 1;

ImageCropper* imageCropper = new ImageCropper();
ImageRename* imageRename = new ImageRename();

// Make a folder (name: Final) in directory
// Select all images, rename it to 1. Then, all images will be renamed to 1 (1), 1 (2), ...


int main()
{
    while (true) {

        image = imageCropper->loadImages(directory,extension,image,std::to_string(FileName));

        if (image.empty()) {
            cerr << "Could not open or find the image!" << endl;
            break;
        }

        cropped_image = imageCropper->cropImages(image,cropped_image);
        imageCropper->saveCroppedImages(CroppedName,directory,extension,cropped_image);
        CroppedName++;
        FileName++;
    }

    string csvFilePath = directory + "Rename.csv"; // CSV file path

    imageRename->loadCSV(csvFilePath,directory);
    imageRename->RenameFileName(directory, extension);
    return 0;
}