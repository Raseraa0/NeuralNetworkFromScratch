#include "DataStructure/dataset.h"
#include <iostream>
int main() {
  std::string x_train_path = "../data/train-images.idx3-ubyte";
  std::string y_train_path = "../data/train-labels.idx1-ubyte";
  std::string x_test_path = "../data/t10k-images.idx3-ubyte";
  std::string y_test_path = "../data/t10k-labels.idx1-ubyte";

  dataset mnist = dataset::load_mnist_dataset(x_train_path, y_train_path,
                                              x_test_path, y_test_path);

std::clog << mnist.get_x_train() << std::endl;
std::clog << mnist.get_y_train() << std::endl;
std::clog << mnist.get_x_test() << std::endl;
std::clog << mnist.get_y_test() << std::endl;
}
