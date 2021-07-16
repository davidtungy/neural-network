#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Layer {
	private:
		int num_nodes_;
		string activation_;
		vector<double> values_;
	public:
		Layer(int num_nodes, string activation);
		Layer(double values[], string activation);
		vector<double> get_values();
		string get_activation();
};