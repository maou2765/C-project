#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
	Pair D1[2] = {
		  Pair(12, "C"), Pair(1, "C++")
	};

	Pair D2[4] = {
		  Pair(0, "Python"), Pair(3, "Scala")
	};

	cout << "Dictionary1:" << endl;
	Dictionary *dict1 = new Dictionary(D1, 2); // Initialized by the parameterized constructor
	dict1->print();
	cout << endl;

	cout << "Dictionary2:" << endl;
	Dictionary *dict2 = new Dictionary(D2, 2); // Initialized by the parameterized constructor
	dict2->print();
	cout << endl;

	// Test assignment operator function
	cout << "Dictionary3:" << endl;
	Dictionary *dict3 = dict1; // Initialized by the parameterized constructor
	dict3->print();
	cout << endl;

	// Test operator+ to support union operation of two dictionary objects
	cout << "Dictionary4 right:" << endl;
	Dictionary dict4 = (*dict3) + (*dict2); // Initialized by the parameterized constructor
	dict4.print();
	cout << endl;

	cout << "Dictionary4 wrong:" << endl;
	dict4 = (*dict3) + (*dict1); // Initialized by the parameterized constructor
	dict4.print();
	cout << endl;

	// Test equality operator function
	cout << boolalpha;
	cout << "Does Dictionary1 equal to Dictionary2 ? "
			<< ((*dict1) == (*dict2)) << endl;
	cout << "Does Dictionary1 equal to Dictionary3 ? "
			<< ((*dict1) == (*dict3)) << endl;
	cout << endl;

	// Test indexing operator function
	cout << "Pair with ID(1) in Dictionary1:" << endl;
	Pair p_id1 = (*dict1)[1];
	p_id1.print();
	cout << endl;

	cout << "Pair with ID(2) in Dictionary1: the output maybe strange as random memory" << endl;
	Pair p_id2 = (*dict1)[2];
	p_id2.print();
	cout << endl;

	// Test stream operator function
	cout << "Print Dictionary1:" << endl;
	cout << (*dict1) << endl;

  return 0;
}
