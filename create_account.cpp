#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "users.h"
#include "io.h"
#include <cstdlib>
#endif

User createUser();

User createAccount() {
  vector<User> users = getUsers();
  User user = createUser();
  users.push_back(user);
  saveUsers(users);
  return user;
}

User createUser() {
  Credentials credentials = getCredentials();
  return User {.id = credentials.id, .password = credentials.password};
}



