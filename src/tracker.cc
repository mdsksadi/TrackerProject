#include <iostream>

#include <stdint.h>
#include <cstdlib>
#include <cstring>

#include <opencv2/opencv.hpp>
#include "../include/tracker.hpp"

TrackerProject::TrackerProject()
{
    std::cout << "Tracker Started\n";
}

TrackerProject::~TrackerProject()
{
    std::cout << "Tracking Finished\n";
}

int8_t TrackerProject::init()
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        std::cerr << "Error opening Camera\n";

        return -1;
    }
    cv::namedWindow("Camera Feed", cv::WINDOW_NORMAL);

    while (true)
    {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            std::cerr << "Empty frame\n";
            break;
        }
        cv::imshow("Camera Feed", frame);

        char key = cv::waitKey(1);
        if (key == 27) // Press Esc to exit
            break;
    }

    cap.release();
    cv::destroyAllWindows();
}