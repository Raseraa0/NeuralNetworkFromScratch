#ifndef DATASET_H
#define DATASET_H

#include "DataStructure/mat.h"

/*
Class for manipulate a whole data set
*/
class dataset {
public:
  /* Load the specific dataset Mnist*/
  static dataset load_mnist_dataset(const std::string& x_train_path,
                                    const std::string& y_train_path,
                                    const std::string& x_test_path,
                                    const std::string& y_test_path);

  /* Getter for x_train */
  const mat& get_x_train() const;

  /* Getter for y_train */
  const mat& get_y_train() const;

  /* Getter for x_test */
  const mat& get_x_test() const;

  /* Getter for y_test */
  const mat& get_y_test() const;

  /* This create new dataset with same value but with randomizing order */
  dataset new_random_split(double test_ratio) const;

private:
  /* Matrix containing the traning data observation */
  mat x_train;

  /* Matrix containing the training corresponding label */
  mat y_train;

  /* Matrix containing the test data observation */
  mat x_test;

  /* Matrix containing the testing corresponding label */
  mat y_test;

  /* Private constructor, the only wat to obtain dataset is by static method */
  dataset(const mat& x_tr, const mat& y_tr, const mat& x_te, const mat& y_te);

  /* Load matrix from the path of the file (for image format) */
  static mat load_images(const std::string& path);

  /* Load matrix from the path of the file (for label format) */
  static mat load_labels(const std::string& path);
};

#endif // !DATASET_H
