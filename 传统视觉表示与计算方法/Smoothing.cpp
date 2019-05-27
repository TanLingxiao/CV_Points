#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;



int main()
{
    // 平滑主要通过滤波器实现
    int DELAY_CAPTION = 1500;
    int DELAY_BLUR = 100;
    int MAX_KERNEL_LENGTH = 31;
    Mat dst;

    Mat img = imread("fruits.jpg", IMREAD_COLOR); //读取为彩色图像

    // Homogeneous Blur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur(img, dst, Size( i, i ), Point(-1,-1));
    }

    // Gaussian Blur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur(img, dst, Size( i, i ), 0, 0 );
    }

    // Median Blur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        medianBlur (img, dst, i );
    }

    // Bilateral Blur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        bilateralFilter (img, dst, i, i*2, i/2 );
    }
    
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", dst);  //窗口展示
    waitKey();
    return 0;
}


