#ifndef MAT_H
#define MAT_H

#include <ostream>
#include <random>
#include <vector>

using std::vector;

/*
Class for manipulate 2 dimension matrix
*/
class mat {

public:
  /* Constructor to build the 2D matrix*/
  mat(const vector<vector<double>>& d);

  /* Constructor to build a 1D columns vector */
  mat(const vector<double>& d);

  /*
  Useful for iterate throw the object
  return a pointer to the first element
  */
  const vector<vector<double>>::const_iterator begin() const;

  /*
  Useful for iterate throw the object
  return a pointer just after the last element
  */
  const vector<vector<double>>::const_iterator end() const;

  /* Getter for n_rows */
  size_t get_n_rows() const;

  /* Getter for n_cols */
  size_t get_n_cols() const;

  /* Return the corresponding element in the matrix */
  double at(size_t i, size_t j) const;

  /* Return pointer to set the corresponding element in the matrix */
  double& at(size_t i, size_t j);

  /* Return the matrix transposed */
  mat transpose() const;

  /* Checking the dimension of the given matrix is the same */
  void check_dimension(const mat& other) const;

  /* Return the dot product with the given matrix */
  double dot(const mat& other) const;

  /* Overload of the - unary operator */
  mat operator-() const;

  /* Overload of the += operator */
  mat& operator+=(const mat& other);

  /* Overload of the -= operator */
  mat& operator-=(const mat& other);

private:
  /* All elements of the matrix */
  vector<vector<double>> data;

  /* Number of rows of the matrix */
  size_t n_rows;

  /* Number of clumns of the matrix */
  size_t n_cols;
};

/* Overload operator for << (print to the output) */
inline std::ostream& operator<<(std::ostream& out, const mat& m) {
  out << "2DMatrix: (" << m.get_n_rows() << ":" << m.get_n_cols() << ")"
      << std::endl;
  for (const auto& line : m) {
    for (const auto& elem : line) {
      out << elem << "\t";
    }
    out << std::endl;
  }
  return out;
}

/* Overload operator for + */
inline mat operator+(const mat& m, const mat& n) {
  m.check_dimension(n);
  vector<vector<double>> res;
  for (size_t i = 0; i < m.get_n_rows(); i++) {
    vector<double> line;
    for (size_t j = 0; j < m.get_n_cols(); j++) {
      line.push_back(m.at(i, j) + n.at(i, j));
    }
    res.push_back(line);
  }
  return res;
}

/* Overload operator for - */
inline mat operator-(const mat& m, const mat& n) {
  m.check_dimension(n);
  vector<vector<double>> res;
  for (size_t i = 0; i < m.get_n_rows(); i++) {
    vector<double> line;
    for (size_t j = 0; j < m.get_n_cols(); j++) {
      line.push_back(m.at(i, j) - n.at(i, j));
    }
    res.push_back(line);
  }
  return res;
}

/* Namepace for matrix utils */
namespace mat_ut {

/* Return a matrix with all elem follow normal distribution */
inline mat random_n(size_t n_rows, size_t n_cols, double mu, double sig) {

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mu, sig);

  vector<vector<double>> res;
  for (size_t i = 0; i < n_rows; i++) {
    vector<double> line;
    for (size_t j = 0; j < n_cols; j++) {
      line.push_back(distribution(generator));
    }
    res.push_back(line);
  }
  return mat(res);
}

/* Return a matrix with all elem follow normal distribution 0,1 */
inline mat random_n(size_t n_rows, size_t n_cols) {
  return random_n(n_rows, n_cols, 0, 1);
}

} // namespace mat_ut

#endif // !MAT_H
