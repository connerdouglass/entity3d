#include <iostream>
#include <ctime>
#include <chrono>
#include "timing.h"

using namespace std::chrono;

long get_system_time_ms() {

    // Get the current time in milliseconds
    milliseconds ms = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );

    // Return the number of milliseconds
    return ms.count();

}