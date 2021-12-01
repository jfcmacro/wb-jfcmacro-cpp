#include <iostream>
#include <stack>
#include <cstdlib>

int
main(void) {

  std::stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);

  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
  std::cout << s.top() << std::endl;

  return EXIT_SUCCESS;
}
