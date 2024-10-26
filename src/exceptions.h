#include <exception>
#include <string>

using namespace std;

class BadCredentials : public exception {
private:
  string message = "Bad Credentails: ";
public:
    BadCredentials(const string msg)
    {
      message += msg + "\n";
    }

    const char* what() const throw()
    {
      return message.c_str();
    }
};

class InvalidDollarInput : public exception {
private:
  string message = "Invalid Dollar input: ";
public:
    InvalidDollarInput(const string msg)
    {
      message += msg + "\n";
    }

    const char* what() const throw()
    {
      return message.c_str();
    }
};

class InsufficientFunds : public exception {
private:
  string message = "Insufficient Funds: ";
public:
    InsufficientFunds(const string balance)
    {
      message += balance;
    }

    const char* what() const throw()
    {
      return message.c_str();
    }
};
