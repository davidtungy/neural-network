#include "layer.h"


#include <iostream>
#include <string>

#include "neuron.h"
#include "activation.h"

using namespace std;


Layer::Layer(int size_previous_layer, int size, ActivationFunction* activation): activation(activation){
	for(int i = 0; i < size; i++) {
		neurons.push_back(Neuron(size_previous_layer));
		// TO DO: randomize bias
		bias.push_back(0.5*i + 0.5);
	}
}

vector<double> Layer::forward(vector<double> input) {
	this->prev_in = input;
	vector<double> result;
	for (int i = 0; i < neurons.size(); i++) {
		result.push_back(neurons[i].weighted_sum(input) + bias[i]);
		neurons[i].net = result[i];
	}
	this->net = result;
	result = activation->apply_activation(result);
	this->out = result;
	return result;
}
