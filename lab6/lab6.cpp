#include <iostream>
#include "stl.h"
using namespace std;

int main() {
  vector<int> q1;  // First container
  q1.push_back(3); // 3, 1, 2, 2
  q1.push_back(1);
  q1.push_back(2);
  q1.push_back(2);

  vector<int> q2;  // Second container
  q2.push_back(1); // 1, 2, 1, 6, 2
  q2.push_back(2);
  q2.push_back(1);
  q2.push_back(6);
  q2.push_back(2);

  vector<int> q3;  // Third container
  q3.push_back(2); // 2, 2
  q3.push_back(2);

  cout << "Q1: Calculate the permutation of a set of integers [3, 1, 2, 2]" << endl;
  Permutation sol1;
  sol1.permute(q1);
  sol1.print();
  cout << endl;

  cout << "Q2A: Calculate the intersection of two sets of integers [3, 1, 2, 2] & [1, 2, 1, 6, 2]" << endl;
  Intersection sol2;
  sol2.intersect(q1, q2);
  sol2.print();

  cout << "Q2B: Calculate the intersection of two sets of integers [3, 1, 2, 2] & [2, 2]" << endl;
  sol2.intersect(q1, q3);
  sol2.print();

  return 0;
}
