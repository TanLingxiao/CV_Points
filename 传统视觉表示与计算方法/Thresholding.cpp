#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    int threshold_value = 0;
    int threshold_type = 3;
    int const max_binary_value = 255;
    Mat gray, dst;
    Mat img = imread("stuff.jpg", IMREAD_COLOR);
    cvtColor(img, gray, COLOR_BGR2GRAY);
    namedWindow("Demo", WINDOW_AUTOSIZE);
    threshold(gray, dst, threshold_value, max_binary_value, threshold_type);
    imshow("Demo", dst);
    waitKey(0);

    return 0;
}




