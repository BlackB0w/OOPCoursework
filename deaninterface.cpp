#include "deaninterface.h"
#include "ui_deaninterface.h"

DeanInterface::DeanInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeanInterface)
{
    ui->setupUi(this);
    this->row = 0;
    this->column = 0;
    gl = new GroupList();
    db.readBase(gl);
    spl = db.readPlans();
    qDebug() << spl[0]->getDir() << "\n" << spl[0]->getPlanML()->countMarks();

    if(spl.size() != 0){
        updPlanBoxes();
        currentPlan = spl[0];
        if (currentPlan->getPlanML()->countMarks() != 0)
            setTable3(currentPlan->getPlanML()->countMarks(), 2);
    }

    for (int i = 0;i< gl->countGroups();i++ ) {
        ui->GrNumBox->insertItem(i,QString::number(gl->findGroupByPos(i)->getNumber()));
    }

    currentGroup = gl->findGroupByNum((ui->GrNumBox->currentText()).toInt());
    if (currentGroup->getStdList()->countStudents() != 0)
        setTable1(currentGroup->getStdList()->countStudents(),2);
    updGrInfo();
    ui->planLabel->setText(currentGroup->getPlan());
}

DeanInterface::~DeanInterface()
{
    delete ui;
}
void DeanInterface::setTable1(int r, int c)
{
    QStringList headers;
    headers << "Номер студбилета"<< "Имя";
    ui->GrWidget->showGrid();
    ui->GrWidget->setColumnCount(c);
    ui->GrWidget->setRowCount(r);
    ui->GrWidget->setHorizontalHeaderLabels(headers);
    for (int i = 0; i< r;i++)
    {//column 1 (stdCard)
        ui->GrWidget->setItem(i,0, new QTableWidgetItem(QString::number(currentGroup->getStdList()->findStudentByPos(i)->getStdCard())));
    }
    for (int i = 0; i< r;i++)
    {//column 2 (name)
        ui->GrWidget->setItem(i,1, new QTableWidgetItem(currentGroup->getStdList()->findStudentByPos(i)->getName()));
    }
    ui->GrWidget->resizeColumnsToContents();
}
void DeanInterface::setTable2(int r, int c, Student* std)
{
    QStringList headers;
    headers << "Предмет"<< "Оценка" << "Тип";
    ui->stdWidget->setColumnCount(c);
    ui->stdWidget->setRowCount(r);
    ui->stdWidget->setHorizontalHeaderLabels(headers);
    ui->stdWidget->showGrid();
    for (int i = 0; i< std->getMList()->countMarks();i++)
    {//column 1 (subject)
        ui->stdWidget->setItem(i,0, new QTableWidgetItem(std->getMList()->findMarkByPos(i)->GetSubject()));
    }
    for (int i = 0; i< std->getMList()->countMarks();i++)
    {//column 2 (mark)
        ui->stdWidget->setItem(i,1, new QTableWidgetItem(QString::number(std->getMList()->findMarkByPos(i)->GetMark())));
    }
    ui->stdWidget->resizeColumnsToContents();
    for (int i = 0; i< std->getMList()->countMarks();i++)
    {//column 3 (type)
        ui->stdWidget->setItem(i,2, new QTableWidgetItem(std->getMList()->findMarkByPos(i)->GetType()));
    }
    ui->stdWidget->resizeColumnsToContents();
}

void DeanInterface::setTable3(int r, int c)
{
    QStringList headers;
    headers << "Предмет"<< "Тип оценки";
    ui->stPlanWidget->showGrid();
    ui->stPlanWidget->setColumnCount(c);
    ui->stPlanWidget->setRowCount(r);
    ui->stPlanWidget->setHorizontalHeaderLabels(headers);
    for (int i =0;i<r;i++ )
    {
        ui->stPlanWidget->setItem(i,0,new QTableWidgetItem(currentPlan->getPlanML()->findMarkByPos(i)->GetSubject()));
        ui->stPlanWidget->setItem(i,1,new QTableWidgetItem(currentPlan->getPlanML()->findMarkByPos(i)->GetType()));
    }
      ui->stPlanWidget->resizeColumnsToContents();
}

void DeanInterface::updPlanBoxes()
{
    for (int i = 0;i< spl.size();i++ ) {
        ui->PlanBox->insertItem(i,spl[i]->getDir());
        ui->PlanBox_2->insertItem(i,spl[i]->getDir());
    }
}

void DeanInterface::updGrInfo()
{
    ui->grAvLabel->setText(QString::number(PerformanceCalc::calcGrAverage(currentGroup)));
    ui->exLabel->setText(QString::number(PerformanceCalc::calcExellentStuds(currentGroup)));
    ui->badLabel->setText(QString::number(PerformanceCalc::calcBadStuds(currentGroup)));
}

void DeanInterface::on_GrWidget_cellClicked(int row, int column)
{
    Student* std = currentGroup->getStdList()->findStudentByCard(ui->GrWidget->item(row,0)->text().toInt());
    qDebug() << std->getName();
    if (std->getMList()->countMarks() != 0)
        setTable2(std->getMList()->countMarks(), 3, std);
    qDebug() <<PerformanceCalc::calcStudAverage(std);
    ui->stdAvLabel->setText(QString::number(PerformanceCalc::calcStudAverage(std)));
}

