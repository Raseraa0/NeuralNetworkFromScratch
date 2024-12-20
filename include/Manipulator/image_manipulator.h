#ifndef IMAGE_MANIPULATOR_H
#define IMAGE_MANIPULATOR_H

#include "Manipulator/data_manipulator.h"
#include <vector>

class image_manip : public data_manip {

public:
  image_manip(std::string path);

  void print_info() const override;

  void print_image(int index);

  std::vector<int> next_image();
  std::vector<int> next_image(int i);

private:
  int n_rows;
  int n_cols;

protected:
  void initialize_parameters() override;
};

#endif // !IMAGE_MANIPULATOR_H
