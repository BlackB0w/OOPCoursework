#include "db.h"
#include <QVariant>
#include <QDebug>
#include <QSqlError>

DB::DB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Program Files\\DB Browser for SQLite\\faculty.db");
}

bool DB::openConnection()
{

    return db.open();
}
void DB::closeConnection()
{
    db.close();
}
void DB::readBase(GroupList* gl)
{
    if (openConnection()){
        QSqlQuery query;
        query.exec("SELECT grNumber, plan  FROM _group");
        while(query.next()){
            Group* gr = new Group();
            int num = query.value(0).toInt();
            QString plan = query.value(1).toString();
            gr->setNumber(num);
            gr->setPlan(plan);
            qDebug()<< num;
            QList <Student*> stList;
            QSqlQuery query2;
            query2.prepare("SELECT stud_id, name FROM student WHERE grNumber = (?)");
            query2.addBindValue(QVariant(num));
            query2.exec();
            while (query2.next()){
                int sid = query2.value(0).toInt();
                QString name = query2.value(1).toString();
                Student* std = new Student();
                std->setName(name);
                std->setStdCard(sid);
                QSqlQuery query3;
                query3.prepare("SELECT subName, mark, type FROM mark WHERE stud_id = (?)");
                query3.bindValue(0,sid);
                query3.exec();

                QList <Mark*> mList;
                while (query3.next()){
                    int mark = query3.value(1).toInt();
                    QString sub = query3.value(0).toString();
                    QString type = query3.value(2).toString();
                    Mark* m = new Mark(sub,mark, type);
                    mList.push_back(m);
                }
                MarksList* list = new MarksList();
                list->setMarksList(mList);
                std->setMList(list);
                stList.push_back(std);
            }
            StudentList* sl = new StudentList();
            sl->setStdList(stList);
            gr->setStdList(sl);
            gl->addGroup(gr);
        }
        closeConnection();
    }
}

void DB::saveBase(GroupList * gl){
    if (openConnection())
    {   QSqlQuery delq;
        delq.exec("DELETE FROM _group");
        QSqlQuery delq2;
        delq2.exec("DELETE FROM student");
        QSqlQuery delq3;
        delq3.exec("DELETE FROM mark");
        for (int i = 0; i< gl->countGroups(); i++)
        {
            QSqlQuery query;
            int grNum = gl->findGroupByPos(i)->getNumber();
            QString plan = gl->findGroupByPos(i)->getPlan();
            query.prepare("INSERT INTO _group (grNumber, plan) VALUES (?,?)");
            query.addBindValue(grNum);
            query.addBindValue(plan);
            query.exec();

            for (int j = 0; j< gl->findGroupByPos(i)->getStdList()->countStudents(); j++)
            {

                QSqlQuery query2;
                QString stdName =  gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getName();
                int stdCardNum = gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getStdCard();
                query2.prepare("INSERT INTO student (stud_id, name, grNumber) VALUES (?,?,?)");
                query2.addBindValue(stdCardNum);
                query2.addBindValue(stdName);
                query2.addBindValue(grNum);
                query2.exec();

                for (int k = 0; k< gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getMList()->countMarks(); k++)
                {
                    QSqlQuery query3;
                    QString sub = gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getMList()->findMarkByPos(k)->GetSubject();
                    int mark = gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getMList()->findMarkByPos(k)->GetMark();
                    QString type = gl->findGroupByPos(i)->getStdList()->findStudentByPos(j)->getMList()->findMarkByPos(k)->GetType();
                    query3.prepare("INSERT INTO mark (subName, mark,type, stud_id) VALUES (?,?,?,?)");
                    query3.addBindValue(sub);
                    query3.addBindValue(mark);
                    query3.addBindValue(type);
                    query3.addBindValue(stdCardNum);
                    query3.exec();

                }
            }
        }
        closeConnection();
    }
}

void DB::readUsers(RolesLists *rl){
    if(openConnection())
    {
        QSqlQuery sq;
        QList<StudentRole*>stl;
        sq.prepare("SELECT login, pass, grNum, stud_id FROM strole");
        sq.exec();
        while(sq.next()){
            QString l = sq.value(0).toString();
            QString p = sq.value(1).toString();
            int gr = sq.value(2).toInt();
            int id = sq.value(3).toInt();
            stl.push_back(new StudentRole(l,p,gr,id));
        }
        rl->setStuds(stl);
        QSqlQuery pq;
        QList <ProfessorRole*> prl;
        pq.prepare("SELECT * FROM profrole");
        pq.exec();

        while(pq.next())
        {
            int p_id = pq.value(0).toInt();
            QString l = pq.value(1).toString();
            QString p = pq.value(2).toString();
            QList <QString> subl;

            QSqlQuery subq;
            subq.prepare("SELECT subName FROM sub WHERE prof_id = (?)");
            subq.addBindValue(p_id);
            subq.exec();

            while(subq.next())
            {
                QString sub = subq.value(0).toString();
                qDebug() << sub;
                subl.push_back(sub);
            }
            prl.push_back(new ProfessorRole(l,p,subl));
        }
        rl->setProfs(prl);
        QSqlQuery dq;
        QList <DeanRole*> dl;
        dq.prepare("SELECT login, pass FROM deanrole");
        dq.exec();

        while(dq.next()){
            QString l = dq.value(0).toString();
            QString p = dq.value(1).toString();
            dl.push_back(new DeanRole(l,p));
        }
        qDebug() << dl.size();
        rl->setDeans(dl);
        closeConnection();
    }
}

QList <StPlan*> DB::readPlans()
{
    QList<StPlan *> sp;
    if(openConnection()){
        QSqlQuery q;
        q.prepare("SELECT * FROM StudPlan");
        q.exec();
        qDebug() << q.lastError() << q.lastQuery();
        while(q.next()){
            QSqlQuery q2;
            QString pn = q.value(1).toString();
            int id = q.value(0).toInt();
            q2.prepare("SELECT sub_name,mark_type FROM planStr WHERE plan_id = (?)");
            q2.addBindValue(id);
            q2.exec();
            qDebug() << q2.lastError() << q2.lastQuery();
            QList <Mark*> ml;
            while(q2.next()){
                QString sn = q2.value(0).toString();
                QString mt = q2.value(1).toString();
                Mark * m = new Mark(sn,0,mt);
                ml.push_back(m);
            }
            sp.push_back(new StPlan(pn,new MarksList(ml)));
        }
        closeConnection();
    }

    return sp;
}

void DB::savePlans(QList<StPlan *> sp)
{
    if(openConnection()){
        QSqlQuery delq, q1,q2;
        delq.exec("DELETE FROM StudPlan");
        delq.exec("DELETE FROM planStr");
        for (int i = 0; i< sp.size();i++){
            q1.prepare("INSERT INTO StudPlan(plan_id,planname) VALUES (?,?)");
            q1.addBindValue(i+1);
            q1.addBindValue(sp[i]->getDir());
            q1.exec();
            qDebug() << q1.lastError() << q1.lastQuery();
            for (int j = 0; j<sp[i]->getPlanML()->countMarks();j++){
                Mark * tmp = sp[i]->getPlanML()->findMarkByPos(j);
                q2.prepare("INSERT INTO planStr(sub_name,mark_type,plan_id) VALUES (?,?,?)");
                q2.addBindValue(tmp->GetSubject());
                q2.addBindValue(tmp->GetType());
                q2.addBindValue(i+1);
                q2.exec();
            }
        }
        closeConnection();
    }

}

