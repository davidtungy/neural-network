#include "layer.h"


#include <iostream>
#include <string>

#include "neuron.h"
#include "activation.h"

using namespace std;


Layer::Layer(int size_previous_layer, int size, string activation): activation(activation){
	for(int i = 0; i < size; i++) {
		neurons.push_back(Neuron(size_previous_layer));
		bias.push_back(0.5*i + 0.5);
	}
}

vector<double> Layer::forward(vector<double> input) {
	this->prev_in = input;
	vector<double> result;
	for (int i = 0; i < neurons.size(); i++) {
		result.push_back(neurons[i].weighted_sum(input) + bias[i]);
		cout << this->bias[i] << " = " << result[i] << endl;
		neurons[i].net = result[i];
	}
	this->net = result;
	result = apply_activation(result, activation);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	this->out = result;
	cout << endl;
	cout << "---------" << endl;
	return result;
}
