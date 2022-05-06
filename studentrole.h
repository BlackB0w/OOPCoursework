#ifndef STUDENTROLE_H
#define STUDENTROLE_H

#include "user.h"

class StudentRole : public User
{
    int stNum;
    int group;
public:
    StudentRole(QString l, QString p, int g,int n);

    int getStNum() const;
    int getGroup() const;
    QString getLogin() const;
    QString getPass() const;
};

#endif // STUDENTROLE_H
