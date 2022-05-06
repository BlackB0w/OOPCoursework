#include "markslist.h"

MarksList::MarksList(){}

MarksList::MarksList(QList<Mark*>ml){
    this->marksList = ml;
}
void MarksList::setMarksList(QList<Mark*> list){
    this->marksList = list;
}
QList<Mark*> MarksList::getMarksList(){
    return this->marksList;
}
Mark* MarksList::findMarkBySubject(QString sub){
    auto it = marksList.begin();
    while (it != marksList.end()&& (*it)->GetSubject() != sub)
        it++;
    if (it != marksList.end()&&(*it)->GetSubject() == sub)
        return (*it);
    else return NULL;
}
Mark* MarksList::findMarkByPos(int c){
    if(marksList.size() >= c){
    auto it = marksList.begin();
     for (int i=0; i<c; i++)
         it++;
     return (*it);
    }else return NULL;
}
int MarksList::countMarks(){
    return marksList.size();
}
bool MarksList::addMark(Mark* m){
        marksList.push_back(m);
        return true;
}
bool MarksList::delMark(QString m){
    bool flag = false;

        auto it = marksList.begin();
        while ((*it)->GetSubject() != m)
            it++;
        marksList.erase(it);
        flag = true;
        return flag;
}
bool MarksList::delMark(int pos){
    auto it = marksList.begin();
    for (int i = 0; i<pos; i++)
        it++;
    marksList.erase(it);
    return true;
}
