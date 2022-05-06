#include "studentlist.h"

void StudentList::setStdList(QList <Student*> l){
    this->StdList = l;
}
QList <Student*> StudentList::getStdList(){
    return this->StdList;
}
Student* StudentList::findStudentByCard(int c){
    auto it = StdList.begin();
    while ((*it)->getStdCard() != c)
        it++;
    return (*it);
}
Student* StudentList::findStudentByPos(int c){
    if(StdList.size() >= c){
        auto it = StdList.begin();
        for (int i=0; i<c; i++)
            it++;
        return (*it);
    }else return NULL;
}
int StudentList::countStudents(){
    return StdList.size();
}
bool StudentList::addStudent(Student* s){

    StdList.push_back(s);
    return true;
}
bool StudentList::delStudent(int s){
    bool flag = false;
    auto it = StdList.begin();
    while ((*it)->getStdCard() != s)
        it++;
    StdList.erase(it);
    flag = true;
    return flag;
}
