#include "neural_network.h"

#include <iostream>
#include <assert.h>
#include <queue>
#include "activation.h"

using namespace std;


NeuralNetwork::NeuralNetwork() {
}

void NeuralNetwork::add_layer(int size_previous_layer, int size, string activation) {
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
void NeuralNetwork::backward(vector<double> target, vector<double> input) {
	// TO DO: update weights AFTER updating the cache (use original weights in all scenarios)
	double lr = 0.2;

	queue<double> cache;

	cout << "TARGET: " << endl;
	for(int i = 0; i < target.size(); i++) {
		cout << target[i] << " ";
		// TO DO: take out the hard coding here
		cache.push(-(target[i] - layers[layers.size()-1].out[i]));
		cache.push(-(target[i] - layers[layers.size()-1].out[i]));
	}
	cout << endl;

	vector<double> TEMP_CACHE;

	for (int i = layers.size() - 1; i >= 0; i--) {
		vector<double> out = layers[i].out;
		vector<double> net = layers[i].net;
		/*
		cout << "LAYER " << i << " contains " << layers[i].neurons.size() << " neurons" << endl;

		cout << "Layer " << i << " out: ";
		for (int outs = 0; outs < out.size(); outs++) {
				cout << out[outs] << " ";
			}
		cout << endl;
		*/
		vector<double> previous_out = layers[i].prev_in;

		
		for (int j = 0; j < layers[i].neurons.size(); j++) {
			/*
			cout << "Layer " << i << " Neuron " << j << " weights: ";
			for (int k = 0; k < layers[i].neurons[j].weights.size(); k++) {
				cout << layers[i].neurons[j].weights[k] << " ";
			}
			cout << endl;
			cout << "Layer " << i << " Neuron " << j << " net: " << layers[i].neurons[j].net << endl;
			*/
			cout << "Adding to temp cache: " << cache.front() << " * " << sigmoid_partial(net[j]) << endl;
			TEMP_CACHE.push_back(cache.front() * sigmoid_partial(net[j]));

			for (int k = 0; k < layers[i].neurons[j].weights.size(); k++) {
				double cached_elem = cache.front();
				//cout << "First: " << "- (" << cached_elem << " - " << out[j] << ")" << " = ";
				//cout << -(cached_elem - out[j]) << endl;

				// TO DO: take out hard coding for partials
				cout << "First (cached): " << cached_elem << endl;
				cout << "Second: sigmoid partial of " << net[j] << " = " << sigmoid_partial(net[j]) << endl;
				cout << "Third: out of previous layer neuron " << previous_out[k] << endl;
				// UPDATE neuron weight
				double update = cached_elem * sigmoid_partial(net[j]) * previous_out[k];
				cout << "Update value is: " << update << endl;
				cout << "UPDATING " << layers[i].neurons[j].weights[k] << " to ";
				layers[i].neurons[j].weights[k] = layers[i].neurons[j].weights[k] - lr * update;
				cout << layers[i].neurons[j].weights[k] << endl;
				cache.pop();
			}
			layers[i].bias[j] = layers[i].bias[j] - lr * cache.front() * sigmoid_partial(out[j]);
		}
		cout << " DONE UPDATING LAYER " << i << endl;
		cout << "-------------------" << endl;
		cout << "TEMP_CACHE: ";
		for (int l = 0; l < TEMP_CACHE.size(); l++) {
			cout << TEMP_CACHE[l] << " ";
		}
		cout << endl;
		if (i > 0) {
			for (int j = 0; j < layers[i].prev_in.size(); j++) {
				double sum = 0;
				for (int l = 0; l < layers[i].neurons.size(); l++) {
					cout << layers[i].neurons[l].weights[j] << " * " << TEMP_CACHE[l] << " + ";
					sum += layers[i].neurons[l].weights[j] * TEMP_CACHE[l];
				}
				cout << " = " << sum << endl;
				for (int l = 0; l < layers[i-1].prev_in.size(); l++) {
					cache.push(sum);
				}
			}
			TEMP_CACHE.clear();
		}

	}
}