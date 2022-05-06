#include "group.h"
QString Group::getPlan() const
{
    return plan;
}

void Group::setPlan(const QString &value)
{
    plan = value;
}

Group::Group(){
    this->number = 0;
    stdList = new StudentList();
}
Group::Group(int n, StudentList* sl){
    this->number = n;
    this->stdList = sl;
}
int Group::getNumber(){
 return this->number;
}
void Group::setNumber(int N){
    this->number = N;
}
StudentList* Group::getStdList(){
    return this->stdList;
}
void Group::setStdList(StudentList* sl){
    this->stdList = sl;
}
