#include "Time.h"
#include <iomanip>
#include <limits>

using namespace std;

Time::Time(int timeHour, int timeMinute, int timeSecond) {
  hour = (timeHour >= 0 && timeHour < 24) ? timeHour : 0;
  minute = (timeMinute >= 0 && timeMinute < 60) ? timeMinute : 0;
  second = (timeSecond >= 0 && timeSecond < 60) ? timeSecond : 0;
}

istream &operator>>(istream &input, Time &timeObject) {

  bool inputIsValid = false; // Flag to track if the input is valid

  while (!inputIsValid) {
    cout << "Please, enter hours, minutes and seconds separated by spaces"
         << endl;

    string line;
    // Read the whole line
    getline(input, line);
    // Use stringstream for parsing
    stringstream timeInputStream(line);

    // Attempting to parse the input
    timeInputStream >> timeObject.hour >> timeObject.minute >>
        timeObject.second;

    if (timeInputStream.fail()) {
      cout << "Invalid input. Please, enter three integers separated by "
              "spaces.\n";

      // Clear the fail state for the next input attempt
      input.clear();
      // Ignore the rest of the line to start fresh on the next input
      input.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      // Validating the parsed time values
      timeObject.hour =
          (timeObject.hour >= 0 && timeObject.hour < 24) ? timeObject.hour : 0;
      timeObject.minute = (timeObject.minute >= 0 && timeObject.minute < 60)
                              ? timeObject.minute
                              : 0;
      timeObject.second = (timeObject.second >= 0 && timeObject.second < 60)
                              ? timeObject.second
                              : 0;
      inputIsValid = true; // Setting the flag to true as the input is now valid
    }
  }

  return input;
};

ostream &operator<<(ostream &output, const Time &timeObject) {
  // setw - sets width of output to 2
  // set fill - fills empty space with 0 for 09:05:01 etc.
  output << setw(2) << setfill('0') << timeObject.hour << ":" << setw(2)
         << setfill('0') << timeObject.minute << ":" << setw(2) << setfill('0')
         << timeObject.second;
  return output;
}

// Prefix increment - incrementing seconds
Time &Time::operator++() {
  ++second;
  if (second == 60) {
    ++minute;
    second = 0;
    if (minute == 60) {
      minute = 0;
    }
  }
  return *this;
};

// Postfix increment - incrementing minutes
Time Time::operator++(int) {
  Time initialState = *this;
  minute++;

  if (minute == 60) {
    hour++;
    minute = 0;
    if (hour == 24) {
      hour = 0;
    }
  }

  return initialState;
};

// Prefix decrement
Time &Time::operator--() {
  if (second == 0) {
    if (minute > 0) {
      --minute;
      second = 59;
    }
  } else {
    --second;
  }
  return *this;
};

// Postfix decrement
Time Time::operator--(int) {

  Time initialState = *this;

  if (minute == 0) {
    if (hour > 0) {
      hour--;
      minute = 59;
    }
  } else {
    minute--;
  }

  return initialState;
};

bool Time::operator>(const Time &rightHandObject) const {
  return (hour > rightHandObject.hour) ||
         (hour == rightHandObject.hour && minute > rightHandObject.minute) ||
         (hour == rightHandObject.hour && minute == rightHandObject.minute &&
          second > rightHandObject.second);
};

bool Time::operator<(const Time &rightHandObject) const {
  return (hour < rightHandObject.hour) ||
         (hour == rightHandObject.hour && minute < rightHandObject.minute) ||
         (hour == rightHandObject.hour && minute == rightHandObject.minute &&
          second < rightHandObject.second);
};

bool Time::operator>=(const Time &rightHandObject) const {
  return !(*this < rightHandObject);
};

bool Time::operator<=(const Time &rightHandObject) const {
  return !(*this > rightHandObject);
};

bool Time::operator==(const Time &rightHandObject) const {
  return hour == rightHandObject.hour && minute == rightHandObject.minute &&
         second == rightHandObject.second;
};
bool Time::operator!=(const Time &rightHandObject) const {
  return !(*this == rightHandObject);
};

Time &Time::operator=(const Time &rightHandObject) {
  if (this != &rightHandObject) {
    this->hour = rightHandObject.hour;
    this->minute = rightHandObject.minute;
    this->second = rightHandObject.second;
  }

  return *this;
};