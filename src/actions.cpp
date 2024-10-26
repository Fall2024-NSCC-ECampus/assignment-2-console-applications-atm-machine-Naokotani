#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "exceptions.h"
#endif

User deposit(User user) {
  user.balance += getFloatInput("Deposit > ");
  printFloat("New balance: ", user.balance);
  return user;
}

User withdraw(User user) {
  printFloat("Current balance: ", user.balance);
  float input = getFloatInput("Withdraw >");
  if (user.balance > input) {
    user.balance -= input;
  } else {
    throw(InsufficientFunds("Insufficient Funds"));
  }
  printFloat("New balance: ", user.balance);
  return user;
}

void requestBalance(User user)
{
  printFloat("Current Balance: ", user.balance);
}
