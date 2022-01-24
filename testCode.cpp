#include <iostream>
#include "depthai/depthai.hpp"
#include "opencv2/opencv.hpp"

int main(){
    using namespace std;

    // Create pipeline
    dai::Pipeline pipeline;
    auto colorCam = pipeline.create<dai::node::ColorCamera>();
    auto xlinkOut = pipeline.create<dai::node::XLinkOut>();
    xlinkOut->setStreamName("preview");
    colorCam->setInterleaved(true);
    colorCam->preview.link(xlinkOut->input);


    try {
        // Try connecting to device and start the pipeline
        dai::Device device(pipeline);

        // Get output queue
        auto preview = device.getOutputQueue("preview");

        cv::Mat frame;
        while (true) {

            // Receive 'preview' frame from device
            auto imgFrame = preview->get<dai::ImgFrame>();

            // Show the received 'preview' frame
            cv::imshow("preview", cv::Mat(imgFrame->getHeight(), imgFrame->getWidth(), CV_8UC3, imgFrame->getData().data()));

            // Wait and check if 'q' pressed
            if (cv::waitKey(1) == 'q') return 0;

        }
    } catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
    }


    return 0;
}
/*
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
*/