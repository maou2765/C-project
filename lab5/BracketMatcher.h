/*-- MatchBracket.h --------------------------------------------------------
 This header file defines two functions:-
 matchBrackets() and displayResult().
 --------------------------------------------------------------------------*/

#ifndef MATCHBRACKET_H
#define MATCHBRACKET_H
#include "Stack.h"



class BracketMatcher {
  public:
    BracketMatcher(); // Default constructor

    // Input: matchResult.
    // if matchResult is True,
    //    print "The expression has matching pairs of brackets"
    // else
    //    print out "The expression has unmatched brackets."  and
    //    print the position of the unmatcted '(' and ')
    void displayResult(bool matchResult) const;


    bool matchBrackets(char theExpr[]);
    // Input: The function parameter is an array of expression
    //
    // Return: True, if ALL the open and close brackets are matched in the expression.
    // Otherwise return False.
    //
    // And, While processing the input expression,
    // for each matched pair, print the positions for each pair of matching brackets
    // e.g.  (2,6)(1,13)(15,19) ...

  private:
    Stack mainStack;
    Stack errStack;
    int pos;  // position of the input expression. (leftmost is 0)
};

#endif /* BracketMatcher_H */
