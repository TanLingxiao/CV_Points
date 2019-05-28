#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    int morph_elem = 0;
    int morph_size = 0;
    int morph_operator = 0;
    Mat dst;
    Mat img = imread("LinuxLogo.jpg", IMREAD_COLOR); //读取为彩色图像

    int operation = morph_operator + 2;
    Mat element = getStructuringElement(morph_elem, Size(2*morph_size + 1, 2*morph_size+1), Point( morph_size, morph_size ));
    morphologyEx(img, dst, operation, element);
    namedWindow("Result", WINDOW_AUTOSIZE);
    
    imshow("Result", dst);

    waitKey(0);

    return 0;
}



