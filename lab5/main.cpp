#include "BracketMatcher.h"
#include <iostream>

using namespace std;

// TODO: implement BracketMatcher.cpp and Stack.cpp

int main()
{
  char expr_1[] = "(((a+b)*c+d-e)/(f+g)-(h+j)*(k-l))/(m-n)";
  char expr_2[] = "(a+b))*((c+d)";
  char expr_3[] = ")x+y+3+4))*((z+1)";
  bool result;   // the matching result

  cout << "** Scan the express from Left to Right **" << endl ;

  //===========expr_1======================================================

  BracketMatcher  myBracketMatcher1;

  cout << endl << endl << "------------------------" << endl;
  cout << "The express 1 is: " << expr_1 << endl << endl;
  result = myBracketMatcher1.matchBrackets( expr_1 );
  myBracketMatcher1.displayResult( result );

  //===========expr_2======================================================

  BracketMatcher  myBracketMatcher2;

  cout << endl << endl << "------------------------" << endl;
  cout << "The express 2 is: " << expr_2 << endl << endl;
  result = myBracketMatcher2.matchBrackets( expr_2 );
  myBracketMatcher2.displayResult( result );

  //===========expr_3======================================================

  BracketMatcher  myBracketMatcher3;

  cout << endl << endl << "------------------------" << endl;
  cout << "The express 3 is: " << expr_3 << endl << endl;
  result = myBracketMatcher3.matchBrackets( expr_3 );
  myBracketMatcher3.displayResult( result );

  return 0;
}
