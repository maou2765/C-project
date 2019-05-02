int main(){
  int a=10;
  int* p =&a;
  *p=20;//a=20

  int* const q=&a;
  *q=10;//ok,a=10
  int b =30;
  q=&b;//not ok

  const int* r=&a;
  *r=30;//not ok
  r=&b;//ok
  const int* const s=&a;
  *s=20;//not ok
  s=&b;//not ok
  int const* t=&a;//it means a pointer to a const object
  *t=30;//not ok
  t=&b;//ok
  int* const c;//not ok const pointer need to be initialized
  *(static_cast<char*<hahaha0>)='a';
  //const object to non-const reference is not ok
  //non-const object to const reference is ok
  //non-const object to non-const reference is ok
  //const object to const reference is ok
}
