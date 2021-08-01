#ifndef Neuron_H
#define Neuron_H

#include <vector>

class Neuron {
  public:
  	Neuron(int size);
    std::vector<double> weights;
    
    double net;

  	virtual double weighted_sum(std::vector<double>);
  	virtual std::vector<double> get_weights();
  	virtual double random_weight();
};

#endif