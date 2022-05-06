#include "mark.h"

Mark::Mark(QString sub, int mark, QString type){
    this->mark = mark;
    this->subject = sub;
    this->type = type;
}
void Mark::SetMark(int mark){
    this->mark = mark;
}
void Mark::SetSubject(QString sub){
    this->subject = sub;
}
int Mark::GetMark(){
    return this->mark;
}
QString Mark::GetSubject(){
    return this->subject;
}

void Mark::SetType(QString t){
    this->type = t;
}

QString Mark::GetType(){
    return type;
}
