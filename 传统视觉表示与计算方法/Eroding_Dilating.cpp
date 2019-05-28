#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    int erosion_size = 0;
    int dilation_size = 0;

    Mat erosion_dst, dilation_dst;
    Mat img = imread("LinuxLogo.jpg", IMREAD_COLOR); //读取为彩色图像

    int erosion_type = MORPH_RECT;
    // int erosion_type = MORPH_CROSS;
    // int erosion_type = MORPH_ELLIPSE;
    Mat element_erosion = getStructuringElement(erosion_type,
                                         Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                                         Point(erosion_size, erosion_size));
    erode(img, erosion_dst, element_erosion);
    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
    imshow("Erosion Demo", erosion_dst);


    int dilation_type = MORPH_RECT;
    // int dilation_type = MORPH_CROSS;
    // int dilation_type = MORPH_ELLIPSE;

    Mat element_dilation = getStructuringElement(dilation_type,
                                         Size(2 * dilation_size + 1, 2 * dilation_size + 1),
                                         Point(dilation_size, dilation_size));
    dilate(img, dilation_dst, element_dilation);
    namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
    imshow("Dilation Demo", dilation_dst);

    waitKey(0);

    return 0;
}
