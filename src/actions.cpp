#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "exceptions.h"
#endif

/**
 * Deposit money in an account.
 *
 * @return User with updated balance.
 */
User deposit(User user) {
  user.balance += getFloatInput("Deposit > ");
  printFloat("New balance: ", user.balance);
  return user;
}

/**
 * Withdraw money from an account.
 *
 * @return User with updated balance.
 * @throws Insufficient funds to widthdraw.
 */
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

/**
 * prints the current balance.
 */
void requestBalance(User user)
{
  printFloat("Current Balance: ", user.balance);
}
