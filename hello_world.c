#include<stdio.h>
enum Dept{CSE,ECE,MATH};
struct Date{
  unsigned int year;
  unsigned int month;
  unsigned int day;
  void print_date(unsigned int year, unsigned int month,unsigned int day){
    printf("%i/%i/%i\n",year,month,day);
  }
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
  void print_dept(Dept dept){
    switch (dept){
      case 0:
        printf("CSE\n");
        break;
      case 1:
        printf("ECE\n");
        break;
      case 2:
        printf("MATH\n");
        break;
    }
  }
};
//void init(const char name[],unsigned int id,char gender, Dept dept,Date entry,Student_Record& record);

int main(){
  struct Date ent={1000,13,32};
  struct Student_Record Jesus;
  Jesus.init("Jesus",689,'N',CSE,ent,Jesus);
  for(int i=0;i<5;i++){
      printf("%c",Jesus.name[i]);
  }
  printf("\n");
  Jesus.print_dept(Jesus.dept);
  Jesus.entry.print_date(Jesus.entry.year,Jesus.entry.month,Jesus.entry.day);
  printf("%i %c\n",Jesus.id,Jesus.gender);
  return 0;
}
