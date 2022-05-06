#ifndef ROLESLISTS_H
#define ROLESLISTS_H
#include "studentrole.h"
#include "professorrole.h"
#include "deanrole.h"
#include <QList>

class RolesLists
{
    QList <StudentRole*> studs;
    QList <ProfessorRole*> profs;
    QList <DeanRole*> deans;
public:
    RolesLists();

    QList<StudentRole *> getStuds() const;
    void setStuds(const QList<StudentRole *> value);
    QList<ProfessorRole *> getProfs() const;
    void setProfs(const QList<ProfessorRole *> value);
    QList<DeanRole *> getDeans() const;
    void setDeans(const QList<DeanRole *> value);
};

#endif // ROLESLISTS_H
