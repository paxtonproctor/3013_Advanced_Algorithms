// This program demonstrates the use of the indirection
// operator.
#include <iostream>
using namespace std;

int main()
{
	int x = 25;     
	int *ptr1 = &x; 
	int **ptr2 = &ptr1; 
	int ***ptr3 = &ptr2; 
	
	cout << "The value of x is: " << x << endl;
	cout << "The address of x is  " << &x << endl;
	cout << "====================================" << endl;
	cout << "ptr1 is  " << ptr1 << endl;
	cout << "*ptr1 is  " << *ptr1 << endl;
	cout << "&ptr1 is  " << &ptr1 << endl;
	cout << "====================================" << endl;
	cout << "ptr2 is  " << ptr2 << endl;
	cout << "*ptr2 is  " << *ptr2 << endl;
	cout << "&ptr2 is  " << &ptr2 << endl;
	cout << "====================================" << endl;
	cout << "ptr3 is  " << ptr3 << endl;
	cout << "*ptr3 is  " << *ptr3 << endl;
	cout << "&ptr3 is  " << &ptr3 << endl;
	cout << "***ptr3 = " << ***ptr3 << endl;
	return 0;
}
