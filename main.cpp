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
      cin.ignore(256, '\n');
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
    cout << timeObject1 << " , " << timeObject2 << " and " << timeObject3
         << endl;

    cout << "Would you like to update the times? (1 for Yes, 0 for No): ";

    int updateTimes;
    updateTimes = getIntInput();

    if (updateTimes == 1) {
      cout << " New Time 1: " << endl;
      cin >> timeObject1;
      cout << "New Time 2: " << endl;
      cin >> timeObject2;
      cout << " New Time 3: " << endl;
      cin >> timeObject3;
    }

    cout << "Enter 1 to continue or 0 to quit: " << endl;
    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}