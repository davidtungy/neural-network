#ifndef Activation_H
#define Activation_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// TO DO: add support for and test other activation functions (and their partials)
// May refactor into a activation function class later to make it a little cleaner

class ActivationFunction {
public:
  virtual double calculate (double x) = 0;
  virtual double partial (double x) = 0;
  virtual vector<double> apply_activation (vector<double> arr) {
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = calculate(arr[i]);
    }
    return arr;
  }

};

/*
static double linear (double x) {
  return x;
}

static double sigmoid (double x) {
  return 1 / (1 + exp(-x));
}

static double sigmoid_partial (double x) {
  return sigmoid(x) * (1 - sigmoid(x));
}

static double relu (double x) {
  return max(0.0, x);
}

static double relu_partial (double x) {
  // define gradient at 0 to be 1
  return (x < 0) ? 0 : 1;
}

static double leaky_relu (double x, double alpha = 0.01) {
  return max(alpha * x, x);
}

static double leaky_relu_partial (double x, double alpha = 0.01) {
  // define gradient at 0 to be 1
  return (x < 0) ? alpha : 1;
}


// Mutator
static vector<double> apply_activation (vector<double> arr, string activation) {
  double (*activation_function) (double);
  if (activation == "linear") {
    activation_function = linear;
  } else if (activation == "sigmoid") {
    activation_function = sigmoid;
  }
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = activation_function(arr[i]);
  }
  return arr;
}
*/

#endif