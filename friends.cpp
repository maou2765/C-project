#include<iostream>
#include <string>
using namespace std;
class Student{
    private:
        class privateStudent{
            friend class Student;
            private:
                string fakename;
            public:
                privateStudent(){this->fakename="fuck";}
                privateStudent(string name){
                    this->fakename=name;
                }
                string getName()const{return this->fakename;}

        };
        string truename;
        privateStudent* unachara;
    public:
        class publicStudent{
            friend class Student;
            private:
                string nakename;
            public:
                publicStudent(){this->nakename="diunei";};
                publicStudent(string name):nakename(name){};
        };
        Student():truename("true"){this->unachara=new privateStudent;};
        Student(string name,string fname):truename(name){this->unachara=new privateStudent(fname);};
        string getunaname() const{return this->unachara->fakename;}
        string getturename()const{return this->truename;}
        privateStudent* getunachara()const{return this->unachara;}
        /*privateStudent* newprivateStudent(string name){
            privateStudent* pp= new privateStudent(name);
            return pp;
        };It does not work*/

};
int main(){
    Student hihi("diunei","loumou");
    Student::publicStudent haha;
    //Student::privateStudent* hehe=hihi->unachara;
    //cout<<hehe->getName()<<endl;
    cout<<hihi.getunachara()->getName()<<endl;
}
