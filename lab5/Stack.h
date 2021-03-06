/*-- Stack.h ---------------------------------------------------------------
 This header file defines a Stack data type.
 Basic operations:
 constructor:  Constructs an empty stack
 empty:        Checks if a stack is empty
 push:         Modifies a stack by adding a value at the top
 top:          Retrieves the top stack value; leaves stack unchanged
 pop:          Modifies stack by removing the value at the top
 display:      Displays all the stack elements

 Class Invariant:
 1. The stack elements (if any) are stored in positions
    0, 1, . . ., myTop of myArray.
 2. -1 <= myTop < STACK_CAPACITY

 mytop stores the top position of the stack;
 -1 means empty stack; 0 means 1 element in the stack
 --------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

const int STACK_CAPACITY = 1024;
typedef int StackElement;

class Stack
{
public:
	/***** Member Functions *****/
	/***** Constructor *****/
	Stack();
	/*------------------------------------------------------------------------
	 Construct a Stack object.

	 Precondition:  None.
	 Postcondition: An empty Stack object has been constructed (myTop is
	     initialized to -1 and myArray is an array with STACK_CAPACITY
	     elements of type StackElement).
	 -----------------------------------------------------------------------*/

	bool empty() const;
	/*------------------------------------------------------------------------
	 Check if stack is empty.
	 Precondition: None
	 Postcondition: Returns true if stack is empty and false otherwise.
	 -----------------------------------------------------------------------*/

	void push(const StackElement& value);
	/*------------------------------------------------------------------------
	 Add a value to a stack.

	 Precondition:  value is to be added to this stack
	 Postcondition: value is added at top of stack provided there is space;
	     otherwise, a stack-full message is displayed and execution is
	     terminated.
	 -----------------------------------------------------------------------*/

	StackElement top() const;
	/*------------------------------------------------------------------------
	 Retrieve value at top of stack (if any).

	 Precondition:  Stack is nonempty
	 Postcondition: Value at top of stack is returned, unless the stack is
	     empty; in that case, an error message is displayed and a "garbage
	     value" is returned.
	 -----------------------------------------------------------------------*/

	void pop();
	/*------------------------------------------------------------------------
	 Remove value at top of stack (if any).

	 Precondition:  Stack is nonempty.
	 Postcondition: Value at top of stack has been removed, unless the stack
	     is empty; in that case, an error message is displayed and
	     execution allowed to proceed.
	 -----------------------------------------------------------------------*/

        // friend function declaration
        friend ostream& operator<<(ostream& os, const Stack& s);

private:
	/***** Data Members *****/
	StackElement myArray[STACK_CAPACITY];
	int myTop;
}; // end of class declaration

#endif /* STACK_H */
