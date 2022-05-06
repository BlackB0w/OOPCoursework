#include "professorrole.h"

QList<QString> ProfessorRole::getSubject() const
{
    return subject;
}

QString ProfessorRole::getLogin() const
{
    return User::getLogin();
}

QString ProfessorRole::getPass() const
{
    return User::getPassword();
}

ProfessorRole::ProfessorRole(QString l,QString p ,QList<QString> s): User(l,p)
{
    this->subject = s;
}
