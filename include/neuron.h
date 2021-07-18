#ifndef Neuron_H
#define Neuron_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Neuron {
  private:
  	vector<Neuron*> backlinks;
  public:
  	double weight;
  	Neuron(double weight);
};

#endif