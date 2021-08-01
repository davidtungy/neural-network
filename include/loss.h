#ifndef Loss_H
#define Loss_H

#include <vector>
#include <queue>

class Loss {
public:
  virtual double calculate_loss (std::vector<double> actual, std::vector<double> predicted) = 0;
  virtual std::queue<double> partial (std::vector<double> actual, std::vector<double> predicted) = 0;
};

#endif