#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

Mat typeConvert(Mat image){
    image.convertTo(image, CV_32FC3);
    image = image/255.0;

    return image;
}

int main ()
{
    Mat musk = imread("images/musk.jpg");
    musk = typeConvert(musk);

    Mat glassPNG = imread("images/sunglass.png",-1);
    resize(glassPNG, glassPNG, Size(300, 100));
    glassPNG.convertTo(glassPNG, CV_32F);
    glassPNG = glassPNG / 255.0;

    cout << "Image Dimension" << glassPNG.size() << endl;
    cout << "Number of channels = " << glassPNG.channels();

    int glassHeight = glassPNG.size().height;
    int glassWidth = glassPNG.size().width;

    Mat glassRGBAChannels[4];
    Mat glassRGBChannels[3];
    split(glassPNG, glassRGBAChannels);

    for (int i = 0; i < 3; i++){
        glassRGBChannels[i] = glassRGBAChannels[i];
    }

    Mat glassBGR, glassMask1;
    merge(glassRGBChannels, 3, glassBGR);
    glassMask1 = glassRGBAChannels[3];

    imshow("Face", musk);
    imshow("Glasses Color", glassBGR);
    imshow("Glasses Mask", glassMask1*255);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
