#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

int
main(void) {
  istringstream input("1\n"
                      "some non-numeric input\n"
                      "2\n");

  // cout << "numeric limits<streamsize>::max() = "
  //      << numeric_limits<streamsize>::max()
  //      << " numeric limits<streamsize>::min() = "
  //      << numeric_limits<streamsize>::min()
  //      << endl;

  for (;;) {
    int n;
    input >> n;


    if (input.eof() || input.bad())
      break;
    else if(input.fail()) {
      input.clear();
      input.ignore(numeric_limits<streamsize>::max(), '\n');
    } else
      cout << n << endl;
  }

  return 0;
}
