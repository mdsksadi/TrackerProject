#ifndef TRACKERPROJECT_H
#define TRACKERPROJECT_H

#include <stdint.h>
#include <cstdlib>
#include <cstring>

class TrackerProject
{
public:
    TrackerProject();
    ~TrackerProject();

    int8_t init();

    bool active{true};
};

#endif /*TRACKERPROJECT_H*/