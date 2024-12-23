#include "utils.h"

int uti::reverse_int(int i) {
  unsigned char i1, i2, i3, i4;
  i1 = i & 255;
  i2 = (i >> 8) & 255;
  i3 = (i >> 16) & 255;
  i4 = (i >> 24) & 255;

  return (static_cast<int>(i1) << 24) + (static_cast<int>(i2) << 16) +
         (static_cast<int>(i3) << 8) + static_cast<int>(i4);
}
