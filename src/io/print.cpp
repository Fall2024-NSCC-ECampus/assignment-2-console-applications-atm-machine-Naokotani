#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

/**
 * prints a message with a new line.
 * @param string that is the message to display.
 */
void printMessage(string message) {
  cout << message << endl;
}

/**
 * Converts an int that represents cents into a
 * dollar value.
 *
 * @return A dollar/cents formatter string (ie "10.50").
 * @param balance stored as cents.
 */
string getBalanceString(int balance)
{
  double b = balance/100.0;
  ostringstream oss;
  oss << fixed << setprecision(2) << b;
  return oss.str();
}

/**
 * Prints balanced
 *
 * @param balance stored as cents.
 * @param message to be prepended to balance.
 */
void printBalance(int balance, string message)
{
  string balanceString = getBalanceString(balance);
  cout << message << balanceString << endl;
}

/**
 * Prints intro menu.
 */
void printIntroMenu() {
  string message;
  message.append("Please select an option from the menu below\n");
  message.append("l -> Login\n");
  message.append("c -> Create New Account\n");
  message.append("q -> Quit\n");
  printMessage(message);
}

/**
 * Prints Main menu.
 */
void printMain() {
  string message;
  message.append("d -> Deposit Money\n");
  message.append("w -> Withdraw Money\n");
  message.append("r -> Request Balance\n");
  message.append("q -> Quit\n");
  printMessage(message);
}
