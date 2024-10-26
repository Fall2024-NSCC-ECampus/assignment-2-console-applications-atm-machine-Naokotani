#include <string>

using namespace std;

const string default_prompt = ">";

string getStringInput(string prompt = default_prompt);
int getIntInput(string prompt = default_prompt);
char getCharInput(string prompt = default_prompt);
float getFloatInput(string prompt = default_prompt);
int getDollarInput(string prompt = default_prompt);
int parseDolloarInput(string input);
string getBalanceString(int balance);
void printMessage(string message);
void printMain();
void printIntroMenu();
void printBalance(int balance, string message = "Current Balance: $");
