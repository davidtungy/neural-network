#ifndef Layer_H
#define Layer_H

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

#include "neuron.h"

using namespace std;

class Layer {
	private:
		int size_;
		string activation_;
		vector<Neuron*> weights_;
	public:
		Layer(int num_nodes, string activation);
		Layer(int num_nodes, vector<double>, string activation);
		vector<Neuron*> get_weights();
		string get_activation();
};

#endif