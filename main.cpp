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

    cout << "\nEnter 1 to continue or 0 to quit:\n\n";

    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}