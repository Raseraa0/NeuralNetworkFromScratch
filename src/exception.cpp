
#include "exception.h"

err::dimension_exception::dimension_exception(const std::string& m)
    : message(m) {}

err::dimension_exception::dimension_exception(const std::string& m, size_t x1,
                                              size_t y1, size_t x2, size_t y2)
    : message(m + "\nFirst: (" + std::to_string(x1) + ", " +
              std::to_string(y1) + ")\nSecond: (" + std::to_string(x2) + ", " +
              std::to_string(y2) + ")\n") {};

const char* err::dimension_exception::what() const noexcept {
  return message.c_str();
}

err::io_exception::io_exception(const std::string& m) : message(m) {}

err::io_exception::io_exception(const std::string& m, const std::string& p)
    : message(m + "\nFile concerned : " + p + "\n") {}

const char* err::io_exception::what() const noexcept { return message.c_str(); }
