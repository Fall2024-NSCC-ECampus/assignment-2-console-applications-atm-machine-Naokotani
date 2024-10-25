#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "ui.h"
#endif

int start();

int main()
{
  printMessage("Hi! Welcome to Mr. Zamar’s ATM Machine!");
  start();
  return 0;
}

int start() {
  while (mainMenu(introMenu()));
  return 0;
}

