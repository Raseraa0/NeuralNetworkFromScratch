#ifndef LABEL_MANIPULATOR_H
#define LABEL_MANIPULATOR_H

#include "Manipulator/data_manipulator.h"
#include <vector>

/*
This class is for reading file containing labels
*/
class label_manip : public data_manip {

public:
  /* Constructor with juste the path of the target file */
  label_manip(std::string path);

  /*
  Print information about the file
  These data are found in the header of the file
  */
  void print_info() const override;

  /* Return the value one label*/
  int next_label();

  /* Same as without parameters but with index checking*/
  int next_label(int i);

protected:
  /* Initialize the parameters of the file by reading the header */
  void initialize_parameters() override;
};

#endif // !LABEL_MANIPULATOR_H
