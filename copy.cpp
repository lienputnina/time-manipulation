#include "Time.h"
using namespace std;

int copyFunction() {
  Time timeObject1(5, 14, 59);
  Time timeObject2(12, 25, 6);

  cout << "Initialized two Time objects: " << endl;
  cout << "timeObject1 is " << timeObject1 << " and  "
       << "timeObject2 is " << timeObject2 << endl;

  cout << "### Output/Input test ###" << endl;
  cin >> timeObject1;
  cout << "Time 1 is now: " << timeObject1 << endl;

  cin >> timeObject2;
  cout << "Time 2 is now: " << timeObject2 << endl;

  cout << "### Assignment test ###" << endl;
  timeObject1 = timeObject2;
  cout << "timeObject1 is " << timeObject1 << endl;
  cout << "timeObject2 is " << timeObject2 << endl;

  cout << "### Prefix increment test ###" << endl;
  ++timeObject1;
  ++timeObject2;
  cout << "timeObject1 prefix increment: " << timeObject1 << endl;
  cout << "timeObject2 prefix increment: " << timeObject2 << endl;

  cout << "### Postfix increment test ###" << endl;
  timeObject1++;
  timeObject2++;
  cout << "timeObject1 postfix increment: " << timeObject1 << endl;
  cout << "timeObject2 postfix increment: " << timeObject2 << endl;

  cout << "### Prefix decrement test ###" << endl;
  --timeObject1;
  --timeObject2;
  cout << "timeObject1 prefix decrement: " << timeObject1 << endl;
  cout << "timeObject2 prefix decrement: " << timeObject2 << endl;

  cout << "### Postfix decrement test ###" << endl;
  timeObject1--;
  timeObject2--;
  cout << "timeObject1 postfix decrement: " << timeObject1 << endl;
  cout << "timeObject2 postfix decrement: " << timeObject2 << endl;

  cout << "### Comparison test 1: operators < and > ###" << endl;
  if (timeObject1 > timeObject2) {
    cout << timeObject1 << " is bigger than " << timeObject2 << endl;
  } else if (timeObject1 < timeObject2) {
    cout << timeObject1 << " is smaller than " << timeObject2 << endl;
  } else {
    cout << timeObject1 << " is equal to " << timeObject2 << endl;
  }

  cout << "### Comparison test 2: operators >= and <= ###" << endl;
  if (timeObject1 >= timeObject2) {
    cout << timeObject1 << " is bigger than or equal to " << timeObject2
         << endl;
  } else if (timeObject1 <= timeObject2) {
    cout << timeObject1 << " is smaller than or equal to " << timeObject2
         << endl;
  } else {
  }

  cout << "### Comparison test 3: operators == and != ###" << endl;
  if (timeObject1 == timeObject2) {
    cout << timeObject1 << " is completely equal to " << timeObject2 << endl;
  } else if (timeObject1 != timeObject2) {
    cout << timeObject1 << " is not equal to " << timeObject2 << endl;
  } else {
  }
  return 0;
}