#include <exception>
#include <string>

using namespace std;

class BadCredentials : public exception {
private:
  string message;
public:
    BadCredentials(const char* msg)
      : message(msg)
    {
    }

    const char* what() const throw()
    {
      return message.c_str();
    }
};
