#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {


    Mat img = imread("fruits.jpg", IMREAD_ANYCOLOR);

    for(;;)
    {
        imshow("Demo", img);
        char c = (char)waitKey(0);
        if(c == 27)
        { break; }
        else if(c == 'i')
        { pyrUp(img, img, Size(img.cols*2, img.rows*2 ));}
        else if(c == 'o')
        { pyrDown(img, img, Size(img.cols/2, img.rows/2));}
    }
    
    return 0;
}




