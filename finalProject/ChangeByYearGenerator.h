#ifndef CHANGEBYYEARGENERATOR 
#define CHANGEBYYEARGENERATOR
#include <sstream>
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
#include "Dict.h"
class ChangeByYearGenerator    :  public ReportGenerator
{
public:
    ChangeByYearGenerator(CompareBehaviour<float>*);
    ~ChangeByYearGenerator();
    // Computes the result for Change of animals from 2011 to 2016 in percentages
    void compute();
    // Take the computed statistics and uses them to populate the ReportData data member
    void formatData(Map<int> map);
    //Prints the computed Report in the format required and saves the report to a file
    void printReport();

private:
    ReportData<float>* chngYearData;
};

#endif