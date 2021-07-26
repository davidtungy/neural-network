#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "neuron.h"
#include <vector>

using namespace std;
using namespace testing;

class NeuronTest : public ::testing::Test {

};

class MockNeuron : public Neuron {
public:
	MockNeuron(int size): Neuron(size) {};
	MOCK_METHOD(vector<double>, get_weights, (), (override));
};

// Not a very robust test, maybe should test distribution instead
TEST_F(NeuronTest, RandomWeightInitialization) {
	int size = 100;
	Neuron n(size);
	vector<double> weights = n.get_weights();
	for (int i = 0; i < size; i++) {
		EXPECT_GE(weights[i], 0);
		EXPECT_LE(weights[i], 1);
	}
}

TEST_F(NeuronTest, WeightedSum) {
	int size = 5;
	MockNeuron neuron(size);
	// Mock neuron weights as [1, 2, 3, 4, 5]
	vector<double> weights;
	for (int i = 0; i < size; i++) {
		weights.push_back(i + 1);
	}
	EXPECT_CALL(neuron, get_weights())
	.Times(1)
	.WillRepeatedly(Return(weights));

	vector<double> input = {1, 5, 3, 2, 0.1};
	double weighted_sum = neuron.weighted_sum(input);
	EXPECT_EQ(weighted_sum, 28.5);
}