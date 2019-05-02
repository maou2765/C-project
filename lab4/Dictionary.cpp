/*
 * Dictionary.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: jiaxiangshang
 */

#include "Dictionary.h"

using namespace std;
Dictionary::Dictionary() {
  cout << "Initialized by Dictionary's default constructor" << endl;
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  this->num_pair = 0;
  this->pairs = NULL;
}

Dictionary::Dictionary(const Dictionary& s){
  cout << "Initialized by Dictionary's copy constructor" << endl;
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked

  this->num_pair = s.num_pair;
  this->pairs = new Pair[this->num_pair];
  for(int i = 0; i < num_pair; i++){
    this->pairs[i] = s.pairs[i];
  }
}  //Copy constructor

Dictionary::Dictionary(const Pair* pairs, int num_pairs){
  cout << "Initialized by Pair's parameterized constructor" << endl;
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked

  this->num_pair = num_pairs;
  this->pairs = new Pair[this->num_pair];
  for(int i = 0; i < this->num_pair; i++){
    this->pairs[i] = pairs[i];
  }
}  // Other constructor

Dictionary::~Dictionary(){
  if(pairs != NULL) {
    this->num_pair = 0;
    delete [] this->pairs;
  }
}

// Add a Pair to the dictionary;
// Do nothing if the Dictionary has no right pair at all..
// If there is a same pair in dictionary, out "This pair has been in dictionary".
// Be careful! Deep copy is required here.
void Dictionary::insert(const Pair& p){
  if(contains(p)){
    cout << "This pair has been in dictionary" << endl;
  }
  else{
    Pair* pairs_tmp = new Pair[this->num_pair+1];
    for(int i = 0; i < this->num_pair; i++){
      pairs_tmp[i] = this->pairs[i];
    }
    this->pairs = pairs_tmp;
    this->pairs[num_pair] = p;
    this->num_pair++;
  }
}

// Return true if the given Pair is in the dictionary; return false otherwise.
bool Dictionary::contains(const Pair& p) const{
  bool find = false;
  for(int i = 0; i < num_pair; i++){
    if(p.get_id() == pairs[i].get_id()){
      find = true;
      break;
    }
  }
  if(find == false){
    return false;
    cout << "The dictionary not contains this pair" << endl;
  }
  return true;
}

void Dictionary::print() const{
  if(num_pair == 0){
    cout << "The Dictionary is empty!" << endl;
    return;
  }
  cout << "Number of pairs: " << num_pair << endl;;
  cout << "Pairs: " << endl;
  for (int i = 0; i < num_pair; i++){
    pairs[i].print();
    cout << endl;
  }
}  // print the list of Pairs in the set



// TODO: Overload assignment operator function
// Note: Deep copying is required
// ADD YOUR CODE HERE
Dictionary& Dictionary::operator=(const Dictionary& s){
    if(this!=&s){
        this->num_pair=s.num_pair;
        delete [] this->pairs;
        this->pairs=new Pair [this->num_pair];
        for(int i =0;i<this->num_pair;i++){
            this->pairs[i]=s.pairs[i];
        }
    }
    return *this;

}
bool Dictionary::operator==(const Dictionary& s) const{
    if(this->num_pair==s.num_pair){
        for(int i=0;i<this->num_pair;i++){
            if(this->contains(s.pairs[i])){
                for(int j=0;j<this->num_pair;j++){
                    if(this->pairs[j].same(s.pairs[i])){
                        break;
                    }else if(j==this->num_pair-1){
                        return false;
                    };
                };
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}
Dictionary Dictionary::operator+(const Dictionary& b) const{
    Dictionary temp(*this);
    for(int i=0;i<b.num_pair;i++){
        if(temp.contains(b.pairs[i])){
            cout<<"This pair has been in dictionary"<<endl;
        }else{
            temp.insert(b.pairs[i]);
        }
    }
    return temp;
}
const Pair& Dictionary::operator[](int j){
    for(int i=0;i<this->num_pair;i++){
        if(this->pairs[i].get_id()==j){
            return this->pairs[i];
        }
    }
    cerr<<"The dictionary not contains this pair\n";
};
Pair Dictionary::operator[](int j)const{
    for(int i=0;i<this->num_pair;i++){
        if(this->pairs[i].get_id()==j){
            return this->pairs[i];
        }
    }
    cerr<<"The dictionary not contains this pair\n";
}
ostream& operator<<(ostream& os,const Dictionary& dict){
    os<<"{";
    for(int i=0;i<dict.num_pair;i++){
        dict.pairs[i].print();
    };
    os<<'}';
    return os;
};

// TODO: Overload operator+ to support union operation of two dictionary objects
// ADD YOUR CODE HERE


// TODO: Overload equality operator function
// ADD YOUE CODE HERE


// TODO: Overload indexing operator function
// ADD YOUR CODE HERE


// TODO: Overload operator<< to allow output of objects in Dictionary type
// ADD YOUR CODE HERE
