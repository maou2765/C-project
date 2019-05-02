#include "Pair.h"

Pair::Pair() {
  id = 1;
  info = "C++";
}

// Copy constructor
Pair::Pair(const Pair& p) {
  id = p.id;
  info = p.info;
}

// Conversion constructor that can convert a id to a Pair object
Pair::Pair(int id) {
  this->id = id;
  this->info = "";
}

// Construct a Pair with id and information
Pair::Pair(int id, string info) {
  this->id = id;
  this->info = info;
}

// Destructor
Pair::~Pair() {
}

// Check whether two pairs are the same
bool Pair::same(const Pair& p) const {
  return (id == p.id && info == p.info);
}

int Pair::get_id() const {
  return id;
}

// Print the pair
void Pair::print() const{
  cout << "( " << id << " : " << info << " )";
}
