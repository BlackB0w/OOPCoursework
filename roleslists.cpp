#include "roleslists.h"

QList<StudentRole *> RolesLists::getStuds() const
{
    return studs;
}

void RolesLists::setStuds(const QList<StudentRole *> value)
{
    studs = value;
}

QList<ProfessorRole *> RolesLists::getProfs() const
{
    return profs;
}

void RolesLists::setProfs(const QList<ProfessorRole *> value)
{
    profs = value;
}

QList<DeanRole *> RolesLists::getDeans() const
{
    return deans;
}

void RolesLists::setDeans(const QList<DeanRole *> value)
{
    deans = value;
}

RolesLists::RolesLists()
{

}
