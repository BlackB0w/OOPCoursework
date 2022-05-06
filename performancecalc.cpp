#include "performancecalc.h"

PerformanceCalc::PerformanceCalc()
{

}

double PerformanceCalc::calcGrAverage(Group *g)
{
    double sum = 0;
    for (int i = 0; i< g->getStdList()->countStudents();i++){
        sum += calcStudAverage(g->getStdList()->findStudentByPos(i));
    }
    double ans = sum/g->getStdList()->countStudents();
    return ans;
}

double PerformanceCalc::calcStudAverage(Student *std)
{
    double sum = 0, divider;
    for (int i = 0; i< std->getMList()->countMarks();i++){
        if (std->getMList()->findMarkByPos(i)->GetType() != "Зачет")
        {sum += std->getMList()->findMarkByPos(i)->GetMark();
            divider++;
        }
    }
    double ans = sum/divider;
    return ans;
}

double PerformanceCalc::calcGrSubAverage(Group *g, QString sub)
{
    double sum = 0;
    for (int i = 0; i< g->getStdList()->countStudents();i++){
        sum += g->getStdList()->findStudentByPos(i)->getMList()->findMarkBySubject(sub)->GetMark();
    }
    double ans = sum/g->getStdList()->countStudents();
    return ans;
}

int PerformanceCalc::calcExellentStuds(Group *g)
{
    int count = 0;
    for (int i = 0; i< g->getStdList()->countStudents();i++){
        bool flag = true;
        Student * std = g->getStdList()->findStudentByPos(i);
        for (int j = 0; j< std->getMList()->countMarks(); j++){
            if(std->getMList()->findMarkByPos(j)->GetType() != "Зачет")
                if(std->getMList()->findMarkByPos(j)->GetMark() != 5)
                    flag = false;
            if(std->getMList()->findMarkByPos(j)->GetType() == "Зачет")
                if(std->getMList()->findMarkByPos(j)->GetMark() == 0)
                    flag = false;
        }
        if(flag)
            count++;
    }
    return count;
}

int PerformanceCalc::calcBadStuds(Group *g)
{
    int count = 0;
    for (int i = 0; i< g->getStdList()->countStudents();i++){
        bool flag = false;
        Student * std = g->getStdList()->findStudentByPos(i);
        for (int j = 0; j< std->getMList()->countMarks(); j++){

            if(std->getMList()->findMarkByPos(j)->GetType() != "Зачет")
                if(std->getMList()->findMarkByPos(j)->GetMark() <= 2)
                    flag = true;
            if(std->getMList()->findMarkByPos(j)->GetType() == "Зачет")
                if(std->getMList()->findMarkByPos(j)->GetMark() == 0)
                    flag = true;
        }
        if(flag)
            count++;
    }
    return count;
}
