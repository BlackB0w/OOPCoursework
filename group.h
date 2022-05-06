#ifndef GROUP_H
#define GROUP_H
#include "studentlist.h"
class Group
{
    int number;
    StudentList* stdList;
    QString plan;
public:
    Group();
    Group(int n, StudentList* sl);
    int getNumber();
    void setNumber(int);
    StudentList* getStdList();
    void setStdList(StudentList*);
    QString getPlan() const;
    void setPlan(const QString &value);
};

#endif // GROUP_H
