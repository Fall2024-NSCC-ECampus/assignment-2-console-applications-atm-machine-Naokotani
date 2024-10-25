#include <string>
#include <vector>

using namespace std;

typedef struct User {
  int id = 0;
  string password = "";
  float balance = 0.0;
}User;

typedef struct Credentials {
  int id;
  string password;
}Credentials;
