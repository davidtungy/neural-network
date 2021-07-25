#ifndef NeuralNetwork_H
#define NeuralNetwork_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "neuron.h"
#include "layer.h"

using namespace std;

class NeuralNetwork {
  private:
  	vector<Layer*> layers;
  	
  public:
  	NeuralNetwork();
    void add_layer(int size_previous_layer, int size, string activation);
    double* forward(double* input);

};

#endif