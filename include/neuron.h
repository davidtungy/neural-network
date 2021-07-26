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
    vector<double> weights;
  	virtual double weighted_sum(vector<double>);
  	virtual vector<double> get_weights();
  	void print_weights();
  	virtual double random_weight();
};

#endif