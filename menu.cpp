#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "accounts.h"
#include "actions.h"
#include "exceptions.h"
#include "users.h"
#endif

#include <iostream>

User getUser(User user);

User introMenu() {
  printIntroMenu();
  User user;
  while (!user.id)
  {
    try {
      user = getUser(user);
    } catch (BadCredentials &e) {
      cerr << e.what();
      printIntroMenu();
    }
  }
  return user;
}

User getUser(User user) {
  switch (getCharInput()) {
  case 'l':
    try {
      return login();
    } catch (BadCredentials& e) {
      throw;
    }
  case 'c':
    return createAccount();
  case 'q':
    return User {.id = -1};
  default:
    return user;
  }
}


User mainMenu(User user) {
  printMain();
  switch (getCharInput())
  {
  case 'd':
    try
    {
      user = deposit(user);
    }
    catch (exception& e)
    {
      cout << e.what();
    }
    break;
  case 'w':
    try
    {
      user = withdraw(user);
    }
    catch(exception& e)
    {
      cerr << e.what();
    }
    break;
  case 'r':
    requestBalance(user);
    break;
  case 'q':
    save(user);
    user.id = -1;
  }

  return user;
}






