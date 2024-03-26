#include "Time.h"
using namespace std;

int main() {
  Time TimeObject1(5, 14, 59);
  Time TimeObject2(12, 25, 6);

  cout << "Initialized two Time objects: " << endl;
  cout << TimeObject1 << "and " << TimeObject2 << endl;
}