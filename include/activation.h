#ifndef Activation_H
#define Activation_H

#include <cstdlib>
#include <iostream>
#include <cmath>

// TO DO: add support for and test other activation functions (and their partials)

static double linear (double x) {
  return x;
}

static double sigmoid (double x) {
  return 1 / (1 + exp(-x));
}

static double sigmoid_partial (double x) {
  return sigmoid(x) * (1 - sigmoid(x));
}

// Mutator
static vector<double> apply_activation (vector<double> arr, string activation) {
  cout << "Applying activation: " << activation << "..." << endl;
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

#endif