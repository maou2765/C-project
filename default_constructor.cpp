#include <iostream>
using namespace std;
class A{
    private:
        int a;
    public:
        A():a(0){cout<<"no parameter"<<endl;}
        A(int i):a(i){}
        int get_a()const{return a;}
};

int main(){
    A obj1;
    A obj2(1);
    cout<<obj1.get_a()<<endl;
    cout<<obj2.get_a()<<endl;
    string a="abc";
    a.erase();
    cout<<a.length()<<endl;
}
