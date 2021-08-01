#include "neural_network.h"

#include <iostream>
#include <assert.h>
#include <limits>
#include <queue>
#include "activation.h"
#include "loss.h"

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

void NeuralNetwork::set_loss(Loss* loss) {
	this->loss = loss;
}

vector<double> NeuralNetwork::forward(vector<double> input) {
	vector<double> layer_output = input;
	for(int i = 0; i < layers.size(); i++) {
		layer_output = layers[i].forward(layer_output);
	}
	return layer_output;
}

// Rough working of backprop
void NeuralNetwork::backward(vector<double> actual) {
	// TO DO: update weights AFTER updating the cache (use original weights in all scenarios)
	double lr = 0.05;

	queue<double> cache;

	vector<double> output = layers[layers.size()-1].out;

	cache = loss->partial(actual, output);

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

				//cout << "First (cached): " << cached_element << endl;
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

void NeuralNetwork::train(vector<vector<double>> X_train, vector<vector<double>> y_train) {

	double min_loss = std::numeric_limits<double>::max();
	int count = 0;

	for (int epoch = 0; epoch < 500; epoch++) {

		// Track cumulative loss across entire epoch
		double cumulative_loss = 0;

		// iterate across all training examples
		for (int i = 0; i < X_train.size(); i++) {
			vector<double> output = forward(X_train[i]);

			cumulative_loss += loss->calculate_loss(y_train[i], output);

			backward(y_train[i]);
		}

		if (epoch % 10 == 0) {
			cout << "Epoch " << epoch << " Loss: " << cumulative_loss << " Average Loss: " << cumulative_loss/X_train.size() << endl;
		}

		// Early stopping (exit loop if loss doesn't decrease for 10 iterations in a row)
		
		if (cumulative_loss < min_loss) {
			count = 0;
			min_loss = cumulative_loss;
		} else {
			count++;
			if (count == 20) {
				break;
			}
		}

		
	}
}
void NeuralNetwork::validate(vector<vector<double>> X_val, vector<vector<double>> y_val) {
	double cumulative_loss = 0;
	for (int i = 0; i < X_val.size(); i++) {
		vector<double> output = forward(X_val[i]);
		cumulative_loss += loss->calculate_loss(y_val[i], output);
	}
	cout << "Validation Loss: " << cumulative_loss << " Average Loss: " << cumulative_loss/X_val.size() << endl;
}

void NeuralNetwork::print_result() {
	for (int i = 0; i < layers[layers.size()-1].out.size(); i++) {
		cout << layers[layers.size()-1].out[i] << " ";
	}
	cout << endl;
}
