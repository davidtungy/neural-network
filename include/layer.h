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
  	
  public:
  	Layer(int size_previous_layer, int size, string activation);
    vector<double> forward(vector<double> input);
    double bias;
    vector<Neuron> neurons;
    string activation;
};

#endif