#ifndef DATA_MANIPULATOR_H
#define DATA_MANIPULATOR_H

#include <fstream>
#include <string>

class data_manip {

public:
  data_manip(std::string path);

  virtual ~data_manip();

  virtual void print_info() const = 0;

protected:
  std::ifstream file;
  int magic_number;
  int n_data;
  int current_data;

  virtual void initialize_parameters()  ;
};

#endif // !DATA_MANIPULATOR_H
