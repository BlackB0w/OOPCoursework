#ifndef DEANINTERFACE_H
#define DEANINTERFACE_H

#include <QWidget>
#include "grouplist.h"
#include <QTableWidgetItem>
#include "db.h"
#include "performancecalc.h"

namespace Ui {
class DeanInterface;
}

class DeanInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DeanInterface(QWidget *parent = nullptr);
    ~DeanInterface();

private slots:
    void on_GrWidget_cellClicked(int row, int column);

    void on_GrNumBox_currentIndexChanged(int index);

    void on_addGrButton_clicked();

    void on_delGrButton_clicked();

    void on_addStdButton_clicked();

    void on_delStdButton_clicked();

    void on_GrWidget_cellPressed(int row, int column);

    void on_stdWidget_cellPressed(int row, int column);

    void on_saveButton_clicked();

    void on_exitButton_clicked();

    void on_changePlanButton_clicked();

    void on_addPlanButton_clicked();

    void on_delPlanButton_clicked();

    void on_PlanBox_currentIndexChanged(const QString &arg1);

    void on_addSubButton_clicked();

    void on_delSubButton_clicked();

    void on_stPlanWidget_cellPressed(int row, int column);

private:
    DB db;
    QList<StPlan*> spl;
    GroupList* gl;
    Group* currentGroup;
    StPlan * currentPlan;
    int row,column, rowM,columnM, rowS, columnS;
    Ui::DeanInterface *ui;
    void setTable1(int r, int c);
    void setTable2(int r, int c, Student* std);
    void setTable3(int r, int c);
    void updPlanBoxes();
    void updGrInfo();
};

#endif // DEANINTERFACE_H
