
#include "image_manipulator.h"
#include "utils.h"
#include <iostream>

image_manip::image_manip(std::string path) : data_manip(path) {
  initialize_parameters();
  current_data++;
}

void image_manip::print_info() const {

  std::clog << "Magic number : " << magic_number << std::endl;
  std::clog << "Number of images : " << n_data << std::endl;
  std::clog << "Number of rows : " << n_rows << std::endl;
  std::clog << "Number of columns : " << n_cols << std::endl;
}

void image_manip::initialize_parameters() {

  file.read((char*)&magic_number, sizeof(magic_number));
  magic_number = uti::reverse_int(magic_number);

  file.read((char*)&n_data, sizeof(n_data));
  n_data = uti::reverse_int(n_data);

  file.read((char*)&n_rows, sizeof(n_rows));
  n_rows = uti::reverse_int(n_rows);

  file.read((char*)&n_cols, sizeof(n_cols));
  n_cols = uti::reverse_int(n_cols);
}

void image_manip::print_image(int index) {
  std::clog << "Warning this function break everything, just use it a the "
               "start of the programe for showing a specified image."
            << std::endl;
  for (int k = 0; k < index ; k++) {
    next_image();
  }
  std::cout << "P2\n" << n_cols << " " << n_rows << " 255" << std::endl;
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      unsigned char val = 0;
      file.read((char*)&val, sizeof(val));
      std::cout << (int)val << std::endl;
    }
  }
}

std::vector<int> image_manip::next_image(int i) {
  if (i != current_data + 1) {
    std::cerr << "Error while parsing, index are not corresponding"
              << std::endl;
    exit(0);
  }
  return next_image();
}

std::vector<int> image_manip::next_image() {

  std::vector<int> res;

  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      unsigned char val;
      file.read((char*)&val, sizeof(val));
      res.push_back((int)val);
    }
  }

  current_data++;
  return res;
}
