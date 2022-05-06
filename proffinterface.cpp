#include "proffinterface.h"
#include "ui_proffinterface.h"

ProffInterface::ProffInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProffInterface)
{
    ui->setupUi(this);
}

ProffInterface::ProffInterface(QWidget *parent, QList <QString> subl) :
    QWidget(parent),
    ui(new Ui::ProffInterface)
{
    ui->setupUi(this);
    this->subl= subl;
    currentSub = this->subl[0];
    ui->sub->setText(currentSub);
    row = 0;
    column = 0;
    gl = new GroupList();
    db.readBase(gl);
    setGrBox();
    currentGroup = gl->findGroupByNum((ui->grBox->currentText()).toInt());
    setInterface(currentGroup->getStdList()->countStudents(),3);


}

ProffInterface::~ProffInterface()
{
    delete ui;
}

void ProffInterface::setGrBox(){
    int j = 0;
    for (int i = 0;i< gl->countGroups();i++ )
    {
        if(hasMarks(gl->findGroupByPos(i)))
        {
            QString gr = QString::number(gl->findGroupByPos(i)->getNumber());
            ui->grBox->insertItem(j,gr);
            j++;
        }
    }
}
bool ProffInterface::hasMarks(Group*gr)
{
    bool flag = false;
    for (int i = 0;i<gr->getStdList()->countStudents() ;i++ ) {
        if(gr->getStdList()->findStudentByPos(i)->getMList()->countMarks() != 0)
            if(gr->getStdList()->findStudentByPos(i)->getMList()->findMarkBySubject(currentSub))
                flag = true;
    }
    return flag;
}

void ProffInterface::setInterface(int r, int c){
    QStringList headers;

    headers << "Студент"<< "Оценка" << "Тип";
    ui->averageLabel->setText(QString::number(PerformanceCalc::calcGrSubAverage(currentGroup,currentSub)));
    ui->GrMarksWidget->setHorizontalHeaderLabels(headers);
    ui->GrMarksWidget->showGrid();
    ui->GrMarksWidget->setColumnCount(c);
    ui->GrMarksWidget->setRowCount(r);

    for (int i = 0; i< r;i++)
    {
        ui->GrMarksWidget->setItem(i,0, new QTableWidgetItem(currentGroup->getStdList()->findStudentByPos(i)->getName()));
        ui->GrMarksWidget->item(i,0)->setFlags(0);

        ui->GrMarksWidget->setItem(i,1, new QTableWidgetItem(QString::number(currentGroup->
                                                                             getStdList()->findStudentByPos(i)->
                                                                             getMList()->findMarkBySubject(currentSub)
                                                                             ->GetMark())));
        ui->GrMarksWidget->setItem(i,2, new QTableWidgetItem(currentGroup->
                                                             getStdList()->findStudentByPos(i)->
                                                             getMList()->findMarkBySubject(currentSub)
                                                             ->GetType()));
    }
    ui->GrMarksWidget->resizeColumnsToContents();
}
void ProffInterface::on_ExitButton_clicked()
{
    this->close();
}


void ProffInterface::on_GrMarksWidget_itemChanged(QTableWidgetItem *item)
{
    if(column == 1){
        Group *currentGroup = gl->findGroupByNum((ui->grBox->currentText()).toInt());
        currentGroup->getStdList()->findStudentByPos(row)->getMList()->findMarkBySubject(currentSub)
                ->SetMark(item->text().toInt());
    }
    row = 0;
    column = 0;
    ui->averageLabel->setText(QString::number(PerformanceCalc::calcGrSubAverage(currentGroup,currentSub)));
}

void ProffInterface::on_GrMarksWidget_cellPressed(int row, int column)
{
    this->row = row;
    this->column = column;
}

void ProffInterface::on_saveButton_clicked()
{
    db.saveBase(gl);
}

void ProffInterface::on_grBox_currentIndexChanged(int index)
{
    currentGroup = gl->findGroupByNum((ui->grBox->currentText()).toInt());
    setInterface(currentGroup->getStdList()->countStudents(),3);
}