void DeanInterface::on_GrNumBox_currentIndexChanged(int index)
{
    currentGroup = gl->findGroupByNum((ui->GrNumBox->currentText()).toInt());
    if (currentGroup->getStdList()->countStudents() != 0)
        setTable1(currentGroup->getStdList()->countStudents(),2);
    updGrInfo();
    ui->planLabel->setText(currentGroup->getPlan());
}

void DeanInterface::on_addGrButton_clicked()
{
    int numToAdd = ui->grNumEdit->text().toInt();
    gl->addGroup(new Group(numToAdd, new StudentList()));
    ui->GrNumBox->insertItem(gl->countGroups(), QString::number(numToAdd));
}

void DeanInterface::on_delGrButton_clicked()
{
    int numToDel = ui->grNumEdit->text().toInt();
    gl->delGroup(numToDel);
    int i =0;
    while(ui->GrNumBox->itemText(i).toInt() != numToDel)
        i++;
    ui->GrNumBox->removeItem(i);
}

void DeanInterface::on_addStdButton_clicked()
{
    auto it = spl.begin();
    MarksList * ml;
    while(it != spl.end() && (*it)->getDir() != currentGroup->getPlan())
        it++;
    if(it != spl.end())
       ml  = new MarksList(*(*it)->getPlanML());
    else
        ml = new MarksList();
    Student * st = new Student(ui->nameEdit->text(), ui->numEdit->text().toInt(),ml);
    gl->findGroupByNum(currentGroup->getNumber())->getStdList()->addStudent(st);
    if (currentGroup->getStdList()->countStudents() != 0)
        setTable1(currentGroup->getStdList()->countStudents(),2);
    updGrInfo();
}

void DeanInterface::on_delStdButton_clicked()
{
    int grToDel = ui->GrWidget->item(row,0)->text().toInt();
    currentGroup->getStdList()->delStudent(grToDel);
    setTable1(currentGroup->getStdList()->countStudents(),2);
}

void DeanInterface::on_GrWidget_cellPressed(int row, int column)
{
    this->row = row;
    this->column = column;
}

void DeanInterface::on_stdWidget_cellPressed(int row, int column)
{
    rowM = row;
    columnM = column;
}

void DeanInterface::on_saveButton_clicked()
{
    db.saveBase(gl);
    db.savePlans(spl);
}

void DeanInterface::on_exitButton_clicked()
{
    this->close();
}

void DeanInterface::on_changePlanButton_clicked()
{
    StPlan * pl;
    auto iter = spl.begin();
    while ((*iter)->getDir() != ui->PlanBox_2->currentText())
        iter++;
    pl = (*iter);
    for (int i = 0;i < currentGroup->getStdList()->countStudents() ;i++ ) {
        currentGroup->getStdList()->findStudentByPos(i)->setMList(new MarksList(*pl->getPlanML()));
    }
    currentGroup->setPlan(pl->getDir());
    Student* std = gl->findGroupByNum(ui->GrNumBox->currentText().toInt())
            ->getStdList()->findStudentByCard(ui->GrWidget->item(row,0)->text().toInt());
    if (std->getMList()->countMarks() != 0)
        setTable2(std->getMList()->countMarks(), 3, std);
}

void DeanInterface::on_addPlanButton_clicked()
{
     spl.push_back(new StPlan(ui->planEdit->text(),new MarksList()));
     ui->PlanBox->insertItem(spl.size(),spl[spl.size()-1]->getDir());
     ui->PlanBox_2->insertItem(spl.size(),spl[spl.size()-1]->getDir());
}

void DeanInterface::on_delPlanButton_clicked()
{
    int i = 0;
    auto iter = spl.begin();
    while (iter != spl.end() && (*iter)->getDir() != ui->planEdit->text())
        iter++;
    if ((*iter)->getDir() != ui->planEdit->text())
        spl.erase(iter);
    while(ui->PlanBox->itemText(i) != ui->planEdit->text())
        i++;
    ui->PlanBox->removeItem(i);
    ui->PlanBox_2->removeItem(i);
}

void DeanInterface::on_PlanBox_currentIndexChanged(const QString &arg1)
{
    auto iter = spl.begin();
    while ((*iter)->getDir() != arg1)
        iter++;
    currentPlan =(*iter);
    if (currentPlan->getPlanML()->countMarks() != 0)
        setTable3(currentPlan->getPlanML()->countMarks(), 2);
}

void DeanInterface::on_addSubButton_clicked()
{
    QString type = ui->markTypeBox->currentText();
    QString sub = ui->subEdit->text();
    currentPlan->getPlanML()->addMark(new Mark(sub,0,type));
    if (currentPlan->getPlanML()->countMarks() != 0)
        setTable3(currentPlan->getPlanML()->countMarks(), 2);
}

void DeanInterface::on_delSubButton_clicked()
{
    currentPlan->getPlanML()->delMark(rowS);
    if (currentPlan->getPlanML()->countMarks() != 0)
        setTable3(currentPlan->getPlanML()->countMarks(), 2);
}

void DeanInterface::on_stPlanWidget_cellPressed(int row, int column)
{
    rowS = row;
    columnS = column;
}
