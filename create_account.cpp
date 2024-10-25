#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "users.h"
#include "io.h"
#include <cstdlib>
#endif

#include <fstream>
#include <iostream>

User createUser();
void saveUsers(vector<User> users);

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

void saveUsers(vector<User> users)
{

  string file = "accounts.bin";
  size_t size = users.size();

  User *usersArr = initializeUserArr(size);
  usersArr = &users[0];

  fstream fout(file, ios::out | ios::binary);

  if (fout)
  {
    fout.write(reinterpret_cast<char*>(&size), 1);
    fout.write(reinterpret_cast<char*>(usersArr), size);
  }
  else {
    free(usersArr);
    throw("could not open file" + file);
  }
  free(usersArr);

  fout.close();
}


