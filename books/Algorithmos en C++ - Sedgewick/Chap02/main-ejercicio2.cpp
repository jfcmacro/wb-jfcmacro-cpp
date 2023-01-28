#include <iostream>
#include "euclides.h"

int
main() {
  int x, y;

  while (std::cin >> x and
	 std::cin >> y)
    if (x > 0 && y > 0) std::cout <<
			  x <<
			  ' ' <<
			  y <<
			  ' ' <<
			  mcd(x,y,true, [](int a, int b) -> void {
			    std::cout << "a: " << a
				      << "b: " << b
				      << std::endl;
			    return;
			  });
  return EXIT_SUCCESS;
}
			 
			    
      
