#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {

  friend istream &operator>>(istream &, Time &);
  friend ostream &operator<<(ostream &, const Time &);

private:
  int hour;
  int minute;
  int second;

public:
  Time(int hour, int minute, int second);
  Time(const Time &object);
  ~Time();

  Time &operator++();
  Time operator++(int);

  Time &operator--();
  Time operator--(int);

  // Time & - return type - reference to an object
  Time &operator=(const Time &);
  bool operator>(const Time &) const;
  bool operator<(const Time &) const;

  bool operator>=(const Time &) const;
  bool operator<=(const Time &) const;

  bool operator==(const Time &) const;
  bool operator!=(const Time &) const;
};

#endif