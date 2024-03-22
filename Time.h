#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time {

  friend istream &operator>>(istream &, Time &);
  friend ostream &operator<<(ostream &, const Time &);

private:
  int second;
  int minute;
  int hour;

public:
  Time(int second, int minute, int hour);

  // See, if we need it
  Time(const Time &object);
  ~Time();

  // Time & - return type - reference to an object
  Time &operator=(const Time &);

  Time &operator++();
  Time operator++(int);

  Time &operator--();
  Time operator--(int);

  bool operator>(const Time &);
  bool operator<(const Time &);

  bool operator>=(const Time &);
  bool operator<=(const Time &);

  bool operator==(const Time &otherArray) const;
  bool operator!=(const Time &otherArray) const;
};

#endif