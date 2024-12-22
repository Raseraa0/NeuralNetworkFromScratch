#ifndef DATA_MANIPULATOR_H
#define DATA_MANIPULATOR_H

#include <fstream>
#include <string>

/*
Abstract class
The goal of this class is to manipulate files from a given path
*/
class data_manip {

public:
  /* Constructor with juste the path of the target file */
  data_manip(std::string path);

  /* Virtual destructor */
  virtual ~data_manip();

  /*
  Print information about the file
  These data are found in the header of the file
  */
  virtual void print_info() const = 0;

protected:
  /* Opened stream for reading the binay file */
  std::ifstream file;

  /* Magic number, to be sur we are on the right file */
  int magic_number;

  /* number of data we have in the file */
  int n_data;

  /* Index of the last data we have read */
  int current_data;

  /* Initialize the parameters of the file by reading the header */
  virtual void initialize_parameters() = 0;
};

#endif // !DATA_MANIPULATOR_H
