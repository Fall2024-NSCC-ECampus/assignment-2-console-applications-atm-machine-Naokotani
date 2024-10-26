#include <string>
#include <vector>

using namespace std;

typedef struct User {
  int id = 0;
  string password = "";
  int balance = 0;
}User;

typedef struct Credentials {
  int id;
  string password;
}Credentials;
