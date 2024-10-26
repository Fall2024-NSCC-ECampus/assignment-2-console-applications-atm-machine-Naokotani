#ifndef FILENAME_H
#define FILENAME_H
#include "../types.h"
#include "../io.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#endif

typedef struct UserArr {
  int id;
  char password[20];
  int balance;
}UserArr;

UserArr *initalizeUserPtr(size_t size);
UserArr *userVecToPtr(vector<User> users, UserArr *userArr);


/**
 * Reads accounts.bin to load vector of Users
 *
 * @return Vector of users from file.
 * @throws file fails to open.
 */
vector<User> getUsers()
{
  ifstream fin;
  fin.open("accounts.bin", ios::in | ios::binary);
  size_t size = 0;
  UserArr *usersPtr;

  if (!fin.fail())
  {
    fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    if (size > 0)
    {
      usersPtr = initalizeUserPtr(size);
      fin.read(reinterpret_cast<char*>(usersPtr),
               sizeof(UserArr) * size);
    }
  }
  else
  {
    cerr << "File failed to open file\n";
    throw;
  }

  fin.close();
  vector<User> users;
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      users.push_back(User
                      {
                        usersPtr[i].id, usersPtr[i].password,
                        usersPtr[i].balance
                      });
    }
  }
  return users;
}

/**
 * Saves users vector to binary file.
 *
 * @throws file fails to open.
 */
void saveUsers(vector<User> users)
{
  string file = "accounts.bin";
  size_t size = users.size();

  UserArr *userArr;
  userArr = initalizeUserPtr(users.size());
  userArr = userVecToPtr(users, userArr);

  ofstream fout(file, ios::out | ios::binary);

  if (fout)
  {
    fout.write(reinterpret_cast<char*>(&size),
               sizeof(size_t));
    fout.write(reinterpret_cast<char*>(userArr),
               sizeof(UserArr) * size);
  }
  else
  {
    printMessage("error opening file.");
    free(userArr);
    throw("could not open file" + file);
  }
}

/**
 * Saves single user accounts.bin file.
 *
 * @throws file fails to open.
 */
void save(User user)
{
  fstream fin("accounts.bin", ios::in | ios::out| ios::binary);
  size_t size = 0;
  UserArr *usersPtr;
  usersPtr = initalizeUserPtr(1);

  if (fin)
  {
    fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));
  }

  if (size > 0 && fin)
  {
    for (size_t i = 0; i < size; i++)
    {
      fin.read(reinterpret_cast<char *>(usersPtr),
               sizeof(UserArr));
      if (usersPtr->id == user.id) {
        usersPtr->balance = user.balance;
        fin.seekp(-sizeof(UserArr), ios::cur);
        break;
      }
    }
    fin.write(reinterpret_cast<char*>(usersPtr),
              sizeof(UserArr));
  }
  
  fin.close();
}

/**
 * Get credentials from user input.
 *
 * @return new Credentails
 * @throws bad credentials
 */
Credentials getCredentials()
{
  try
  {
    return Credentials
    {
      getIntInput("ID>"),
      getStringInput("Password>"),
    };
  }
  catch (exception& e)
  {
    throw;
  }
}


/**
 * intailizes a UserArray pointer
 *
 * @parameters size of pointer.
 * @return allocated UserArr pointer.
 */
UserArr *initalizeUserPtr(size_t size)
{
  return (UserArr*) calloc(size, sizeof(UserArr));
}

/**
 * intailizes a UserArray pointer
 *
 * @parameters Vector of uers to be copied, UserArr pointer to copy to.
 * @return UserArr.
 */
UserArr *userVecToPtr(vector<User> users, UserArr *userArr)
{
  for (size_t i = 0; i < users.size(); i++)
  {
    userArr[i].id = users[i].id;
    strcpy(userArr[i].password, users[i].password.c_str());
    userArr[i].balance = users[i].balance;
  }
  return userArr;
}
