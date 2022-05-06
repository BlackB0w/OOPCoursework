#include "deanrole.h"

DeanRole::DeanRole(QString l,QString p): User(l,p)
{}

QString DeanRole::getLogin() const
{
    return User::getLogin();
}

QString DeanRole::getPass() const
{
    return User::getPassword();
}
