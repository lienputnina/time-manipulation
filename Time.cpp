#include "Time.h"
#include <iomanip>
#include <iostream>
using namespace std;

// rename "timeObject"

Time::Time(int timeSecond, int timeMinute, int timeHour) {
  int second = (timeSecond >= 0 && timeSecond < 60) ? timeSecond : 0;
  int minute = (timeMinute >= 0 && timeMinute < 60) ? timeMinute : 0;
  int hour = (timeHour >= 0 && timeHour < 24) ? timeHour : 0;
}

Time::Time(const Time &timeObject) {
  second = timeObject.second;
  minute = timeObject.minute;
  hour = timeObject.hour;
};

Time::~Time() { cout << "Time is up!" << endl; }

istream &operator>>(istream &input, Time &timeObject) {

  cout << "Please, enter hours, minutes, seconds separated by spaces " << endl;
  input >> timeObject.hour >> timeObject.minute >> timeObject.second;

  // change formatting for this, if timeObject = timeObject
  timeObject.hour =
      (timeObject.hour >= 0 && timeObject.hour < 24) ? timeObject.hour : 0;
  timeObject.minute = (timeObject.minute >= 0 && timeObject.minute < 60)
                          ? timeObject.minute
                          : 0;
  timeObject.second = (timeObject.second >= 0 && timeObject.second < 60)
                          ? timeObject.second
                          : 0;

  return input;
};

ostream &operator<<(ostream &output, const Time &timeObject) {
  // setw - sets width of output to 2
  // set fill - fills empty space with 0 for 09:05:01 etc.
  output << "The current time is: " << setw(2) << setfill('0')
         << timeObject.hour << ":" << setw(2) << setfill('0')
         << timeObject.minute << ":" << setw(2) << setfill('0')
         << timeObject.second;
  return output;
}

// Assignment method
Time &Time::operator=(const Time &rightHandObject) {
  if (this != &rightHandObject) {
    this->hour = rightHandObject.hour;
    this->minute = rightHandObject.minute;
    this->second = rightHandObject.second;
  }

  return *this;
};

// Prefix increment
Time &Time::operator++() {
  /*
  if it's the last second value, increment minute as well
  else - increment only second
  */
  if (second > 59) {
    ++second && ++minute; // is this legal?
  }

  ++second;

  return *this; // really?
};

// Postfix increment
Time Time::operator++(int newMinuteValue) {
  /*
  if it's the last minute value, increment minute and hour
  else - increment only minute
  */
  if (minute > 59) {
    minute++ &&hour++; // is this legal?
  }

  minute++;

  return *this; // really?
};

// Prefix increment
Time &Time::operator--() {
  /*
  if it's the first second value, decrement minute as well
  else - decrement only second
  */

  // change this
  if (second >= 0) {
    --second && --minute; // is this legal?
  }

  --second;

  return *this; // really?
};

// Postfix increment
Time Time::operator--(int) {
  /*
  if it's the last minute value, decrement hour as well
  else - decrement only minute
  */
  if (minute > 59) {
    minute-- &&hour--;
  }

  minute--;

  return *this;
};
