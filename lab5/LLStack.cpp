#include"LLStack.h"
ostream& operator<<(ostream& os,const Stack& s){
    list<int>::const_iterator p;
    for(p=s.stack.begin();p!=s.stack.end();++p){
        os<<*p<<endl;
    }

    return os;
}
