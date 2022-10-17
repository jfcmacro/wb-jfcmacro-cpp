#include <iostream>
#include <cstdlib>
#include "MyClass.h"

int
main(int argc, char *argv[]) {
  MyClass *a, *b, *c;

  a = new MyClass("foo");
  b = new MyClass("ba-a-ar");
  c = new MyClass("baz");


  std::cout << a->text() << " (" << a->getLengthOfText()
	    << ")" << std::endl;
  std::cout << b->text() << " (" << b->getLengthOfText()
	    << ")" << std::endl;
  std::cout << c->text() << " (" << c->getLengthOfText()
	    << ")" << std::endl;

  int result = a->getLengthOfText() - c->getLengthOfText();

  std::cout << "Result: " << result << std::endl;

  delete a;
  delete b;
  delete c;

  return EXIT_SUCCESS;
}
