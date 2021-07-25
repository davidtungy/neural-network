#ifndef Neuron_H
#define Neuron_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Neuron {
  private:
  	int size;
  	// same length as size of previous layer (fully connected)
  	double* weights;
  	double bias;
  public:
  	Neuron(int size);
  	Neuron(int size, double bias);
  	virtual double weighted_sum(double input[]);
  	virtual double* get_weights();
  	void print_weights();
  	virtual double random_weight();
  	~Neuron();
};

#endif