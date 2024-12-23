#ifndef DATASET_H
#define DATASET_H

#include "DataStructure/mat.h"

class dataset {
public:
  static dataset load_mnist_dataset(std::string x_train_path,
                                    std::string y_train_path,
                                    std::string x_test_path,
                                    std::string y_test_path);

 const mat& get_x_train() const;
 const mat& get_y_train() const;
 const mat& get_x_test() const;
 const mat& get_y_test() const;

private:
  mat x_train;
  mat y_train;
  mat x_test;
  mat y_test;

  dataset(mat x_tr, mat y_tr, mat x_te, mat y_te);

  static mat load_images(std::string path);
  static mat load_labels(std::string path);
};

#endif // !DATASET_H
