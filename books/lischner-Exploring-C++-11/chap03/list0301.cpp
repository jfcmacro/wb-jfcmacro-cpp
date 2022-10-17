/// list0301.cpp

#include <iostream>

int
main(void) {
  int sum{0};
  int count{};
  int x;

  while (std::cin >> x) {

    sum = sum + x;
    count = count + 1;
  }

  if (count != 0)
    std::cout << "average = " << sum / count << std::endl;

  return EXIT_SUCCESS;
}
