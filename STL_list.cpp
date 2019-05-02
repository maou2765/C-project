#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for(list<int>::iterator p=a.begin();p!=a.end();p++){
        cout<<*p;
    }
    cout<<endl;
    list<int> temp;
    for(int i=0;i<2;i++){
        temp.push_front(*(--a.end()));
        a.pop_back();
        a.push_front(*(temp.begin()));
        temp.pop_front();
    }
    for(list<int>::iterator p=a.begin();p!=a.end();p++){
        cout<<*p;
    }
}
