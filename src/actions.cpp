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
  user.balance += getDollarInput("Deposit > ");
  printBalance(user.balance, "New Balance: $");
  return user;
}

/**
 * Withdraw money from an account.
 *
 * @return User with updated balance.
 * @throws Insufficient funds to widthdraw.
 */
User withdraw(User user) {
  printBalance(user.balance);
  int input = getDollarInput("Withdraw >");

  if (user.balance > input) {
    user.balance -= input;
  } else {
    throw(InsufficientFunds(getBalanceString(user.balance)));
  }

  printBalance(user.balance, "New Balance: $");
  return user;
}

/**
 * prints the current balance.
 */
void requestBalance(User user)
{
  printBalance(user.balance);
}
