#include<iostream>
#include<string.h>
using namespace std;
class Movie
{
  public:
    Movie (char* n, double s){
      strcpy(name,n);
      sales=s;
    }; // Constructor
    char* get_name(void) {
      return name;
    };    // Look up name
    double get_sales(void){
      return sales;
    };  // Look up sales

  private:
    char name[30];
    double sales;
};

int main(){
  Movie m1 ("Lord of the Rings", 400);
  Movie m2 ("Star Wars", 200);

  if (m1.get_sales() <= m2.get_sales()){
    cout << m2.get_name()
    << " is the better movie because it made $"
    << m2.get_sales() << " million.\n";
  }
  else{
    cout << m1.get_name()
    << " is the better movie because it made $"
    << m1.get_sales() << " million.\n";
  }
}
