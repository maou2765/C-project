#ifndef LLSTACK_H
#define LLSTACK_H
#include<iostream>
#include<list>
using namespace std;
//template<typename T>
class Stack{
    private:
        list<int> stack;
        int topIndex;
    public:
        Stack():topIndex(0),stack(){}
        void push(int elem){stack.push_back(elem);}
        void pop(){stack.pop_back();}
        int top() const{return *stack.rbegin();}
        bool empty()const{return stack.empty();}
        friend ostream& operator<<(ostream&, const Stack&);
};



#endif
