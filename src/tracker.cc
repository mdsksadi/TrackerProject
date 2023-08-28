#include <iostream>

#include <stdint.h>
#include <cstdlib>
#include <cstring>

#include <opencv2/opencv.hpp>
#include "../include/tracker.hpp"

// Message from the Constructor
TrackerProject::TrackerProject()
{
    std::cout << "Tracker Started\n";
}

// Message from the Distractor
TrackerProject::~TrackerProject()
{
    std::cout << "Tracking Finished\n";
}

// Actual Implementation for capturing the frame
int8_t TrackerProject::init()
{
    /*
     * Create a VideoCapture Object for camera index 0
     * 0 refers to the default camera (camera index 0)
     */
    cv::VideoCapture cap(0);

    // Show error if the camera does not open.
    if (!cap.isOpened())
    {
        std::cerr << "Error opening Camera\n";

        return -1;
    }

    /*
     * Create a named window in which the captured video frames will be displayed
     * cv::WINDOW_NORMAL creates a resizable window that can be adjusted in size.
     */
    cv::namedWindow("Camera Feed", cv::WINDOW_NORMAL);

    /*
    * It is a common structure used for processing video frames in various computer vision applications.
    * Mat is the class in OpenCV used to represent images (or frames in this case). This line creates an empty Mat Object named frame, which will hold each captured video frame.
    * cap is a VideoCpture object that represents the video stream (VideoCapture cap (0);)
        This line reads the next frame from the video stream and stores it in the frame variable. The >> operator is overloaded for the VideoCapture class to read frames
    * If (frame.empty()): This condition checks if the captured frame is empty.
        which can happen if the end of the video stream is reached or if there is an issue with capturing the frame.
    */
    while (active)
    {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            std::cerr << "Empty frame\n";
            break;
        }

        // Display an image (or frame) in a named window created using OpenCV's namedWindow function.
        cv::imshow("Camera Feed", frame);

        //  Wait for a key press from the user while the application is displaying a window with images or video frames.
        char key = cv::waitKey(1);
        if (key == 27) // Press Esc to exit
            break;
    }

    // Release the resources associated with the VideoCapture object, which I used to open and access the camera.
    cap.release();
    cv::destroyAllWindows();
}