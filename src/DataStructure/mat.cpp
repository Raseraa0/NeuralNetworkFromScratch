#include "DataStructure/mat.h"
#include <iostream>

mat::mat(const vector<vector<double>>& d)
    : data(d), n_rows(d.size()), n_cols(d.at(0).size()) {
  for (size_t i = 0; i < n_rows; i++) {
    if (d.at(i).size() != n_cols) {
      std::cerr << "Error : matrix given to the constructor is not rectangular"
                << std::endl;
      exit(1);
    }
  }
}

mat::mat(const vector<double>& d) {
  for (const auto& elem : d) {
    vector<double> line;
    line.push_back(elem);
    data.push_back(line);
  }
  n_rows = d.size();
  n_cols = 1;
}

mat::~mat() = default;

const vector<double>* mat::begin() const { return &data.front(); }
const vector<double>* mat::end() const { return &data.back() + 1; }

int mat::get_n_rows() const { return n_rows; }

int mat::get_n_cols() const { return n_cols; }
