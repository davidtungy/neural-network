#ifndef Loss_H
#define Loss_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class Loss {
public:
  virtual double calculate_loss (vector<double> actual, vector<double> predicted) = 0;
  virtual queue<double> partial (vector<double> actual, vector<double> predicted) = 0;

};


#endif