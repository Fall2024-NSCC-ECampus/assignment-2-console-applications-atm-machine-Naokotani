#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "menu.h"
#include <exception>
#include <iostream>
#endif

int start();

int main()
{
  printMessage("Hi! Welcome to Mr. Zamar’s ATM Machine!");
  start();
  return 0;
}

int start() {
  User user = introMenu();
  while (user.id > 0)
  {
    try {
      user = mainMenu(user);
    } catch (exception& e) {
      cerr << e.what();
    }
  }
  return 0;
}

