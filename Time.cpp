#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int timeSecond, int timeMinute, int timeHour) {
  int second = timeSecond >= 0 && timeSecond < 60 ? timeSecond : 0;
  int minute = timeMinute >= 0 && timeMinute < 60 ? timeMinute : 0;
  int hour = timeHour >= 0 && timeHour < 24 ? timeHour : 0;
}

Time::Time(const Time &object) {
  second = object.second;
  minute = object.minute;
  hour = object.hour;
};
