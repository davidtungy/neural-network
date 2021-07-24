#ifndef Layer_H
#define Layer_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "neuron.h"

using namespace std;

class Layer {
  private:
  	double bias;
  	Neuron* neurons;
    string activation;
    int size;
  public:
  	Layer(int size, int size_previous_layer, string activation);
    double* forward(double input[]);
    ~Layer();
};

#endif