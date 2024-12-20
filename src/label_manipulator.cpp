

#include "label_manipulator.h"
#include "utils.h"
#include <iostream>

label_manip::label_manip(std::string path) : data_manip(path) {

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
    std::cerr << "Error while parsing, index are not corresponding"
              << std::endl;
    exit(0);
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
