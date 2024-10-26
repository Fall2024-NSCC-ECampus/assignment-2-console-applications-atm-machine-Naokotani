#ifndef FILENAME_H
#define FILENAME_H
#include "../src/types.h"
#include "../src/accounts.h"
#include "../src/users.h"
#include <iostream>
#endif

vector<User> getTestUsers()
{ 
  vector<User> users;
  users.push_back({.id=1, .password="pass", .balance=12.99});
  users.push_back({.id=2, .password="password!", .balance=12.99});
  users.push_back({.id=3, .password="Passtoed!@#", .balance=12.99});
  users.push_back({.id=4, .password="PPPP22222asdf", .balance=12.99});
  users.push_back({.id=5, .password="new", .balance=12.99});
  users.push_back({.id=6, .password="new", .balance=12.99});
  return users;
}

void printUsers(vector<User> users)
{
  for (User user : users) {
    cout << user.id << endl;
    cout << user.password << endl;
    cout << user.balance << endl;
    cout << endl;
  }
}

int main()
{
  vector<User> users = getTestUsers();
  printUsers(users);
  saveUsers(users);
  vector<User> loadedUsers = getUsers();
  printUsers(loadedUsers);
}
