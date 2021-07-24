#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <time.h>
#include "neuron.h"
#include "layer.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));
	double input[5] = {1, 1, 2, 1, 1};

	// TO DO: add to test
	Layer* l = new Layer(5, 5, "sigmoid");
	double* res = l->forward(input);
	cout << "RESULT: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << res[i] << endl;
	}
	free(res);
}