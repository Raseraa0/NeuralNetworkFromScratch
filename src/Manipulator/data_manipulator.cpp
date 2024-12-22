#include "Manipulator/data_manipulator.h"
#include "exception.h"
#include <iostream>

data_manip::data_manip(std::string p) : path(p) {
  file = std::ifstream(path, std::ios::binary);
  if (!file.is_open()) {
    throw err::io_exception("Error while attempting opening a file", path);
  }
}

data_manip::~data_manip() = default;
