#ifndef TRACKERPROJECT_H
#define TRACKERPROJECT_H

#include <stdint.h>
#include <cstdlib>
#include <cstring>

class TrackerProject
{
public:
    // Constructor
    TrackerProject();
    // Distractor
    ~TrackerProject();

    // Function for capture frame with camera
    int8_t init();

    // Boolean true as active
    bool active{true};
};

#endif /*TRACKERPROJECT_H*/