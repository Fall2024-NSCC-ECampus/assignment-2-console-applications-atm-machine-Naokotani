#include <string>

using namespace std;

const string default_prompt = ">";

string getStringInput(string prompt = default_prompt);
int getIntInput(string prompt = default_prompt);
char getCharInput(string prompt = default_prompt);
float getFloatInput(string prompt = default_prompt);
void printMessage(string message);
void printMain();
void printIntroMenu();
void printFloat(string message, float num);
