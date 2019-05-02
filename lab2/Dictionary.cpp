#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary() {
  // This function is already completed.

  // This cout statement is for learning purpose only, which shows when the constructor will be invoked.
  cout << "Initialized by Dictionary's default constructor" << endl;
  this->num_pairs = 0;
}

// Copy constructor: deep copy required.
Dictionary::Dictionary(const Dictionary& s) {
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked.
  cout << "Initialized by Dictionary's copy constructor" << endl;

  // TODO: add your code here
  this->num_pairs=s.num_pairs;
  for(int i=0;i<MAX_NUM_PAIRS;i++){
    this->pairs[i]=s.pairs[i];
  }
}

// Other constructor: deep copy required.
Dictionary::Dictionary(const Pair pairs[], int num_pairs) {
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by Pair's parameterized constructor" << endl;

  // TODO: add your code here
  this->num_pairs=num_pairs;
  for(int i=0;i<num_pairs;i++){
    this->pairs[i]=pairs[i];
  }
}

// Destructor
Dictionary::~Dictionary() {
}

// Add a Pair to the dictionary; output (cout) the message "Insufficient array space" and
// do nothing else if there are already MAX_NUM_PAIRS number of pairs.
void Dictionary::add_pair(const Pair& p) {
  // TODO: add your code here
  if(this->num_pairs<MAX_NUM_PAIRS){
    if (this->contains(p)){
      cout<<"This pair has been in dictionary"<<endl;
    }else{
      this->pairs[this->num_pairs]=p;
      this->num_pairs+=1;
    }
  }else{
    cout<<"Insufficient array space"<<endl;
  }
}

// Look up the right Pair from the dictionary; output (cout) the message "No right pairs" and
// do nothing else if the dictionary has no right pair at all.
void Dictionary::lookup(int id, Pair & p) {
  // TODO: add your code here
  bool right=false;
  if(this->num_pairs==0){
    cout<<"The dictionary is empty"<<endl;
  }else{
    for(int i=0;i<this->num_pairs;i++){
      if(id==this->pairs[i].get_id() &&this->pairs[i].same(p)){
        this->pairs[i].print();
        right=true;
        break;
      }else if(id==this->pairs[i].get_id() && !(this->pairs[i].same(p))){
        cout<<"Invalid pair id"<<endl;
        right=true;
        break;
      }
    }
    if(right==false){
      cout<<"No right pairs"<<endl;
    }
  }
}

// Return true if the given Pair is in the dictionary; return false otherwise.
bool Dictionary::contains(const Pair& p) const {
  // TODO: add your code here
  for (int i=0;i<this->num_pairs;i++){
    if (this->pairs[i].same(p))
      return true;
  };
  return false;
}

// Print the list of Pairs in the dictionary.
void Dictionary::print() const {
  // TODO: add your code here
  if(this->num_pairs == 0) {
    cout << "The Dictionary is empty!" << endl;
    return;
  }
  cout << "Number of pairs: " << this->num_pairs << endl;;
  cout << "Pairs: " << endl;
  for (int i = 0; i < this->num_pairs; i++) {
    pairs[i].print();
    cout << endl;
  }
}
