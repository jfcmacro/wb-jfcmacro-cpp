#include <iostream>
#include <stdio.h>

int
main()
{
  char *x = new char(1000);

  x[0] = '\0';

  while (fgets(x, 999, stdin)) 

    cout << x << endl;
}
