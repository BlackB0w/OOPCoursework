#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <grouplist.h>
#include "db.h"
#include "studentinterface.h"
#include "proffinterface.h"
#include "deaninterface.h"
#include "roleslists.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_Log_in_Button_clicked();

private:
    int checkUser(QString login, QString pass, int type);
    Ui::Widget *ui;
    DB db;
    DeanInterface *di;
    StudentInterface * si;
    ProffInterface * pi;
    RolesLists * rl;
};
#endif // WIDGET_H
