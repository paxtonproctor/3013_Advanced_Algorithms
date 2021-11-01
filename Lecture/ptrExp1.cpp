// This program stores the address of a variable in a pointer.
#include <iostream>
using namespace std;

int main() 
{
	int x = 25;   // int variable
	//int *ptr;     // Pointer variable, can point to an int
	//ptr = &x;     // Store the address of x in ptr

	int *ptr = &x;
	cout << "========================================================" << endl;
	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << &x << endl;
	cout << "The address of x is (now using the pointer) " << ptr << endl; 
	cout << "The content of the address that ptr is pointing to is " << *ptr << endl;
	cout << "The address of our ptr pointer " << &ptr << endl;
	cout << "========================================================" << endl;
	return 0;
}
