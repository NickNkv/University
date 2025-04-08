#pragma once

class Time;

class Time {
public:
	//life cycle
	Time();
	Time(unsigned hours, unsigned minutes, unsigned seconds);

	//methods
	unsigned TimeUntilMidnight();
	void IncrementOneSecond();
	bool IsDinnerTime();
	bool IsPartyTime();
	Time TimeDifference(Time& time);
	bool operator<(const Time& time) const;
	bool operator>(const Time& time) const;
	Time& operator=(const Time & time);
	void Print();

private:
	unsigned int seconds;
};