#ifndef Neuron_H
#define Neuron_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Neuron {
  private:
  	
  public:
  	Neuron(int size);
    int size;
    // same length as size of previous layer (fully connected)
    double* weights;
  	virtual double weighted_sum(double input[]);
  	virtual double* get_weights();
  	void print_weights();
  	virtual double random_weight();
  	~Neuron();
};

#endif