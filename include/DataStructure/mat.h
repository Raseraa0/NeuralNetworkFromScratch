#ifndef MAT_H
#define MAT_H

#include <iterator>
#include <ostream>
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
  const vector<double>* begin() const;

  /*
  Useful for iterate throw the object
  return a pointer just after the last element
  */
  const vector<double>* end() const;

  /* Getter for n_rows */
  int get_n_rows() const;

  /* Getter for n_cols */
  int get_n_cols() const;

  /* Return the corresponding element in the matrix */
  double at(int i, int j) const;

  /* Return pointer to set the corresponding element in the matrix */
  double& at(int i, int j);

  /* Return the matrix transposed */
  mat transpose() const;


  void check_dimension(const mat& other) const ;

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

#endif // !MAT_H