#ifndef SUBREGIONGENERATOR_H
#define SUBREGIONGENERATOR_H
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
#include "Dict.h"

class SubRegionGenerator : public ReportGenerator
{
public:
    SubRegionGenerator(CompareBehaviour<int>*);
    ~SubRegionGenerator();
    // Computes the result for SubRegion with the most number of horse/ponies in 2016
    void compute();
    // Take the computed statistics and uses them to populate the ReportData data member
    void formatData(Dict<string, Record*>*);
    //Prints the computed Report in the format required and saves the report to a file
    void printReport();
    
private:
    //Helper Function to get the sub-region with the maximum horse/ponies
    Dict<string, Record*>* getMaxSubRegions(vector<Record*> records);
    ReportData<int>* subRegData;
};

#endif