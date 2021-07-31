#include "neural_network.h"

#include <iostream>
#include <assert.h>
#include <queue>
#include "activation.h"

using namespace std;


NeuralNetwork::NeuralNetwork() {
}

void NeuralNetwork::add_layer(int size_previous_layer, int size, ActivationFunction* activation) {
	if (this->layers.empty()) {
		this->layers.push_back(Layer(size_previous_layer, size, activation));
	} else {
		assert(this->layers.back().neurons.size() == size_previous_layer);
		this->layers.push_back(Layer(size_previous_layer, size, activation));
	}
}

vector<double> NeuralNetwork::forward(vector<double> input) {
	vector<double> layer_output = input;
	for(int i = 0; i < layers.size(); i++) {
		layer_output = layers[i].forward(layer_output);
	}
	return layer_output;
}

// Rough working of backprop
void NeuralNetwork::backward(vector<double> target) {
	// TO DO: update weights AFTER updating the cache (use original weights in all scenarios)
	double lr = 0.05;

	queue<double> cache;

	for(int i = 0; i < target.size(); i++) {
		cache.push(-(target[i] - layers[layers.size()-1].out[i]));
	}

	vector<double> TEMP_CACHE;

	for (int i = layers.size() - 1; i >= 0; i--) {
		Layer current_layer = layers[i];
		ActivationFunction* activation = current_layer.activation;

		vector<double> out = layers[i].out;
		vector<double> net = layers[i].net;
		vector<double> previous_out = layers[i].prev_in;

		
		for (int j = 0; j < layers[i].neurons.size(); j++) {
			double cached_element = cache.front();
			TEMP_CACHE.push_back(cached_element * activation->partial(net[j]));

			for (int k = 0; k < layers[i].neurons[j].weights.size(); k++) {

				//cout << "First (cached): " << cached_elem << endl;
				//cout << "Second: sigmoid partial of " << net[j] << " = " << activation->partial(net[j]) << endl;
				//cout << "Third: out of previous layer neuron " << previous_out[k] << endl;
				// Update neuron weight
				double update = cached_element * activation->partial(net[j]) * previous_out[k];
				layers[i].neurons[j].weights[k] = layers[i].neurons[j].weights[k] - lr * update;
			}
			// Update bias weight
			layers[i].bias[j] = layers[i].bias[j] - lr * cached_element * activation->partial(out[j]);
			cache.pop();
		}

		if (i > 0) {
			for (int j = 0; j < layers[i].prev_in.size(); j++) {
				double sum = 0;
				for (int l = 0; l < layers[i].neurons.size(); l++) {
					sum += layers[i].neurons[l].weights[j] * TEMP_CACHE[l];
				}
				cache.push(sum);
			}
			TEMP_CACHE.clear();
		}

	}
}

void NeuralNetwork::print_result() {
	for (int i = 0; i < layers[layers.size()-1].out.size(); i++) {
		cout << layers[layers.size()-1].out[i] << " ";
	}
	cout << endl;
}
