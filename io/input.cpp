#include <iostream>

using namespace std;

/**
 * Get a string from user command line input.
 *
 * @return string from user input.
 */
string getStringInput(string prompt) {
  string s;
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
int getIntInput(string prompt) {
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
 * Get an character from command line input.
 *
 * @return character from user input.
 * @throw string is longer than one character.
 */
char getCharInput(string prompt = ">") {
  string s = getStringInput(prompt);
  if (s.length() > 1) {
    throw("Did not enter a single character: " + s);
  } else {
    return s.at(0);
  }
}
