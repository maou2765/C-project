#include"BracketMatcher.h"

using namespace std;
BracketMatcher::BracketMatcher():mainStack(),errStack(),pos(0){
}
bool BracketMatcher::matchBrackets(char theExpr[]){
    int i=0;
    for(char* c=theExpr;*c!='\0';c++){
        if(*c=='('){
            mainStack.push(i);
        }else if(*c==')'){
            if(!mainStack.empty()){
                cout<<'('<<mainStack.top()<<','<<i<<')';
                mainStack.pop();
            }else{
                errStack.push(i);
            }
        }
        i++;
    }
    cout<<endl;
    return mainStack.empty();
}
void BracketMatcher::displayResult(bool matchResult)const{
    if(matchResult){
        cout<<"The expression has matching pairs of brackets"<<endl;
    }else{
        cout<<"The expression has unmatched brackets."<<endl;
        if(!mainStack.empty()){
            cout<<"unmatched '(' at:"<<endl;
            cout<<mainStack;
        };
        if(!errStack.empty()){
            cout<<"unmatched ')' at:"<<endl;
            cout<<errStack;
        }

    }
}
