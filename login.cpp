#ifndef FILENAME_H
#define FILENAME_H
#include "types.h"
#include "io.h"
#include "users.h"
#endif

Credentials getCredentials();
User findUser(Credentials credentials, vector<User> users);
vector<User> getUsers();

User login()
{
  printMessage("Enter your credentails\n");
  try
  {
    return findUser(getCredentials(), getUsers());
  }
  catch (exception& e)
  {
    throw;
  }
};

User findUser(Credentials credentails, vector<User> users)
{

  for(User user: users)
  {
    if (user.id == credentails.id)
    {
      if (user.password == credentails.password)
      {
        return user;
      }
      else
      {
        throw("Invalid Password");
      }
    }
  }
  throw("Id not found");
}


