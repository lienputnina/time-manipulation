#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {

  /*
  Declaring friendly functions for input/output operators. This approach allows
  the Time class to be directly input from and output to streams like 'cin''and
  'cout', which themselves are instances of 'istream' and 'ostream' classes.
  */
  friend istream &operator>>(istream &, Time &);
  friend ostream &operator<<(ostream &, const Time &);

private:
  int hour;
  int minute;
  int second;

public:
  Time(int hour, int minute, int second);

  Time &operator++();
  Time operator++(int);

  Time &operator--();
  Time operator--(int);

  bool operator>(const Time &) const;
  bool operator<(const Time &) const;

  bool operator>=(const Time &) const;
  bool operator<=(const Time &) const;

  bool operator==(const Time &) const;
  bool operator!=(const Time &) const;

  Time &operator=(const Time &);
};

#endif