#include "student.h"

Student::Student(){
    this->stdCard = NULL;
}
Student::Student(QString n, int sc, MarksList* ml){
    this->name = n;
    this->stdCard = sc;
    this->mList = ml;
}
QString Student::getName(){
    return this->name;
}
void Student::setName(QString name){
    this->name = name;
}
MarksList* Student::getMList(){
    return this->mList;
}
void Student::setMList(MarksList* ml){
    this->mList = ml;
}
int  Student::getStdCard(){
    return this->stdCard;
}
void  Student::setStdCard(int sc){
    this->stdCard = sc;
}
