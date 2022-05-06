#ifndef PROFFINTERFACE_H
#define PROFFINTERFACE_H

#include <QWidget>
#include "grouplist.h"
#include <QTableWidgetItem>
#include "db.h"
#include "performancecalc.h"
namespace Ui {
class ProffInterface;
}

class ProffInterface : public QWidget
{
    Q_OBJECT

public:
    explicit ProffInterface(QWidget *parent = nullptr);
    ProffInterface(QWidget *parent, QList <QString> subl);
    ~ProffInterface();

private slots:
    void on_ExitButton_clicked();

    void on_GrMarksWidget_itemChanged(QTableWidgetItem *item);

    void on_GrMarksWidget_cellPressed(int row, int column);

    void on_saveButton_clicked();

    void on_grBox_currentIndexChanged(int index);

private:
    void setInterface( int r, int c);
    void setGrBox();
    bool hasMarks(Student*);
    bool hasMarks(Group*);
    DB db;
    GroupList* gl;
    Group * currentGroup;
    QList <QString> subl;
    QString currentSub;
    int row,column;
    Ui::ProffInterface *ui;
};

#endif // PROFFINTERFACE_H
