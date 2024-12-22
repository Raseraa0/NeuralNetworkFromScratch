#ifndef IMAGE_MANIPULATOR_H
#define IMAGE_MANIPULATOR_H

#include "Manipulator/data_manipulator.h"
#include <vector>

/*
This class is for reading file containing images
*/
class image_manip : public data_manip {

public:
  /* Constructor with juste the path of the target file */
  image_manip(std::string path);

  /*
  Print information about the file
  These data are found in the header of the file
  */
  void print_info() const override;

  /*
  Print image corresponding to the given index
  This fonction is here to help debugging,
  by helping vizualize a speciic training data

  /!\ This function breaks the flow of the file,
  do not use it in normal context
  */
  void print_image(int index);

  /* Return a vector of all value for one image */
  std::vector<int> next_image();

/* Same as without parameters but with index checking*/
  std::vector<int> next_image(int i);

private:
  /* Number of rows for each images */
  int n_rows;

  /* Number of columns for each images */
  int n_cols;

protected:
  /* Initialize the parameters of the file by reading the header */
  void initialize_parameters() override;
};

#endif // !IMAGE_MANIPULATOR_H
