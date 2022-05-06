#ifndef USER_H
#define USER_H
#include <QString>

class User
{
    QString login;
    QString password;
protected:
    QString getPassword() const;
    QString getLogin() const;
    User(QString,QString);
};

#endif // USER_H
