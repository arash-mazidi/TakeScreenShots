#include "ImageCropper.h"
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

Mat ImageCropper::loadImages(string directory, string extension,Mat image,string FileName)
{
    // Load the images
    cout << directory;
    image = imread(directory + FileName + extension);

    if (image.empty()) {
        cerr << "Could not open or find the image!" << endl;
    }
    else {
        cout << "Image loaded successfully!" << endl;
    }
    return image;
}

/////////////////////////////////////////////////////////////////////////////////

Mat ImageCropper::cropImages(Mat image, Mat cropped_image)
{
    // Define the region of interest (ROI) you want to crop
    // The region is defined as Rect(x, y, width, height)
    int x =1 ;  // X-coordinate of the top-left corner
    int y = 38;   // Y-coordinate of the top-left corner
    int width = 1282;  // Width of the cropping rectangle
    int height = 722; // Height of the cropping rectangle

    // Check if the cropping region is valid
    if (x >= 0 && y >= 0 && x + width <= image.cols && y + height <= image.rows) {
        Rect crop_region(x, y, width, height);
        cropped_image = image(crop_region); // Crop the image using the defined ROI
    }
    else {
        cerr << "Error: Cropping region is out of image bounds!" << endl;
    }
    return cropped_image;
}

/////////////////////////////////////////////////////////////////////////////////

void ImageCropper::saveCroppedImages(int CroppedName, string directory, string extension, Mat cropped_image)
{
    // Check if cropped_image is valid before saving
    if (!cropped_image.empty()) {
        imwrite(directory + to_string(CroppedName) + extension, cropped_image);
        cout << "Cropped image saved successfully!" << endl;
    }
    else {
        cerr << "Error: No cropped image to save!" << endl;
    }
}