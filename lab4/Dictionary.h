#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Pair.h"

class Dictionary {
    friend ostream& operator<<(ostream&,const Dictionary&);
  public:
    Dictionary();                                   // Default constructor
    Dictionary(const Dictionary& s);                // Copy constructor: deep copy required
    Dictionary(const Pair* pairs, int num_pairs);  // Other constructor: deep copy required
    ~Dictionary();                                  // Destructor

    // Add a Pair to the dictionary;
    // Do nothing if the Dictionary has no right pair at all..
    // If there is a same pair in dictionary, out "This pair has been in dictionary".
    // Be careful! Deep copy is required here.
    void insert(const Pair& p);

    // Return true if the given Pair is in the dictionary; return false otherwise.
    bool contains(const Pair& p) const;

    // Print the list of Pairs in the dictionary.
    void print() const;

    // TODO: Add the following operator function prototypes for the Dictionary class
    // - The assignment operator, operator=  [ Note: Deep copying is required]
    // - The equality operator, operator==
    // - The union operator, operator+
    // - The indexing operator, operator[]
    // - The << operator, operator<<

    // ADD YOUR CODE HERE

    // TODO: Declare non-member function operator<< as a friend of the Dictionary class.

    // ADD YOUR CODE HERE
    Dictionary& operator=(const Dictionary&);
    bool operator==(const Dictionary&) const;
    Dictionary operator+(const Dictionary&) const;
    const Pair& operator[](int);
    Pair operator[](int) const;
  private:
    int num_pair;
    Pair* pairs;
};

#endif /* DICTIONARY_H_ */
