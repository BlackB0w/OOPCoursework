#ifndef PERFORMANCECALC_H
#define PERFORMANCECALC_H
#include "grouplist.h"

class PerformanceCalc
{
public:
    PerformanceCalc();
    static double calcGrAverage(Group* g);
    static double calcStudAverage(Student* std);
    static double calcGrSubAverage(Group *g, QString sub);
    static int calcExellentStuds(Group *g);
    static int calcBadStuds(Group *g);
};

#endif // PERFORMANCECALC_H
