#ifndef MARKSLIST_H
#define MARKSLIST_H
#include <QList>
#include "mark.h"
class MarksList
{
    QList <Mark*> marksList;
public:
    MarksList();
    MarksList(QList<Mark*> ml);
    void setMarksList(QList<Mark*>);
    QList<Mark*> getMarksList();
    Mark* findMarkBySubject(QString);
    Mark* findMarkByPos(int);
    int countMarks();
    bool addMark(Mark*);
    bool delMark(int);
    bool delMark(QString);
};

#endif // MARKSLIST_H
