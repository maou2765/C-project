#include"Stack.h"
Stack::Stack():myTop(-1){
    for(int i=0;i<STACK_CAPACITY;i++){
        myArray[i]=0;
    }
}
bool Stack::empty() const{
    return (myTop==-1);
}
void Stack::push(const StackElement& value){
    if(myTop==1023){cerr<<"Stack Full!";}
    else if(myTop<1023){
        myArray[++myTop]=value;
    }
}
StackElement Stack::top() const {
    if(not empty()){
        return myArray[myTop];
    }else{
        cerr<<"Stack Empty";
    }
}
void Stack::pop(){
    if(not empty()){
        --myTop;
    }else{
        cerr<<"Stack Empty";
    }
}
ostream& operator<<(ostream& os, const Stack& s){
    for(int i=s.myTop;i>=0;i--){
        os<<s.myArray[i]<<endl;
    }
    return os;
}
