#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "layer.h"

using namespace std;


class LayerTest : public ::testing::Test {

};

// Not a very robust test, maybe should test distribution instead
TEST_F(LayerTest, RandomNodeValueInitialization) {
	int num_nodes = 100;
	Layer l(num_nodes, "sigmoid");
	vector<double> values = l.get_values();
	// One extra node for bias term
	EXPECT_EQ(values.size(), num_nodes + 1);
	for (int i = 0; i < num_nodes + 1; i++) {
		EXPECT_GE(values[i], 0);
		EXPECT_LE(values[i], 1);
	}
}

TEST_F(LayerTest, FixedNodeValueInitialization) {
	int num_nodes = 7;
	double vals[] = {1, 3, 5, 1, 35, 0.3, -135};
	Layer l(num_nodes, vals, "linear");
	vector<double> values = l.get_values();
	EXPECT_EQ(values.size(), num_nodes);
	for (int i = 0; i < num_nodes; i++) {
		EXPECT_EQ(values[i], vals[i]);
	}
}