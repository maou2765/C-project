#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
  cout << "Dictionary1:" << endl;
  Dictionary dict1;
  // Initialized by the default constructor
  dict1.print();
  cout << endl;

  Pair p0;
  dict1.lookup(0, p0);
  p0.print();
  cout << endl;

  Pair ps[4] = {
    Pair(0, "C"), Pair(1, "C++"), Pair(2, "Python"), Pair(3, "Scala")
  };

  cout << "Dictionary2:" << endl;
  Dictionary *dict2 = new Dictionary(ps, 4); // Initialized by the parameterized constructor
  dict2->print();
  cout << endl;

  cout << "Dictionary3:" << endl;
  Dictionary dict3(*dict2); // Initialized by the copy constructor

  cout << "Dictionary3: added a pair(4 Java)" << endl;
  dict3.add_pair(Pair(4, "Java"));
  dict3.print();
  cout << endl;

cout << "Delete dict2" << endl;
	delete dict2;
	cout<< endl;

  cout << "Dictionary3: adding duplicated pair(4 Java)" << endl;
  dict3.add_pair(Pair(4, "Java"));
  dict3.print();
  cout << endl;

  dict3.removeFirstPair();
  cout << "Dictionary3: removed first pair:" << endl;
  dict3.print();
  cout << endl;


  /* Setting the bool alpha format flag so that bool values will be
   * displayed in their textual representation: either true or false,
   * instead of integral values.
   */

  cout << boolalpha;
  cout << "Does dict3 have the Pair (5, JS)? "
       << dict3.contains(Pair(5, "JS")) << endl;
  cout << "Does dict3 have the Pair (3, Scala)? "
       << dict3.contains(Pair(3, "Scala")) << endl;
  cout << "Does dict3 have the Pair (0, C)? "
       << dict3.contains(Pair(0, "C")) << endl;
  cout << endl;

  cout << "main: before last line return 0:" << endl;
  cout << "Automatically invoke destructors to delete dict1, dict3" << endl;
  return 0;
}
