#include <iostream>
#include <new>
using namespace std;

int
main ()
{
  unsigned long start = 0x8000L;

  for  (int i=0; i < 20; i++)
  {
    try {
      int* p;
      unsigned long size = (start << i);
      cout << "Allocating " << dec << size << " int's...";
      p = new int[size];
      cout << "OK! " << dec << i << endl;
      delete[] p;
    }
    catch( bad_alloc &ba) {
      cout << "ALLOC ERROR:" << endl << ba.what( ) << endl;
    }
  }
  return 0;
}
