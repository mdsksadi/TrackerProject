#include "../include/tracker.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace cv;
using namespace std;

static void TrackerProjectThread()
{
    TrackerProject Tk;
    Tk.init();

    while (!Tk.active)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));

        // Tk.checkOverSpeed();
    }
}

int main()
{
    std::cout << "Starting Tracker Project\n";

    std::thread trackerProjectThread(TrackerProjectThread);
    trackerProjectThread.join();

    std::cout << "End Tracker Project\n";

    return 0;
}