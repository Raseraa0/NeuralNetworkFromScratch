#include "DataStructure/dataset.h"
#include "exception.h"
#include "utils.h"

#include <algorithm>
#include <fstream>
#include <stdexcept>

using std::ifstream;

dataset dataset::load_mnist_dataset(const std::string& x_train_path,
                                    const std::string& y_train_path,
                                    const std::string& x_test_path,
                                    const std::string& y_test_path) {

  mat x_train = dataset::load_images(x_train_path);
  mat y_train = dataset::load_labels(y_train_path);
  mat x_test = dataset::load_images(x_test_path);
  mat y_test = dataset::load_labels(y_test_path);

  return dataset(x_train, y_train, x_test, y_test);
}

const mat& dataset::get_x_train() const { return x_train; }
const mat& dataset::get_y_train() const { return y_train; }
const mat& dataset::get_x_test() const { return x_test; }
const mat& dataset::get_y_test() const { return y_test; }

dataset::dataset(const mat& x_tr, const mat& y_tr, const mat& x_te,
                 const mat& y_te)
    : x_train(x_tr), y_train(y_tr), x_test(x_te), y_test(y_te) {}

mat dataset::load_images(const std::string& path) {
  std::ifstream file = std::ifstream(path, std::ios::binary);
  if (!file.is_open()) {
    throw err::io_exception("Error while attempting opening a file", path);
  }

  int magic_number;
  int n_data;
  int n_rows;
  int n_cols;

  file.read((char*)&magic_number, sizeof(magic_number));
  magic_number = uti::reverse_int(magic_number);

  file.read((char*)&n_data, sizeof(n_data));
  n_data = uti::reverse_int(n_data);

  file.read((char*)&n_rows, sizeof(n_rows));
  n_rows = uti::reverse_int(n_rows);

  file.read((char*)&n_cols, sizeof(n_cols));
  n_cols = uti::reverse_int(n_cols);

  vector<vector<double>> res;

  for (int num = 0; num < n_data; num++) {
    vector<double> line;
    for (int i = 0; i < n_rows; i++) {
      for (int j = 0; j < n_cols; j++) {
        unsigned char val;
        file.read((char*)&val, sizeof(val));
        line.push_back((double)val);
      }
    }
    res.push_back(line);
  }
  file.close();
  return mat(res);
}
mat dataset::load_labels(const std::string& path) {

  std::ifstream file = std::ifstream(path, std::ios::binary);
  if (!file.is_open()) {
    throw err::io_exception("Error while attempting opening a file", path);
  }

  int magic_number;
  int n_data;

  file.read((char*)&magic_number, sizeof(magic_number));
  magic_number = uti::reverse_int(magic_number);

  file.read((char*)&n_data, sizeof(n_data));
  n_data = uti::reverse_int(n_data);

  vector<double> res;

  for (int num = 0; num < n_data; num++) {
    unsigned char val;
    file.read((char*)&val, sizeof(val));
    res.push_back(val);
  }
  file.close();
  return mat(res);
}

dataset dataset::new_random_split(double test_ratio) const {
  if (test_ratio < 0 || test_ratio > 1) {
    throw std::invalid_argument("The ratio must be include into [0,1]");
  }

  mat all_x(this->get_x_train());
  mat all_y(this->get_y_train());

  all_x.concatenate_under(this->get_x_test());
  all_y.concatenate_under(this->get_y_test());

  if (all_x.get_n_rows() != all_y.get_n_rows()) {
    throw err::dimension_exception(
        "Different number of data in observation and label", all_x.get_n_rows(),
        all_x.get_n_cols(), all_y.get_n_rows(), all_y.get_n_cols());
  }

  vector<size_t> rows_index;
  for (size_t i = 0; i < all_x.get_n_rows(); i++) {
    rows_index.push_back(i);
  }
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::shuffle(rows_index.begin(), rows_index.end(), generator);

  vector<vector<double>> new_x_train;
  vector<vector<double>> new_x_test;
  vector<vector<double>> new_y_train;
  vector<vector<double>> new_y_test;

  size_t test_size = test_ratio * all_x.get_n_rows();

  for (size_t i = 0; i < test_size; i++) {
    new_x_test.push_back(all_x.line_at(rows_index.at(i)));
    new_y_test.push_back(all_y.line_at(rows_index.at(i)));
  }

  for (size_t i = test_size; i < all_x.get_n_rows(); i++) {
    new_x_train.push_back(all_x.line_at(rows_index.at(i)));
    new_y_train.push_back(all_y.line_at(rows_index.at(i)));
  }

  return dataset(mat(new_x_train), mat(new_y_train), mat(new_x_test),
                 mat(new_y_test));
}
