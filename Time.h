#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time {

  friend ostream &operator<<(ostream &, const Time &);
  friend istream &operator>>(istream &, const Time &);

private:
  int second;
  int minute;
  int hour;

public:
  Time(int second, int minute, int hour);

  // kopijas konstruktors
  // See, if we need it
  Time(const Time &object);
  ~Time();

  const Time &operator=(const Time &);

  Time &operator++();   // Prefix increment
  Time operator++(int); // Postfix increment

  Time &operator--();   // Prefix increment
  Time operator--(int); // Postfix decrement

  bool operator>(const Time &);
  bool operator<(const Time &);

  bool operator>=(const Time &);
  bool operator<=(const Time &);

  bool operator==(const Time &otherArray) const;
  bool operator!=(const Time &otherArray) const;
};

#endif