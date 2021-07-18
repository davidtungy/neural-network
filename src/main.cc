#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "neuron.h"
#include "layer.h"
#include "neural_network.h"

using namespace std;

int main(int argc, char* argv[]) {
	Neuron* n= new Neuron(10.0);
	cout << n->weight << endl;

	Layer l(10, "sigmoid");
	vector<Neuron*> weights = l.get_weights();
	for (int i = 0; i < weights.size(); i++) {
		cout << weights[i]->weight << endl;
	}

	NeuralNetwork nn();
	cout << "Dummy neural network" << endl;

}