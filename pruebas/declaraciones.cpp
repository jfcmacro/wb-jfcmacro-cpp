#include <iostream>

using namespace std;

int 
main() {

	double* p = new double(2);
	void* q;
	int* r;

	q = p;
	// p = q;
	// r = p;
	// r = q;
	r = (int*) q;
	r = static_cast<int*>(q);
	// r = static_cast<int*>(p);
	r = reinterpret_cast<int*>(p);
}

