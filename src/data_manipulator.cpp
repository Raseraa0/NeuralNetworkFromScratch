#include "data_manipulator.h"
#include <iostream>

data_manip::data_manip(std::string path) {
  file = std::ifstream(path, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error while attempting opening the file : " << path
              << std::endl;
    exit(1);
  }

}

data_manip::~data_manip() = default;

void data_manip::initialize_parameters() {};

