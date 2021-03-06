#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Pair.h"
//const int MAX_NUM_PAIRS = 50;

class Dictionary {
  public:
    Dictionary();                                   // Default constructor
    Dictionary(const Dictionary& s);                // Copy constructor: deep copy required
    Dictionary(const Pair pairs[], int num_pairs);  // Other constructor: deep copy required
    ~Dictionary();                                  // Destructor

	
    // If there is a same pair in dictionary, out "This pair has been in dictionary".
    // Be careful! Deep copy is required here.
    void add_pair(const Pair& p);
	
    // Look up the right pair from the dictionary by id; output (cout) the message
    // "The dictionary is empty" or "Invalid pair id" or "The dictionary not contains this pair"
    // for different situations and do nothing else if the dictionary has no right pair at all.
	
	void removeFirstPair(); 
	//Remove the first pair (the one with the smallest index) from the set; output (cout) the message "No pair" and do nothing else if the set has no points at all
	
    void lookup(int id, Pair & p);
	
    // Return true if the given Pair is in the dictionary; return false otherwise.
    bool contains(const Pair& p) const;
	
    // Print the list of Pairs in the dictionary.
    void print() const;

  private:
    int num_pairs;
    Pair *pairs;
};

#endif /* DICTIONARY_H_ */
