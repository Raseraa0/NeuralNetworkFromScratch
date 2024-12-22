#include "DataStructure/mat.h"
#include "exception.h"

mat::mat(const vector<vector<double>>& d)
    : data(d), n_rows(d.size()), n_cols(d.at(0).size()) {
  for (size_t i = 0; i < n_rows; i++) {
    if (d.at(i).size() != n_cols) {
      throw err::dimension_exception("Matrix is not rectangular");
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

const vector<double>* mat::begin() const { return &data.front(); }
const vector<double>* mat::end() const { return &data.back() + 1; }

size_t mat::get_n_rows() const { return n_rows; }

size_t mat::get_n_cols() const { return n_cols; }

double mat::at(int i, int j) const { return data.at(i).at(j); }

double& mat::at(int i, int j) { return data.at(i).at(j); }

mat mat::transpose() const {
  vector<vector<double>> trans;
  for (size_t col = 0; col < n_cols; col++) {
    vector<double> line;
    for (size_t row = 0; row < n_rows; row++) {
      line.push_back(this->at(row, col));
    }
    trans.push_back(line);
  }
  return mat(trans);
}

void mat::check_dimension(const mat& other) const {
  if (n_rows != other.n_rows || n_cols != other.n_cols) {
    throw err::dimension_exception("Error while checking the dimension", n_rows,
                                   n_cols, other.n_rows, other.n_cols);
  }
}

double mat::dot(const mat& other) const {
  check_dimension(other);
  double sum = 0;
  for (size_t i = 0; i < n_rows; i++) {
    for (size_t j = 0; j < n_cols; j++) {
      sum += this->at(i, j) * other.at(i, j);
    }
  }
  return sum;
}

mat mat::operator-() const {
  vector<vector<double>> res;
  for (size_t i = 0; i < n_rows; i++) {
    vector<double> line;
    for (size_t j = 0; j < n_cols; j++) {
      line.push_back(-this->at(i, j));
    }
    res.push_back(line);
  }
  return mat(res);
}

mat& mat::operator+=(const mat& other) {
  check_dimension(other);
  for (size_t i = 0; i < n_rows; i++) {
    for (size_t j = 0; j < n_cols; j++) {
      this->at(i, j) += other.at(i, j);
    }
  }
  return *this;
}

mat& mat::operator-=(const mat& other) {
  check_dimension(other);
  for (size_t i = 0; i < n_rows; i++) {
    for (size_t j = 0; j < n_cols; j++) {
      this->at(i, j) -= other.at(i, j);
    }
  }
  return *this;
}
