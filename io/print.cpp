#include <iostream>
#include <string>

using namespace std;

void printMessage(string message) {
  cout << message << endl;
}

void printIntroMenu() {
  string message;
  message.append("Please select an option from the menu below\n");
  message.append("l -> Login\n");
  message.append("c -> Create New Account\n");
  message.append("q -> Quit\n");
  printMessage(message);
}

void printMain() {
  string message;
  message.append("d -> Deposit Money\n");
  message.append("w -> Withdraw Money\n");
  message.append("r -> Request Balance\n");
  message.append("q -> Quit\n");
  printMessage(message);
}

void printFloat(string message, float balance) {
  cout << message << balance << endl;
}


