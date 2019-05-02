#include<iostream>
#include<vector>
using namespace std;
template<typename ForwardIterator>
ForwardIterator max_elem(ForwardIterator first, ForwardIterator last){
    ForwardIterator temp=first;
    for(ForwardIterator p=first;p!=last;p++){
        if(*temp<*p){temp=p;}
    }
    return temp;
}
int main(){
    std::vector<int> x;
    x.push_back(0);
    if(x.begin()==x.end()){
        cout<<"x.begin==x.end"<<endl;
    }else{
        cout<<*(x.end())<<endl;
    };
    cout<<*(max_elem(x.begin(),x.begin()))<<endl;
}
