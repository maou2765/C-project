#include <iostream>
#include "whiteSpace.h"
#include "black.h"

using namespace std;

int main()
{
	const WhiteSpace* whiteSpace1 = new WhiteSpace;
	const WhiteSpace whiteSpace2;
	const Black* black = new Black;

	whiteSpace1->sayTheName();
	whiteSpace2.sayTheName();
	black->sayTheName();

	cout << "Chinese landscape painting is artistic combinations of black ink and white spaces!!" << endl;

	delete whiteSpace1;
	delete black;

	return 0;
}
