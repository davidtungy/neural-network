#ifndef Layer_H
#define Layer_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "activation.h"

#include "neuron.h"

using namespace std;

class Layer {
  private:
  	
  public:
  	Layer(int size_previous_layer, int size, ActivationFunction* activation);
    vector<double> forward(vector<double> input);
    vector<double> bias;
    vector<Neuron> neurons;
    vector<double> prev_in;
    vector<double> net;
    vector<double> out;
    ActivationFunction* activation;
};

#endif