#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;



int main()
{
    Mat img = imread("fruits.jpg", IMREAD_COLOR); //读取为彩色图像
    cout << "高度："<< img.size().height << " 宽度："<< img.size().width << endl;
    // cvtColor(img, img, COLOR_BGR2RGB);
    // Mat grey;
    // cvtColor(img, grey, COLOR_BGR2GRAY);  // 转为灰度图
    // imwrite("/home/tanlx/CLionProjects/work/grey.jpg", grey); // 保存为新图片

    vector<Mat> chanels;
    Mat R;
    Mat G;
    Mat B;
    split(img, chanels); // 按通道分割图像
    R = chanels.at(0);
    G = chanels.at(1);
    B = chanels.at(2);
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", img);  //窗口展示
    waitKey();
    return 0;
}


