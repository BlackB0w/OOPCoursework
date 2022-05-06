#include "studentinterface.h"
#include "ui_studentinterface.h"

StudentInterface::StudentInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInterface)
{
    ui->setupUi(this);
}
StudentInterface::StudentInterface(QWidget *parent, int gr, int number) :
    QWidget(parent),
    ui(new Ui::StudentInterface)
{
    ui->setupUi(this);
    gl = new GroupList();
    db.readBase(gl);
    std = gl->findGroupByNum(gr)->getStdList()->findStudentByCard(number);
    ui->StudentNameLabel->setText(std->getName());
    setInterface(std->getMList()->countMarks(),3);
    double av = PerformanceCalc::calcStudAverage(std);
    qDebug()<<av;
    ui->averageLabel->setText(QString::number(av));

}
StudentInterface::~StudentInterface()
{
    delete ui;
}

void StudentInterface::on_ExitButton_clicked()
{
    this->close();
}
void StudentInterface::setInterface( int r, int c){
    QStringList headers;
    headers << "Предмет"<< "Оценка" << "Тип";
    ui->MarksTableWidget->setColumnCount(c);
    ui->MarksTableWidget->setRowCount(r);
    ui->MarksTableWidget->setHorizontalHeaderLabels(headers);
    ui->MarksTableWidget->showGrid();
    for (int i = 0; i< r;i++)
    {//column 1 (subject)
        ui->MarksTableWidget->setItem(i,0, new QTableWidgetItem(std->getMList()->findMarkByPos(i)->GetSubject()));
        //column 2 (mark)
        ui->MarksTableWidget->setItem(i,1, new QTableWidgetItem(QString::number(std->getMList()->findMarkByPos(i)->GetMark())));
        //column 3 (type)
        ui->MarksTableWidget->setItem(i,2, new QTableWidgetItem(std->getMList()->findMarkByPos(i)->GetType()));
    }
    ui->MarksTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MarksTableWidget->resizeColumnsToContents();
}
