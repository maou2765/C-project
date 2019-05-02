class A{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
};
class B: public A{
    /*
    * we get all of A
    * while access right is not changed
    *    private:
            int a;
        protected:
            int b;
        public:
            int c;
    */
};
class C: protected A{
    /*we get all of A
    while public member will be changed to protected
private:
    int a;
protected:
    int b;
    int c;
    */
};
class D:private A{
    /*we get all of A
    while all data member is changed provate
private:
    int a;
    int b;
    int c;
    */
    public:
        void func(){
            /*
            a=1;//error since a is treated as private member of A, such that class D  is not able to access it
            b=2;
            c=3;
            */
        }
};
class E:public D{
    /*a,b,c is still private
    */
};
int main(){
    A* b=new B;//ok
    //A* c=new C;//error
}
