#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <regex>
#include "doctest.h"

using namespace std;

int parseDollarInput(string input)
{
  int balance;
  if (input.front() == '$')
  {
    input = input.substr(1);
  }

  size_t pos = input.find('.');
  
  if (pos == string::npos)
  {
    balance = stoi(input) * 100;
  }
  else
  {
    balance = stoi(input.erase(pos, 1));
  }
  return balance;
}

TEST_CASE("testing the factorial function") {
  CHECK(parseDollarInput("12.99") == 1299);
  CHECK(parseDollarInput("120.99") == 12099);
  CHECK(parseDollarInput("1200.99") == 120099);
  CHECK(parseDollarInput("12000.99") == 1200099);
  CHECK(parseDollarInput("120000.99") == 12000099);
  CHECK(parseDollarInput("01.99") == 199);
}

bool validateDollarInput(string input)
{
  regex dollarRegex(R"(^\$?\d+(\.\d{2})?$)");
  return regex_match(input, dollarRegex);
}


TEST_CASE("testing the factorial function") {
  CHECK(validateDollarInput("$12.99") == true);
  CHECK(validateDollarInput("12.99") == true);
  CHECK(validateDollarInput("$12") == true);
  CHECK(validateDollarInput("12") == true);
  CHECK(validateDollarInput("$120.99") == true);
  CHECK(validateDollarInput("1200.99") == true);
  CHECK(validateDollarInput("120000.99") == true);
  CHECK(validateDollarInput("$12000000.99") == true);
  CHECK(validateDollarInput("$12.9") == false);
  CHECK(validateDollarInput("#1.99") == false);
  CHECK(validateDollarInput("01.99") == true);
}

string getBalanceString(int balance)
{
  double b = balance/100.0;
  ostringstream oss;
  oss << fixed << setprecision(2) << b;
  return oss.str();
}

TEST_CASE("testing the factorial function") {
  CHECK(getBalanceString(1299) == "12.99");
  CHECK(getBalanceString(12999) == "129.99");
  CHECK(getBalanceString(129999) == "1299.99");
  CHECK(getBalanceString(12999999) == "129999.99");
}
