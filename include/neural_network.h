#ifndef NeuralNetwork_H
#define NeuralNetwork_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "neuron.h"
#include "layer.h"
#include "activation.h"
#include "loss.h"

using namespace std;

class NeuralNetwork {
  private:
  	vector<Layer> layers;
  	
  	
  public:
  	NeuralNetwork();
  	Loss* loss;
    void add_layer(int size_previous_layer, int size, ActivationFunction* activation);
    void set_loss(Loss* loss);
    vector<double> forward(vector<double> input);
    void backward(vector<double> actual);
    void print_result();
    //void train(vector<vector<double>> X_train, vector<vector<double>> y_train);
};

#endif