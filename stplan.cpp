#include "stplan.h"

QString StPlan::getDir() const
{
    return dir;
}

void StPlan::setDir(const QString &value)
{
    dir = value;
}

MarksList *StPlan::getPlanML() const
{
    return planML;
}

void StPlan::setPlanML(MarksList *value)
{
    planML = value;
}

StPlan::StPlan()
{

}
StPlan::StPlan(QString d, MarksList* ml)
{
    this->dir = d;
    this->planML = ml;
}
