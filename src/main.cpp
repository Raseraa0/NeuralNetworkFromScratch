#include "Manipulator/image_manipulator.h"
#include "Manipulator/label_manipulator.h"
#include <iostream>

int main() {
  image_manip image("../data/t10k-images.idx3-ubyte");
  label_manip label("../data/t10k-labels.idx1-ubyte");

  image.print_info();
  std::clog << "" << std::endl;
  label.print_info();
  std::clog << "" << std::endl;


  for (int i = 0; i < 69; i++) {
    label.next_label();
  }
  std::clog << label.next_label() << std::endl;

  image.print_image(69);
}
