#include <iostream>
#include <cstdlib>
#include "MyClassQt.h"

int
main(int argc, char *argv[]) {
  MyClassQt *a, *b, *c;

  a = new MyClassQt("foo");
  b = new MyClassQt("ba-a-ar");
  c = new MyClassQt("baz");


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
