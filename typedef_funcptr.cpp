typedef  void (*haha)(int*,double*);
void func(int* a, double* b){
    *a+=*b;
}
int main(){
    haha funcptr=func;
    int a=1;
    double b=1;
    funcptr(&a,&b);
}
