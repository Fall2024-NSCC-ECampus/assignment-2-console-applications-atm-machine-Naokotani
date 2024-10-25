#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#endif

float deposit(User user) {
  user.balance += getFloatInput();
  return user.balance;
}

float withdraw(User user) {
  float input = getFloatInput();
  if (user.balance > input) {
    user.balance -= input;
  } else {
    throw("Insuffcient funds");
  }
  return user.balance;
}
