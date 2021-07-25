#include "layer.h"


#include <iostream>
#include <string>

#include "neuron.h"
#include "activation.h"

using namespace std;


Layer::Layer(int size_previous_layer, int size, string activation): size(size), activation(activation){
	this->neurons = (Neuron * ) (malloc(size * sizeof(Neuron)));
	for(int i = 0; i < size; i++) {
		new (&(this->neurons[i])) Neuron(size_previous_layer);
	}
}

double* Layer::forward(double input[]) {
	double* result = new double[this->size];
	for (int i = 0; i < this->size; i++) {
		result[i] = this->neurons[i].weighted_sum(input);
	}
	apply_activation(result, this->size, this->activation);
	for (int i = 0; i < this->size; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return result;
}

int Layer::get_size() {
	return this->size;
}

Layer::~Layer() {
	free(neurons);
}