#include "Time.h"
#include <limits>

using namespace std;

/*
Helper function that checks the user input for restarting the program or leaving
it
*/
int getIntInput() {
  int inputNumber;
  bool continueLoop = true;
  while (continueLoop) {
    cin >> inputNumber;

    if (cin.fail()) {
      cout << "Invalid input. Please, enter an integer\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continueLoop = false;
    }
  }

  return inputNumber;
}

int main() {

  int repeatExecution = 0;

  /*
  Program can be repeated until an exit condition is reached
  */
  do {

    cout << "Creating the first time object:" << endl;
    Time time1(5, 14, 59);
    cin >> time1;
    cout << "Time 1 is: " << time1 << endl;
    cout << "\n";

    cout << "Creating the second time object:" << endl;
    Time time2(12, 25, 6);
    cin >> time2;
    cout << "Time 2: " << time2 << endl;
    cout << "\n";

    cout << "Creating the third time object:" << endl;
    Time time3(16, 45, 0);
    cin >> time3;
    cout << "Time 3: " << time3 << endl;
    cout << "\n";

    cout << "++time1:" << endl;
    ++time1;
    cout << time1 << endl;
    cout << "\n";

    cout << "++time2:" << endl;
    ++time2;
    cout << time2 << endl;
    cout << "\n";

    cout << "time1++:" << endl;
    time1++;
    cout << time1 << endl;
    cout << "\n";

    cout << "time2++:" << endl;
    time2++;
    cout << time2 << endl;
    cout << "\n";

    cout << "--time1:" << endl;
    --time1;
    cout << time1 << endl;
    cout << "\n";

    cout << "--time2:" << endl;
    --time2;
    cout << time2 << endl;
    cout << "\n";

    cout << "time1--:" << endl;
    time1--;
    cout << time1 << endl;
    cout << "\n";

    cout << "time2--:" << endl;
    time2--;
    cout << time2 << endl;
    cout << "\n";

    cout << "Time1 < Time2: " << (time1 < time2) << endl;
    cout << "Time1 > Time2: " << (time1 > time2) << endl;
    cout << "\n";

    cout << "Time1 <= Time2: " << (time1 <= time2) << endl;
    cout << "Time1 >= Time2: " << (time1 >= time2) << endl;
    cout << "\n";

    cout << "Time1 == Time2: " << (time1 == time2) << endl;
    cout << "Time1 != Time2: " << (time1 != time2) << endl;
    cout << "\n";

    cout << "Time1 = Time2 = Time3:" << endl;
    time1 = time2 = time3;
    cout << time1 << " , " << time2 << " and " << time3 << endl;
    cout << "\n";

    cout << "Enter 1 to start again or 0 to quit: " << endl;

    // Validating user input for breaking the loop
    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}