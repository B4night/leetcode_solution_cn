#include <iostream>
using namespace std;

class A {
	virtual void func() {};
};

class B : public A {
	virtual void func() {};
};

int main() {
	cout << sizeof(A) << endl << sizeof(B) << endl;	
}