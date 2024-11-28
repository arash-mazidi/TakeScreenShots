#pragma once
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
class ImageCropper
{
public:
	Mat loadImages(string,string,Mat,string);
	Mat cropImages(Mat,Mat);
	void saveCroppedImages(int, string,string,Mat);
};

