#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#endif

std::vector<User> getUsers();
Credentials getCredentials();
User *initalizeUserPtr(size_t size);
void saveUsers(vector<User> users);
