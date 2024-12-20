#ifndef LABEL_MANIPULATOR_H
#define LABEL_MANIPULATOR_H

#include "data_manipulator.h"
#include <vector>

class label_manip : public data_manip {

public:
  label_manip(std::string path);

  void print_info() const override;

  int next_label();
  int next_label(int i);

protected:
  void initialize_parameters() override;
};

#endif // !LABEL_MANIPULATOR_H
