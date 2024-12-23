#include "DataStructure/dataset.h"
#include "exception.h"
#include "utils.h"

#include <fstream>

using std::ifstream;

dataset dataset::load_mnist_dataset(std::string x_train_path,
                                    std::string y_train_path,
                                    std::string x_test_path,
                                    std::string y_test_path) {

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

dataset::dataset(mat x_tr, mat y_tr, mat x_te, mat y_te)
    : x_train(x_tr), y_train(y_tr), x_test(x_te), y_test(y_te) {}

mat dataset::load_images(std::string path) {
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
mat dataset::load_labels(std::string path) {

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

