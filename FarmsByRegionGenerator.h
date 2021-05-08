#ifndef FARMSBYREGIONGENERATOR_H
#define FARMSBYREGIONGENERATOR_H
#include <sstream>
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"

#define COLUMNS 10
#define ANIMALS 9

class FarmsByRegionGenerator    :  public ReportGenerator
{
public:
    FarmsByRegionGenerator(CompareBehaviour<float>*);
    ~FarmsByRegionGenerator();
    //Computes the result for percentage number of farms for each animal in each region in 2016
    void compute();
    // Take the computed statistics and uses them to populate the ReportData data member
    void formatData(vector<float[COLUMNS]>& maxRecs);
    //Prints the computed Report in the format required and saves the report to a file
    void printReport();
    
private:
    //Helper function to compute the farm by animal type
    int* getFarmCountByType(vector<Record*> records);
    ReportData<float>* farmRegData;
};

#endif