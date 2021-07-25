#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "neuron.h"

using namespace std;
using namespace testing;

class NeuronTest : public ::testing::Test {

};

class MockNeuron : public Neuron {
public:
	MockNeuron(int size): Neuron(size) {};
	MockNeuron(int size, double bias): Neuron(size, bias) {};
	MOCK_METHOD(double*, get_weights, (), (override));
};

// Not a very robust test, maybe should test distribution instead
TEST_F(NeuronTest, RandomWeightInitialization) {
	int size = 100;
	Neuron n(size);
	double* weights = n.get_weights();
	for (int i = 0; i < size; i++) {
		EXPECT_GE(weights[i], 0);
		EXPECT_LE(weights[i], 1);
	}
}

TEST_F(NeuronTest, WeightedSum) {
	int size = 5;
	double bias = 1.6;
	MockNeuron neuron(size, bias);
	// Mock neuron weights as [1, 2, 3, 4, 5]
	double* weights = new double[size];
	for (int i = 0; i < size; i++) {
		weights[i] = i + 1;
	}
	EXPECT_CALL(neuron, get_weights())
	.Times(1)
	.WillRepeatedly(Return(weights));

	double input[5] = {1, 5, 3, 2, 0.1};
	double weighted_sum = neuron.weighted_sum(input);
	EXPECT_EQ(weighted_sum, 30.1);

	free(weights);
}