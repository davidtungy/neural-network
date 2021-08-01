#ifndef NeuralNetwork_H
#define NeuralNetwork_H

#include <vector>

#include "activation.h"
#include "layer.h"
#include "loss.h"

class NeuralNetwork {
  private:
  	std::vector<Layer> layers;
  	Loss* loss;
  	
  public:
  	NeuralNetwork();
    void add_layer(int size_previous_layer, int size, ActivationFunction* activation);
    void set_loss(Loss* loss);
    std::vector<double> forward(std::vector<double> input);
    void backward(std::vector<double> actual);
    void train(std::vector<std::vector<double>> X_train, std::vector<std::vector<double>> y_train);
    void validate(std::vector<std::vector<double>> X_val, std::vector<std::vector<double>> y_val);
};

#endif