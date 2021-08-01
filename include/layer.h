#ifndef Layer_H
#define Layer_H

#include <vector>

#include "activation.h"
#include "neuron.h"

class Layer {
  public:
  	Layer(int size_previous_layer, int size, ActivationFunction* activation);
    std::vector<double> forward(std::vector<double> input);

    ActivationFunction* activation;
    std::vector<Neuron> neurons;
    std::vector<double> bias;

    std::vector<double> prev_in;
    std::vector<double> net;
    std::vector<double> out;
};

#endif