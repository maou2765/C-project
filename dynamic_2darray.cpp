#include<iostream>
using namespace std;
int** create_matrix(int num_of_row,int num_of_col){
  int** matrix=new int* [num_of_row];
  for(int i=0;i<num_of_row;++i){
    matrix[i]=new int [num_of_col];
  }
  return matrix;
}
void print_matrix(int** matrix,int num_of_row,int num_of_col){
  for(int i=0;i<num_of_row;++i){
    for(int j=0;j<num_of_col;++j){
      cout<<matrix[i][j]<<' ';
    }
    cout<<endl;
  }
}
void delete_matrix(int** matrix,int num_of_row,int num_of_col){
  for(int i=0;i<num_of_row;i++){
    delete matrix[i];
    matrix[i]=nullptr;
  }
  delete matrix;
}
int main(){
  int** hamitonian=create_matrix(10,10);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      hamitonian[i][j]=i+j+i%2;
    }
  }
  print_matrix(hamitonian,10,10);
  delete_matrix(hamitonian,10,10);
  hamitonian=nullptr;
  cout<<hamitonian<<endl;
  return 0;
}
