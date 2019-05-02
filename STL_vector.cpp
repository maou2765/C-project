#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
//A container class is a class that holds a collection of homogeneous object
//if the member function is built outside the class templete,we must add templete <typename T>  each time we define the function
template <typename T>
class Array{
    private:
        int _size;
        T* _addr;
    public:
        Array(){this->_size=0,this->_addr=new T [0];};
        Array(int size){this->_size=size;this->_addr=new T [size];};
};
template <class Iterator, class Predicate>
Iterator my_find_if(Iterator first, Iterator last, Predicate predicate){
    if(first!=last && !predicate(*first)){
        cout<<"looking "<<*first<<endl;
        return my_find_if(++first,last,predicate);
    }else if(first==last && !predicate(*first)){
        cerr<<"Not found"<<endl;
    }else if(first==last && predicate(*first)){
        cout<<"eventually, we find the solution"<<endl;
        return first;
    }else if(first!=last &&predicate(*first)){
        cout<<"found before last element"<<endl;
        return  first;
    }else if(first==last && predicate(*first)){
        cout<<"eventually, we find the solution"<<endl;
        return first;
    }
};
template<typename T>
bool greater_than_300(T a){
    return a>300;
};
int main(){
    std::vector<int> haha;
    for(int i=0;i<5;i++){
        haha.push_back(i*10);
    }
    std::vector<int>::iterator p;//iterator is the inner class of vector
    for(p =haha.begin();p!=haha.end();p++){//++ is overloaded by the iterator
    //sometimes we cannot overload [], then we must use iterator
        cout<<*p<<endl;
    };
    cout<<"2nd element:";
    p=haha.begin();
    cout<<*(p+1)<<endl;//second element
    //haha.resize(10);
    for(p =haha.begin();p!=haha.end();p++){//++ is overloaded by the iterator
    //sometimes we cannot overload [], then we must use iterator
        cout<<*p<<endl;
    };
    haha.push_back(400);
    std::vector<int>::iterator p1=my_find_if(haha.begin(),haha.end(),greater_than_300<int>);
    cout<<*p1<<endl;
}
