#include "DataStructure/mat.h"
#include <iostream>

int main() {

  vector<double> first_line;
  vector<double> second_line;
  vector<double> third_line;

  first_line.push_back(1);
  first_line.push_back(2);
  first_line.push_back(3);
  second_line.push_back(4);
  second_line.push_back(5);
  second_line.push_back(6);
  third_line.push_back(7);
  third_line.push_back(8);
  third_line.push_back(9);

  vector<vector<double>> data;
  data.push_back(first_line);
  data.push_back(second_line);
  data.push_back(third_line);

  mat matrix(data);
  mat vector(second_line);

  std::clog << matrix << std::endl;

  matrix.at(2, 2) = 100;

  std::clog << matrix - matrix << std::endl;

  return 0;
}
