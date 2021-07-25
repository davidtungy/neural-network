#include "neuron.h"

#include <iostream>

using namespace std;


Neuron::Neuron(int size): size(size), bias(0.5) {
	this->weights = new double[size];
	for (int i = 0; i < this->size; i++) {
		this->weights[i] = random_weight();
	}
}

Neuron::Neuron(int size, double bias) : Neuron(size){
	this->bias = bias;
}

double Neuron::random_weight() {
	return ((double) rand()) / RAND_MAX;
}

double* Neuron::get_weights() {
	return this->weights;
}

double Neuron::weighted_sum(double input[]) {
	double* current_weights = this->get_weights();
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		cout << input[i] << "*" << current_weights[i] << " ";
		sum += input[i] * current_weights[i];
	}
	cout << " + " << this->bias;
	sum += this->bias;
	cout << " = " << sum << endl;
	return sum;
}

void Neuron::print_weights() {
	for (int i = 0; i < size; i++) {
		cout << this->weights[i] << endl;
	}
}

Neuron::~Neuron() {
	free(weights);
}