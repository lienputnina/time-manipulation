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

  // Used to track the validity of the user input
  bool isInputValid = false;

  // while isInput valid = true => while input is valid
  while (!isInputValid) {
    cout << "Please, enter hours, minutes and seconds separated by spaces"
         << endl;

    string line;

    // Reading the whole line of input
    getline(input, line);

    // Needed to parse a line
    stringstream timeInputStream(line);

    // Attempting to parse the input
    timeInputStream >> timeObject.hour >> timeObject.minute >>
        timeObject.second;

    // If the attempt was not successful
    if (timeInputStream.fail()) {
      cout << "Invalid input. Please, enter three integers separated by "
              "spaces.\n";

      // Clear the fail state for the next input attempt
      input.clear();
      // Ignore the rest of the line to start fresh on the next input
      input.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // If attempt was successful and input is valid
    else {
      // Validating the parsed time values
      timeObject.hour =
          (timeObject.hour >= 0 && timeObject.hour < 24) ? timeObject.hour : 0;
      timeObject.minute = (timeObject.minute >= 0 && timeObject.minute < 60)
                              ? timeObject.minute
                              : 0;
      timeObject.second = (timeObject.second >= 0 && timeObject.second < 60)
                              ? timeObject.second
                              : 0;

      isInputValid = true;
    }
  }

  return input;
};

ostream &operator<<(ostream &output, const Time &timeObject) {
  /*
    Formatting time in hh:mm:ss
  */
  output << setw(2) << setfill('0') << timeObject.hour << ":" << setw(2)
         << setfill('0') << timeObject.minute << ":" << setw(2) << setfill('0')
         << timeObject.second;
  return output;
}

Time &Time::operator++() {
  // Incrementing seconds
  second++;
  if (second == 60) {
    // Incrementing minutes, when the last value of seconds is reached
    minute++;
    // Resetting seconds, when their last value is reached
    second = 0;
    if (minute == 60) {
      // Incrementing hours, when the last value of minutes is reached
      hour++;
      // Resetting minutes, when their last value is reached
      minute = 0;
      if (hour == 24) {
        // Resetting hours, if their last value is reached
        hour = 0;
      }
    }
  }
  return *this; // returning the value of the changed object
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
   If the first allowed value of seconds is reached, then decrement minutes
  */
  if (second == 0) {
    if (minute > 0) {
      minute--;
      // Decrementing seconds to their penultimate value
      second = 59;
    }
    if (minute == 0) {
      hour--;
    }
  }
  // Otherwise - decrement seconds
  else {
    --second;
  }
  return *this;
};

Time Time::operator--(int) {
  /*
    Saving the objects initial state to return it later
    */
  Time initialState = *this;

  /*
   If the first allowed value of minutes is reached, then decrement hours
  */
  if (minute == 0) {
    if (hour > 0) {
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
  Returns true, if the first time object is not smaller than the
  second time object
  */
  return !(*this < rightHandObject);
};

bool Time::operator<=(const Time &rightHandObject) const {
  /*
 Returns true, if the first time object is not bigger than the
 second time object
 */
  return !(*this > rightHandObject);
};

bool Time::operator==(const Time &rightHandObject) const {
  // Returns true if hours, minutes and seconds are all equal
  return hour == rightHandObject.hour && minute == rightHandObject.minute &&
         second == rightHandObject.second;
};

bool Time::operator!=(const Time &rightHandObject) const {
  /*
  Returns true, if the first time object is not equal to the
  second time object
*/
  return !(*this == rightHandObject);
};

/*
  Assigns hours, minutes and seconds of the first time object to the second time
  object values
*/
Time &Time::operator=(const Time &rightHandObject) {
  if (this != &rightHandObject) {
    this->hour = rightHandObject.hour;
    this->minute = rightHandObject.minute;
    this->second = rightHandObject.second;
  }

  return *this;
};