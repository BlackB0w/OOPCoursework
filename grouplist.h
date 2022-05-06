#ifndef GROUPLIST_H
#define GROUPLIST_H
#include "group.h"
#include <QList>

class GroupList
{
    QList <Group*> gList;
public:
      void setGList(QList <Group*>);
      QList <Group*> getGList();
      Group* findGroupByNum(int);
      Group* findGroupByPos(int);
      int countGroups();
      bool addGroup(Group*);
      bool delGroup(int);
};

#endif // GROUPLIST_H
