#include "widget.h"
#include "ui_widget.h"
#include "studentrole.h"
#include "professorrole.h"
#include "deanrole.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->IncorrectDataLabel->hide();
    rl = new RolesLists();
    db.readUsers(rl);

}

Widget::~Widget()
{
    delete ui;
}

int Widget::checkUser(QString login, QString pass, int type){
    qDebug() << login << pass << type;
    bool flag = false;
    int i = 0;
    if (type == 0){
        qDebug() << rl->getStuds().size() ;
        for (; i < rl->getStuds().size() ;i++) {
            qDebug() <<rl->getStuds()[i]->getLogin() <<rl->getStuds()[i]->getPass();
            if(rl->getStuds()[i]->getLogin() == login && rl->getStuds()[i]->getPass() == pass)
            {
                flag = true;
                break;
            }
        }
        if (!flag){
            i = -1;
        }
    }
    else if (type == 1){
        for (; i < rl->getProfs().size() ;i++) {
            if(rl->getProfs()[i]->getLogin() == login && rl->getProfs()[i]->getPass() == pass)
            {
                flag = true;
                break;
            }
        }
        if (!flag){
            i = -1;
        }
    }
    else if (type == 2){
        for (; i < rl->getDeans().size() ;i++) {
            if(rl->getDeans()[i]->getLogin() == login && rl->getDeans()[i]->getPass() == pass)
            {
                flag = true;
                break;
            }
        }
        if (!flag){
            i = -1;
        }
    }
    return i;
}
void Widget::on_Log_in_Button_clicked()
{


    int userType = ui->UsertypeBox->currentIndex();
    QString login = ui->LoginLine->text();
    QString pass = ui->PassLine->text();
    int ind = checkUser(login,pass, userType);
    qDebug() << ind;
    if (userType == 0)
    {


        if(ind != -1)
        {
            si = new StudentInterface(nullptr,rl->getStuds()[ind]->getGroup(),rl->getStuds()[ind]->getStNum());
            si->show();
            if(!ui->IncorrectDataLabel->isHidden())
                ui->IncorrectDataLabel->hide();
            this->hide();
        }
        else
            ui->IncorrectDataLabel->show();
    }
    else if (userType == 1)
    {
        if(ind != -1)
        {
            pi = new ProffInterface(nullptr,rl->getProfs()[ind]->getSubject());
            pi->show();
            if(!ui->IncorrectDataLabel->isHidden())
                ui->IncorrectDataLabel->hide();
            this->hide();
        }
        else
            ui->IncorrectDataLabel->show();
    }
    else if (userType == 2)
    {
        if(ind != -1)
        {
            di = new DeanInterface();
            di->show();
            if(!ui->IncorrectDataLabel->isHidden())
                ui->IncorrectDataLabel->hide();
            this->hide();
        }
        else
            ui->IncorrectDataLabel->show();
    }

}
