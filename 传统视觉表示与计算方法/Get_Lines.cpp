#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    Mat gray;
    Mat bw;
    Mat img = imread("board.jpg", IMREAD_ANYCOLOR);

    cvtColor(img, gray, COLOR_BGR2GRAY);
    adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

    Mat horizontal = bw.clone();
    Mat vertical = bw.clone();
    int horizontal_size = horizontal.cols / 30;
    Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontal_size, 1));
    erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
    dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

    int vertical_size = vertical.rows / 30;
    Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, vertical_size));
    erode(vertical, vertical, verticalStructure, Point(-1, -1));
    dilate(vertical, vertical, verticalStructure, Point(-1, -1));

    bitwise_not(vertical, vertical);

    Mat edges;
    adaptiveThreshold(vertical, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);

    Mat kernel = Mat::ones(2, 2, CV_8UC1);
    dilate(edges, edges, kernel);

    Mat smooth;
    vertical.copyTo(smooth);

    blur(smooth, smooth, Size(2, 2));

    smooth.copyTo(vertical, edges);

    imshow("Demo", vertical);

    waitKey(0);

    return 0;
}




