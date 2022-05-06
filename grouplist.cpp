#include "grouplist.h"

void GroupList::setGList(QList <Group*> gl){
    this->gList = gl;
}
QList <Group*> GroupList::getGList(){
    return this->gList;
}
Group* GroupList::findGroupByNum(int n){
    auto it = gList.begin();
    while ((*it)->getNumber() != n)
        it++;
    return (*it);
}
Group* GroupList::findGroupByPos(int c){
    if(gList.size() >= c){
        auto it = gList.begin();
        for (int i=0; i<c; i++)
            it++;
        return (*it);
    }else return NULL;
}
int GroupList::countGroups(){
    return gList.size();
}
bool GroupList::addGroup(Group* g){
    gList.push_back(g);
    return true;
}
bool GroupList::delGroup(int g){
    bool flag = false;
    auto it = gList.begin();
    while ((*it)->getNumber() != g)
        it++;
    gList.erase(it);
    flag = true;
    return flag;
}
