#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;



int main()
{
    double alpha = 2.1;
    int beta = 40;

    Mat img = imread("fruits.jpg", IMREAD_COLOR); //读取为彩色图像
    Mat new_img = Mat::zeros( img.size(), img.type());

    for( int y = 0; y < img.rows; y++ ) {
        for( int x = 0; x < img.cols; x++ ) {
            for( int c = 0; c < img.channels(); c++ ) {
                new_img.at<Vec3b>(y,x)[c] =
                        saturate_cast<uchar>( alpha*img.at<Vec3b>(y,x)[c] + beta); // 通过改变通道值改变亮度
            }
        }
    }

    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", new_img);  //窗口展示
    waitKey();
    return 0;
}
