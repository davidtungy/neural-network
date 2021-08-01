# neural-network
Neural network coded from scratch in C++. Python is definitely better from a practical sense, but this was a fun challenge to test my own understanding.

## Usage

This is meant to simulate common neural network frameworks.

Add layers to the neural network: 

```
add_layer(input_size, output_size, activation)
```

Set the neural network's loss function:

```
set_loss(loss_function)
```

Basic neural network example:
```
NeuralNetwork n;
n.add_layer(4, 2, new Sigmoid());
n.add_layer(2, 2, new Sigmoid());
n.add_layer(2, 2, new LReLU());
n.set_loss(new MSE());

n.train(X_train, y_train);
n.validate(X_val, y_val);
```

## Proof of concept

Define a nonlinear multivariable function:

(x1, x2, x3, x4) => (y1, y2), where:

y1 = x3 + (1.8 * x1) - x2 + x4

y2 = x1 + x4 * x2

![loss](https://github.com/davidtungy/neural-network/blob/main/plot.png)

## Design

The neural network consists of layers, which in turn consist of neurons.

During forward propagation, each neuron calculates it's net output and passes it to its layer. The layer then applies a non-linear activation to each neuron's output. This in turn is passed into the next layer as its input.

During backpropagation, each layer updates its neurons weights. During calculation, each layer is also responsible for caching weights that the next (previous) layer will use.

## Installation

CMakeList.txt should take care of external dependencies (Google Test framework).

```
git clone https://github.com/davidtungy/neural-network.git
mkdir build
cd build
cmake ..
make
```
Run the program via:

```
bin/main
```
