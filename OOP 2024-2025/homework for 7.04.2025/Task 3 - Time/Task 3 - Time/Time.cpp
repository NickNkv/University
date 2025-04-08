#include "Time.hpp"
#include <iostream>
#include <cmath>
#define timeForDay 86400

Time::Time() {
	this->seconds = 0;
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds) {
	unsigned temp = seconds + minutes * 60 + hours * 3600;
	if (temp >= timeForDay) {
		this->seconds = temp % timeForDay;
	}
	else {
		this->seconds = temp;
	}
}

unsigned Time::TimeUntilMidnight() {
	return timeForDay - this->seconds;
}

void Time::IncrementOneSecond() {
	this->seconds++;
}

bool Time::IsDinnerTime() {
	if (this->seconds >= 20 * 3600 + 30 * 60 && this->seconds <= 22 * 3600) {
		return true;
	}
	return false;
}

bool Time::IsPartyTime() {
	if (
		(this->seconds >= 23 * 3600 && this->seconds <= timeForDay - 1) ||
		(this->seconds >= 0 && this->seconds <= 6 * 3600)
		) {
		return true;
	}
	return false;
}

Time Time::TimeDifference(Time& time) {
	unsigned int otherTime = timeForDay - time.TimeUntilMidnight();
	unsigned int result = 0;
	if (this->seconds > otherTime) {
		result = this->seconds - otherTime;
	}
	else {
		result = otherTime - this->seconds;
	}
	return Time(0, 0, result);
}

bool Time::operator<(const Time& time) const {
	return this->seconds < time.seconds;
}

bool Time::operator>(const Time& time) const {
	return this->seconds > time.seconds;
}

Time& Time::operator=(const Time& time) {
	if (this != &time) {
		this->seconds = time.seconds;
	}
	return *this;
}

void Time::Print() {
	unsigned hours = this->seconds / 3600;
	unsigned minutes = (this->seconds - 3600 * hours) / 60;
	unsigned sec = (this->seconds - 3600 * hours - 60 * minutes);

	if (hours < 10) {
		std::cout << "0" << hours;
	}
	else {
		std::cout << hours;
	}
	std::cout << ":";

	if (minutes < 10) {
		std::cout << "0" << minutes;
	}
	else {
		std::cout << minutes;
	}
	std::cout << ":";

	if (sec < 10) {
		std::cout << "0" << sec << std::endl;
	}
	else {
		std::cout << sec << std::endl;
	}
}
