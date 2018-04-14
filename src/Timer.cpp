#include "Timer.h"


Timer::Timer()
	: m_lastTime(high_resolution_clock::now()) {

}

double Timer::getDelta() {
	auto currentTime = high_resolution_clock::now();
	duration<double> delta(currentTime - m_lastTime);
	m_lastTime = currentTime;
	return delta.count();
}