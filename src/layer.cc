#include "layer.h"


#include <iostream>
#include <string>

#include "neuron.h"
#include "activation.h"

using namespace std;


Layer::Layer(int size_previous_layer, int size, string activation): activation(activation), bias(0.5){
	for(int i = 0; i < size; i++) {
		neurons.push_back(Neuron(size_previous_layer));
	}
}

vector<double> Layer::forward(vector<double> input) {
	vector<double> result;
	for (int i = 0; i < neurons.size(); i++) {
		result.push_back(neurons[i].weighted_sum(input) + bias);
		cout << this->bias << " = " << result[i] << endl;
	}
	result = apply_activation(result, activation);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "---------" << endl;
	return result;
}
