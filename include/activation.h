#ifndef Activation_H
#define Activation_H

#include <cstdlib>
#include <iostream>
#include <vector>

class ActivationFunction {
public:
  virtual double calculate (double x) = 0;
  virtual double partial (double x) = 0;
  virtual std::vector<double> apply_activation (std::vector<double> arr) {
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = calculate(arr[i]);
    }
    return arr;
  }

};

#endif