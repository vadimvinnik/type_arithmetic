#include "type_arithmetics.h"
#include <iostream>
using namespace std;

int main() {
  // 9 + 9 == 18
  cout << add<_9, _9>::value << endl;

  // 5 * 7 == 35
  cout << mul<_5, _7>::value << endl;

  // let's try a more complex expression
  // 2 * 7 + 3 * (4 + 5) == 41
  cout <<
    add<
      mul<_2, _7>,
      mul<
        _3,
        add<_4, _5>
      >
    > ::value << endl;

  // and now factorial: 5! == 120
  cout << factorial<_5>::value << endl;
  
  return 0;
}
