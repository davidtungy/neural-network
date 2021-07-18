#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "layer.h"
#include "neuron.h"

using namespace std;


class LayerTest : public ::testing::Test {

};

// Not a very robust test, maybe should test distribution instead
TEST_F(LayerTest, RandomNodeValueInitialization) {
	int num_nodes = 100;
	Layer l(num_nodes, "sigmoid");
	vector<Neuron*> weights = l.get_weights();
	// One extra node for bias term
	EXPECT_EQ(weights.size(), num_nodes + 1);
	for (int i = 0; i < num_nodes + 1; i++) {
		EXPECT_GE(weights[i]->weight, 0);
		EXPECT_LE(weights[i]->weight, 1);
	}
}

TEST_F(LayerTest, FixedNodeValueInitialization) {
	int num_nodes = 7;
	vector<double> presets = {1, 3, 5, 1, 35, 0.3, -135};
	Layer l(num_nodes, presets, "linear");
	vector<Neuron*> weights = l.get_weights();
	// No extra bias term
	EXPECT_EQ(weights.size(), num_nodes);
	for (int i = 0; i < num_nodes; i++) {
		EXPECT_EQ(weights[i]->weight, presets[i]);
	}
}