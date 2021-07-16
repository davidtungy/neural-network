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