#include <iostream>
#include "Time.hpp"

void printTimes(Time* times) {
	for (int i = 0; i < 10; i++) {
		times[i].Print();
	}
}

void sortTimes(Time* times) {
	for (int i = 1; i < 10; i++) {
		Time temp = times[i];
		int j = i - 1;
		while (j >= 0 && temp < times[j]) {
			times[j + 1] = times[j];
			j--;
		}
		times[j + 1] = temp;
	}
}

int main() {
	Time t1(22, 20, 50);
	Time t2(0, 0, 30);
	if (t1 > t2) {
		std::cout << "T1 is > than T2" << std::endl;
	}
	std::cout << t1.IsDinnerTime() << std::endl;
	std::cout << t1.IsPartyTime() << std::endl;
	Time diff = t1.TimeDifference(t2);
	t1.Print();
	t1 = t2;
	t1.Print();
	std::cout << std::endl;

	Time times[10] {
		Time (10, 5, 55),
		Time (11, 30, 0),
		Time (3, 25, 36),
		Time (10, 5, 55),
		Time (11, 30, 0),
		Time (7, 25, 36),
		Time (6, 42, 15),
		Time (3, 30, 0),
		Time (22, 25, 59),
		Time (6, 43, 11)
	};

	//printTimes(times);
	sortTimes(times);
	//std::cout << std::endl;
	printTimes(times);

	return 0;
}