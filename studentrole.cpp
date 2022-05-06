#include "studentrole.h"

int StudentRole::getStNum() const
{
    return stNum;
}

int StudentRole::getGroup() const
{
    return group;
}

QString StudentRole::getLogin() const
{
    return User::getLogin();
}

QString StudentRole::getPass() const
{
    return User::getPassword();
}

StudentRole::StudentRole(QString l, QString p, int g, int n):User(l,p)
{
    this->group = g;
    this->stNum = n;
}
