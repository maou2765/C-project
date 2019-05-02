#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Permutation {
  public:
    Permutation() { }
    void permute(const vector<int>& nums);
    void print() const;
  private:
    vector<vector<int> > p;
};

class Intersection {
  public:
    Intersection() { }
    void intersect(const vector<int>& nums1, const vector<int>& nums2);
    void print() const;
  private:
    vector<int> inter;
};
