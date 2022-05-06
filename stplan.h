#ifndef STPLAN_H
#define STPLAN_H
#include "markslist.h"

class StPlan
{
    QString dir;
    MarksList* planML;
public:
    StPlan();
    StPlan(QString d, MarksList* ml);
    QString getDir() const;
    void setDir(const QString &value);
    MarksList *getPlanML() const;
    void setPlanML(MarksList *value);
};

#endif // STPLAN_H
