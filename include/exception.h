#include <exception>
#include <string>

/*
In this namepace I am defining some useful exception
The main goal is tu create easier way to write exception message
*/
namespace err {

/*
This is for all exception due to dimension
*/
class dimension_exception : public std::exception {
private:
  /* Message of the exception */
  const std::string message;

public:
  /* Regular exception constructor */
  dimension_exception(const std::string& m);

  /* Constructor with the dimensions which are causing the issue */
  dimension_exception(const std::string&, size_t x1, size_t y1, size_t x2,
                      size_t y2);

  /* Define of the what call */
  const char* what() const noexcept override;
};

/*
This is for all exception due to input/ouput issue
*/
class io_exception : public std::exception {
private:
  /* Message of the exception */
  const std::string message;

public:
  /* Regular exception constructor */
  io_exception(const std::string& m);

  /* Constructor with the path of the file with issue */
  io_exception(const std::string& m, const std::string& path);

  /* Define of the what call */
  const char* what() const noexcept override;
};

} // namespace err
