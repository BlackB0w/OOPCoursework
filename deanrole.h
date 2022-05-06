#ifndef DEANROLE_H
#define DEANROLE_H

#include "user.h"

class DeanRole : public User
{
public:
    DeanRole(QString l,QString p);
    QString getLogin() const;
    QString getPass() const;
};

#endif // DEANROLE_H
