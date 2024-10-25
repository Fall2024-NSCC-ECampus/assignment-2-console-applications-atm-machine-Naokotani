#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#endif


User *initalizeUserPtr(size_t size);

vector<User> getUsers()
{
  ifstream fin("accounts.bin", ios::in | ios::binary);
  size_t size = 0;
  User *usersPtr;

  if (fin)
  {
    fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    usersPtr = initalizeUserPtr(size);
    fin.read(reinterpret_cast<char*>(usersPtr), sizeof(User) * size);
  }

  fin.close();
  vector<User> users = vector<User>(usersPtr, usersPtr+size);
  free(usersPtr);
  return users;
}

void saveUsers(vector<User> users)
{
  printMessage("Saving Users...");
  string file = "accounts.bin";
  size_t size = users.size();

  User *usersArr;
  usersArr = &users[0];

  ofstream fout(file, ios::out | ios::binary);

  if (fout)
  {
    fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));
    fout.write(reinterpret_cast<char*>(usersArr), sizeof(User) * size);
  }
  else {
    printMessage("error opening file.");
    free(usersArr);
    throw("could not open file" + file);
  }
}

Credentials getCredentials()
{
  try
  {
    return Credentials {.id = getIntInput("ID> "), .password = getStringInput("Password> ")};
  }
  catch (...) {
    throw;
  }
}


User *initalizeUserPtr(size_t size)
{
  return (User*) calloc(size, sizeof(User));
}
