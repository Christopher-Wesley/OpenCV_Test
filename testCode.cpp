#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main(void) 
{
    Mat img = imread("/Users/chriswesley/Desktop/Sample_Code/test.jpg", 0);
    if(img.empty())
    {
        std::cout << "Could not read the image:" << std::endl;
        return 1;
    }
    imshow("Display Window", img);
    int k = waitKey(0);

    if (k == 's')
    {
        imwrite("/Users/chriswesley/Desktop/Sample_Code/testgray.jpg", img);
    }
    destroyAllWindows();
    return 0;
}
