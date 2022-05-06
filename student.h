#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "markslist.h"
class Student
{
    QString name;
    MarksList* mList;
    int stdCard;

public:
    Student();
    Student(QString n, int sc, MarksList* ml);
    int getStdCard();
    void setStdCard(int);
    QString getName();
    void setName(QString);
    MarksList* getMList();
    void setMList(MarksList*);
};

#endif // STUDENT_H
