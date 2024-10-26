#ifndef FILENAME_H
#define FILENAME_H
#include "../types.h"
#include "../io.h"
#include "../users.h"
#include "../exceptions.h"
#endif

User findUser(Credentials credentials, vector<User> users);

/**
 * Prompts for login credentials and finds corresponding User.
 *
 * @return Login User.
 * @throws Invalid credentials, missing password, id not found.
 */
User login()
{
  printMessage("Enter your credentails\n");
  try
  {
    return findUser(getCredentials(), getUsers());
  }
  catch (BadCredentials& e)
  {
    throw;
  }
};

/**
 * Loops through User vector to finder user based on credentials 
 *
 * @return Login User.
 * @throws Invalid credentials, missing password, id not found.
 */
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
        throw(BadCredentials("Invalid Password.\n"));
      }
    }
  }
  throw(BadCredentials("ID not found.\n"));
}



