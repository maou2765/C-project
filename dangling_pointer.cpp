#include<iostream>
int main(){
  char* p1=new char [128];
  char* p2=p1;
  p1[0]='a';
  delete p1;p1=NULL;
  std::cout << p2[0];
  p2[0]='b';
  std::cout << p2[0];
}
