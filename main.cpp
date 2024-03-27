#include "Time.h"
using namespace std;

int getIntInput() {
  int inputNumber;
  bool continueLoop = true;
  while (continueLoop) {
    cin >> inputNumber;

    if (cin.fail()) {
      cout << "Invalid input. Please, enter an integer\n";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      continueLoop = false;
    }
  }

  return inputNumber;
}

int main() {
  Time timeObject1(5, 14, 59);
  Time timeObject2(12, 25, 6);
  Time timeObject3(16, 45, 0);

  int repeatExecution = 0;

  do {
    cin >> timeObject1;
    cout << "Time 1 is now: " << timeObject1 << endl;

    cin >> timeObject2;
    cout << "Time 2 is now: " << timeObject2 << endl;

    cin >> timeObject3;
    cout << "Time 3 is now: " << timeObject3 << endl;

    timeObject1 = timeObject2 = timeObject3;

    cout << "\nAfter synchronizing, the times are: " << endl;
    cout << "Time 1 is " << timeObject1 << endl;
    cout << "Time 2 is " << timeObject2 << endl;
    cout << "Time 3 is " << timeObject3 << endl;

    // if (timeObject1 == timeObject2 && timeObject2 == timeObject3) {
    //   cin >> timeObject1;
    //   cout << "Time 1 is now: " << timeObject1 << endl;
    //   cin >> timeObject2;
    //   cout << "Time 2 is now: " << timeObject2 << endl;
    //   cin >> timeObject3;
    //   cout << "Time 3 is now: " << timeObject3 << endl;
    // };

    /*
    ++timeObject1;
    ++timeObject2;
    ++timeObject3;
    cout << "timeObject1 is " << timeObject1 << endl;
    cout << "timeObject2 is " << timeObject2 << endl;
    cout << "timeObject3 is " << timeObject3 << endl;

    timeObject1++;
    timeObject2++;
    timeObject3++;
    cout << "timeObject1 is " << timeObject1 << endl;
    cout << "timeObject2 is " << timeObject2 << endl;
    cout << "timeObject3 is " << timeObject3 << endl;

    --timeObject1;
    --timeObject2;
    --timeObject3;
    cout << "timeObject1 is " << timeObject1 << endl;
    cout << "timeObject2 is " << timeObject2 << endl;
    cout << "timeObject3 is " << timeObject3 << endl;

    timeObject1--;
    timeObject2--;
    timeObject3--;
    cout << "timeObject1 is " << timeObject1 << endl;
    cout << "timeObject2 is " << timeObject2 << endl;
    cout << "timeObject3 is " << timeObject3 << endl;

    if (timeObject1 > timeObject2) {
      cout << timeObject1 << " is bigger than " << timeObject2 << endl;
    } else if (timeObject1 < timeObject2) {
      cout << timeObject1 << " is smaller than " << timeObject2 << endl;
    } else {
      cout << timeObject1 << " is equal to " << timeObject2 << endl;
    }

    if (timeObject1 >= timeObject2) {
      cout << timeObject1 << " is bigger than or equal to " << timeObject2
           << endl;
    } else if (timeObject1 <= timeObject2) {
      cout << timeObject1 << " is smaller than or equal to " << timeObject2
           << endl;
    } else {
    }

    if (timeObject1 == timeObject2) {
      cout << timeObject1 << " is completely equal to " << timeObject2 <<
      endl;
    } else if (timeObject1 != timeObject2) {
      cout << timeObject1 << " is not equal to " << timeObject2 << endl;
    } else {
    }
*/
    cout << "\nEnter 1 to continue or 0 to quit:\n\n";

    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}