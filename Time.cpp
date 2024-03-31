#include "Time.h"
#include <iomanip>
#include <limits>

using namespace std;

Time::Time(int timeHour, int timeMinute, int timeSecond) {
  /*
  Initializing Time member variables and doing validation for hours,
  minutes and seconds to ensure they are within acceptable ranges:
  - hours: valid range is 0 to 23. Defaults to 0 if outside this range.
  - minutes: valid range is 0 to 59. Defaults to 0 if outside this range.
  - seconds: valid range is 0 to 59. Defaults to 0 if outside this range.
  */
  hour = (timeHour >= 0 && timeHour < 24) ? timeHour : 0;
  minute = (timeMinute >= 0 && timeMinute < 60) ? timeMinute : 0;
  second = (timeSecond >= 0 && timeSecond < 60) ? timeSecond : 0;
}

istream &operator>>(istream &input, Time &timeObject) {

  // Tracking the validity of the user input
  bool inputIsValid = false;

  while (!inputIsValid) {
    cout << "Please, enter hours, minutes and seconds separated by spaces"
         << endl;

    string line;

    // Reading the whole line of input
    getline(input, line);

    // Facilitating parsing of the line
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
      inputIsValid =
          true; // Setting the variable to true as the input is now valid
    }
  }

  return input;
};

ostream &operator<<(ostream &output, const Time &timeObject) {
  /*
    Formatting time in hh:mm:ss format with leading zeros for single-digit
    values
  */
  output << setw(2) << setfill('0') << timeObject.hour << ":" << setw(2)
         << setfill('0') << timeObject.minute << ":" << setw(2) << setfill('0')
         << timeObject.second;
  return output;
}

Time &Time::operator++() {
  // Incrementing minutes
  ++second;
  if (second == 60) {
    // Incrementing minutes, when the last value of seconds is reached
    ++minute;
    // Resetting seconds, when their last value is reached
    second = 0;
    if (minute == 60) {
      // Resetting minutes, when their last value is reached
      minute = 0;
    }
  }
  return *this;
};

Time Time::operator++(int) {
  /*
  Saving the objects initial state to return it later
  */
  Time initialState = *this;

  // Incrementing minutes
  minute++;

  if (minute == 60) {
    // Incrementing hours, when the last value of minutes is reached
    hour++;
    // Resetting minutes when their last value is reached
    minute = 0;
    if (hour == 24) {
      // Resetting hours after completing a day
      hour = 0;
    }
  }

  // Returning the objects original state before increment
  return initialState;
};

Time &Time::operator--() {
  /*
   Decrementing minutes if the first value of seconds is reached
  */
  if (second == 0) {
    if (minute > 0) {
      --minute;

      // Decrementing seconds to their penultimate value
      second = 59;
    }
  } else {
    // Decrementing seconds
    --second;
  }
  return *this;
};

Time Time::operator--(int) {
  /*
    Saving the objects initial state to return it later
    */
  Time initialState = *this;

  if (minute == 0) {
    if (hour > 0) {
      /*
         Decrementing hours if the first value of minutes is reached
        */
      hour--;
      // Decrementing minutes to their penultimate value
      minute = 59;
    }
  } else {
    // Decrementing minutes
    minute--;
  }

  return initialState;
};

bool Time::operator>(const Time &rightHandObject) const {
  /*
Returns true, if:
- The hours are bigger than rightHand object's hours
- Hours are the same, but minutes are bigger
- Minutes and hours are the same, but seconds are bigger
*/
  return (hour > rightHandObject.hour) ||
         (hour == rightHandObject.hour && minute > rightHandObject.minute) ||
         (hour == rightHandObject.hour && minute == rightHandObject.minute &&
          second > rightHandObject.second);
};

bool Time::operator<(const Time &rightHandObject) const {
  /*
Returns true, if:
- The hours are smaller than right-hand-side object's hours
- hours are the same, but minutes are smaller
- minutes and hours are the same, but seconds are smaller
*/
  return (hour < rightHandObject.hour) ||
         (hour == rightHandObject.hour && minute < rightHandObject.minute) ||
         (hour == rightHandObject.hour && minute == rightHandObject.minute &&
          second < rightHandObject.second);
};

bool Time::operator>=(const Time &rightHandObject) const {
  /*
  Returns true, if the left-hand-side object is not smaller than the
  right-hand-side object
  */
  return !(*this < rightHandObject);
};

bool Time::operator<=(const Time &rightHandObject) const {
  /*
 Returns true, if the left-hand-side object is not bigger than the
 right-hand-side object
 */
  return !(*this > rightHandObject);
};

bool Time::operator==(const Time &rightHandObject) const {
  return hour == rightHandObject.hour && minute == rightHandObject.minute &&
         second == rightHandObject.second;
};

bool Time::operator!=(const Time &rightHandObject) const {
  /*
Returns true, if the left-hand-side object is not equal to the
right-hand-side object
*/
  return !(*this == rightHandObject);
};

/*
Assigns all values of the left-hand-side object to the right-hand-side object
*/
Time &Time::operator=(const Time &rightHandObject) {
  if (this != &rightHandObject) {
    this->hour = rightHandObject.hour;
    this->minute = rightHandObject.minute;
    this->second = rightHandObject.second;
  }

  return *this;
};