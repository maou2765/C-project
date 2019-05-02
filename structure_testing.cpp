#include<iostream>
using namespace std;
enum Dept{CSE,ECE,MATH};
struct Date{
  unsigned int year;
  unsigned int month;
  unsigned int day;
};
struct Student_Record{
  char name[5];
  unsigned int id;
  char gender;
  Dept dept;
  Date entry;
  void *init(const char name[],unsigned int id,char gender,Dept dept,Date entry,Student_Record& record){
    for(int i=0;i<5;i++){
      record.name[i]=name[i];
    };
    record.id=id;
    record.gender=gender;
    record.dept=dept;
    record.entry=entry;
  };
};
void init(const char name[],unsigned int id,char gender, Dept dept,Date entry,Student_Record& record);

int main(){
  Date ent={1000,13,32};
  Student_Record Jesus;
  Jesus.init("Jesus",689,'N',CSE,ent,Jesus);
    for(int i=0;i<5;i++){
    cout<<Jesus.name[i];
  }
  cout<<endl<<Jesus.id<<'\t'<<Jesus.gender<<'\t'<<Jesus.dept<<'\t'<<Jesus.entry.year<<'/'<<Jesus.entry.month<<'/'<<Jesus.entry.day<<endl;
  return 0;
}
