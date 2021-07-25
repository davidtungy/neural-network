#ifndef Activation_H
#define Activation_H

#include <cstdlib>
#include <iostream>
#include <cmath>

static double linear (double x) {
  return x;
}

static double sigmoid (double x) {
  return 1 / (1 + exp(-x));
}

// Mutator
static void apply_activation (double* arr, int size, string activation) {
  double (*activation_function) (double);
  if (activation == "linear") {
    activation_function = linear;
  } else if (activation == "sigmoid") {
    activation_function = sigmoid;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = activation_function(arr[i]);
  }
}

#endif