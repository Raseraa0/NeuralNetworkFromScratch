#include "Manipulator/label_manipulator.h"
#include "exception.h"
#include "utils.h"
#include <iostream>

label_manip::label_manip(std::string p) : data_manip(p) {

  initialize_parameters();
  current_data++;
}

void label_manip::print_info() const {

  std::clog << "Magic number : " << magic_number << std::endl;
  std::clog << "Number of images : " << n_data << std::endl;
}

void label_manip::initialize_parameters() {

  file.read((char*)&magic_number, sizeof(magic_number));
  magic_number = uti::reverse_int(magic_number);

  file.read((char*)&n_data, sizeof(n_data));
  n_data = uti::reverse_int(n_data);
}

int label_manip::next_label(int i) {
  if (i != current_data + 1) {
    std::string mess = "Error while parsing the file, index " +
                       std::to_string(i) + " and index " +
                       std::to_string(current_data) + " are not corresponding";
    throw err::io_exception(mess, this->path);
  }
  return next_label();
}

int label_manip::next_label() {

  std::vector<int> res;

  unsigned char val;
  file.read((char*)&val, sizeof(val));

  current_data++;
  return val;
}
