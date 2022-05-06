#ifndef MARK_H
#define MARK_H
#include <QString>

class Mark
{
    QString subject;
    int mark;
    QString type;
public:
    Mark(QString, int, QString);
    void SetMark(int);
    void SetSubject(QString);
    void SetType(QString);
    int GetMark();
    QString GetSubject();
    QString GetType();
};

#endif // MARK_H
