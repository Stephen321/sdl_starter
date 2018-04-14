#ifndef TIMER_H
#define TIMER_H

#include <chrono>
using namespace std::chrono;

class Timer {
public:
    Timer();
    double getDelta();

private:
    time_point<high_resolution_clock> m_lastTime;
};

#endif /* TIMER_H */
