#include <iostream>
#include <unistd.h>

using namespace std;

class A {
public:
	A(int n) {
		cout << "Constructor invocado" << endl;
		vector = new int[n];
		this->n = n;
	}

	A(const A &a) {
		cout << "Constructor invocado" << endl;
		vector = new int[a.n];
		this->n = a.n;
	}

	~A() {
		cout << "Destructor invocado" << endl;
		delete[] vector;
	}

	A&
	operator =(const A& a) {

		delete[] vector;
		vector = new int[a.n];
		this->n = a.n;
		return *this;
	}

	A friend operator +(const A& a, const A& b); 
private:
	int *vector;
	int n;
};


A operator +(const A& a, const A& b) {

	A c(a.n + b.n);

	return c;
}

int
main() {

	A a(10), b(20), c(30);


	a = b + c;

	::sleep(5);
}
