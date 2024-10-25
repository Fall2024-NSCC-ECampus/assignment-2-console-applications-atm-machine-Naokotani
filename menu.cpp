#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "accounts.h"
#include "actions.h"
#endif

#include <iostream>

User getUser(User user);

User introMenu() {
  printIntroMenu();
  User user;
  while (!user.id)
  {
    user = getUser(user);
  }
  return user;
}

User getUser(User user) {
  switch (getCharInput()) {
  case 'l':
    return login();
  case 'c':
    return createAccount();
  case 'q':
    return User {.id = -1};
  default:
    return user;
  }
}


int mainMenu(User user) {
  printMain();
  switch (getCharInput())
  {
  case 'd':
    try
    {
      deposit(user);
    }
    catch (exception& e)
    {
      cout << e.what();
    }
    return 1;
  case 'w':
    try
    {
      withdraw(user);
    }
    catch(exception& e)
    {
      cerr << e.what();
    }
    return 1;
  case 'q':
    return -1;
  default:
    return 0;
  }
}






