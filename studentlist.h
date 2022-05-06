#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "student.h"

class StudentList
{
    QList <Student*> StdList;
public:
    void setStdList(QList <Student*>);
    QList <Student*> getStdList();
    Student* findStudentByPos(int);
    Student* findStudentByCard(int);
    int countStudents();
    bool addStudent(Student*);
    bool delStudent(int);
};

#endif // STUDENTLIST_H
