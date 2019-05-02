#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>
#include <string>
using namespace std;

class Pair {
  public:
    Pair();
    Pair(const Pair& p);        // Copy constructor
    Pair(int id);               // Conversion constructor that can convert a id to a Pair object
    Pair(int id, string info);  // Construct a Pair with id and information
    ~Pair();                    // Destructor

    bool same(const Pair& p) const; // Check whether two pair are the same
    int get_id() const;             // Get the identity of this pair
    void print() const;             // Print the pair

  private:
    int id;      // Identity
    string info; // Information
};

#endif /* PAIR_H_ */
