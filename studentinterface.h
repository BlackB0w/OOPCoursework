#ifndef STUDENTINTERFACE_H
#define STUDENTINTERFACE_H

#include <QWidget>
#include "grouplist.h"
#include "db.h"
#include "performancecalc.h"
namespace Ui {
class StudentInterface;
}

class StudentInterface : public QWidget
{
    Q_OBJECT

public:
    explicit StudentInterface(QWidget *parent = nullptr);
    StudentInterface(QWidget *parent,int gr,int num);
    ~StudentInterface();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::StudentInterface *ui;
    DB db;
    GroupList * gl;
    Student* std;
    int group;
    int StNum;
    void setInterface( int r, int c);
};

#endif // STUDENTINTERFACE_H
