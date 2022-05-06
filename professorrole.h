#ifndef PROFESSORROLE_H
#define PROFESSORROLE_H

#include "user.h"
#include <QList>
class ProfessorRole : public User
{
    QList<QString> subject;
public:
    ProfessorRole(QString l,QString p ,QList<QString>  s);
    QList<QString> getSubject() const;
    QString getLogin() const;
    QString getPass() const;
};

#endif // PROFESSORROLE_H
