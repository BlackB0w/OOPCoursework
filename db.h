#ifndef DB_H
#define DB_H
#include "grouplist.h"
#include "roleslists.h"
#include "stplan.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class DB
{
    QSqlDatabase db;
public:
    DB();
    bool openConnection();
    void closeConnection();
    void readBase(GroupList*);
    void saveBase(GroupList*);
    void readUsers(RolesLists*);
    QList <StPlan*> readPlans();
    void savePlans(QList <StPlan*>);
};

#endif // DB_H
