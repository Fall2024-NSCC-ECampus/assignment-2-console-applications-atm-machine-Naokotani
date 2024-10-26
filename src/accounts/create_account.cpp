#ifndef FILENAME_H
#define FILENAME_H
#include "../types.h"
#include "../users.h"
#include "../io.h"
#include <cstdlib>
#include <iostream>
#endif

/**
 * Creates and saves a new user to binary file.
 *
 * @return New User.
 */
User createAccount() {
 vector<User> users = getUsers();
  int newId = users.size() + 1;
  cout << "New id: " << newId << endl;
  User user = User {.id = newId, .password = getStringInput("Enter new password>")};
  users.push_back(user);
  saveUsers(users);
  return user;
}




