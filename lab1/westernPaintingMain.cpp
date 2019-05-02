#include <iostream>
#include "colors.h"
#include "black.h"

using namespace std;

int main()
{
	const Colors* red = new Colors;
	const Colors* yellow = new Colors;
	const Colors blue;
	
	const Black* black = new Black;

	red->sayTheName(); //why use "->" here?
	yellow->sayTheName(); //why use "->" here?
	blue.sayTheName(); //and why use "." here?
	black->sayTheName();

	cout << "Here is the western style color oil paintings!!" << endl;

	delete red;
	delete yellow;
	delete black;

	//we needed to delete red, yellow, black but not blue, why?

	return 0;
}
