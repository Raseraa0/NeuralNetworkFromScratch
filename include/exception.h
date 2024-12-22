#include <exception>
#include <string>

namespace err {

class dimension_exception : public std::exception {
private:
  const std::string message;

public:
  dimension_exception(const std::string& m);

  dimension_exception(const std::string&, size_t x1, size_t y1, size_t x2,
                      size_t y2);

  const char* what() const noexcept override;
};

class io_exception : public std::exception {
private:
  const std::string message;

public:
  io_exception(const std::string& m);

  io_exception(const std::string& m, const std::string& path);

  const char* what() const noexcept override;
};

} // namespace err
