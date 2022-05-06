#include "user.h"

QString User::getLogin() const
{
    return login;
}

QString User::getPassword() const
{
    return password;
}

User::User(QString l, QString p)
{
    this->login = l;
    this->password = p;
}
