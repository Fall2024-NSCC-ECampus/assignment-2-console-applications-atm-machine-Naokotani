#ifndef FILENAME_H
#define FILENAME_H
#include <iostream>
#include <string>
#include <regex>
#include "../exceptions.h"
#endif

using namespace std;

bool validateDollarInput(string input);

/**
 * Get a string from user command line input.
 *
 * @return string from user input.
 */
string getStringInput(string prompt)
{
  string s;
  cout << prompt;
  cin >> s;
  return s;
}

/**
 * Get a string from user command line input.
 *
 * @return string from user input.
 */
string getCharArrInput(string prompt, int length)
{
  char s[length];
  cout << prompt;
  cin >> s;
  return s;
}

/**
 * Get an integer from command line input.
 *
 * @return integer from user input.
 * @throw unable to parse an integer from user input.
 */
int getIntInput(string prompt)
{
  string s = getStringInput(prompt);
  try
  {
    return stoi(s);
  }
  catch (invalid_argument& ia)
  {
    throw("couldn't parse integer from input: " + s);
  }
}

/**
 * Get an integer from command line input.
 *
 * @return float from user input.
 * @throw unable to parse an integer from user input.
 */
int getFloatInput(string prompt)
{
  string s = getStringInput(prompt);
  try
  {
    return stof(s);
  }
  catch (invalid_argument& ia)
  {
    throw("couldn't parse float from input: " + s);
  }
}

/**
 * Checks a dollar input for $ and . characters and removes them
 *
 * @return appropriate dollar amount.
 */
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

/**
 * Get an integer from command line input.
 *
 * @return Dollar amount ready for binary file.
 * @throws Invalid dollar input.
 */
int getDollarInput(string prompt)
{
  string s = getStringInput(prompt);
  if (!validateDollarInput(s)) {
    throw(InvalidDollarInput(s));
  }
  return parseDollarInput(s);
}

bool validateDollarInput(string input)
{
  regex dollarRegex(R"(^\$?\d+(\.\d{2})?$)");
  return regex_match(input, dollarRegex);
}

/**
 * Get an character from command line input.
 *
 * @return character from user input.
 * @throw string is longer than one character.
 */
char getCharInput(string prompt = ">")
{
  string s = getStringInput(prompt);
  if (s.length() > 1)
  {
    throw("Did not enter a single character: " + s);
  }
  return s.at(0);
}
