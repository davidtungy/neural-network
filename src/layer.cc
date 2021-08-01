#include "layer.h"

#include "activation.h"
#include "neuron.h"


Layer::Layer(int size_previous_layer, int size, ActivationFunction* activation): activation(activation){
	for(int i = 0; i < size; i++) {
		neurons.push_back(Neuron(size_previous_layer));
		// TO DO: randomize bias
		bias.push_back(0.5*i + 0.5);
	}
}

std::vector<double> Layer::forward(std::vector<double> input) {
	this->prev_in = input;
	std::vector<double> result;
	for (int i = 0; i < neurons.size(); i++) {
		result.push_back(neurons[i].weighted_sum(input) + bias[i]);
		neurons[i].net = result[i];
	}
	this->net = result;
	result = activation->apply_activation(result);
	this->out = result;
	return result;
}
