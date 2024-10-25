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
  fstream fin("accounts.bin", ios::in | ios::binary);

  size_t size;
  User *usersPtr = initalizeUserPtr(size);

  if (fin)
  {
    fin.read(reinterpret_cast<char*>(&size), 1);
    fin.read(reinterpret_cast<char*>(usersPtr), size);
  }

  fin.close();
  vector<User> users = vector<User>(usersPtr, usersPtr+size);
  free(usersPtr);

  return users;
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
