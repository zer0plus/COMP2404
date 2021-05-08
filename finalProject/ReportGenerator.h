#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include <vector>
#include <string>
#include "Record.h"
#include "Map.h"

template <class T> class Map;
class ReportGenerator
{
public:
    ReportGenerator(/* args */);
    virtual ~ReportGenerator();

    //Reads the records from the given file
    static void readRecords(string);

    //Pure Virtual Function to compute the statistics for a report
    virtual void compute() = 0;
    
    //Pure Virtual Function to print reports 
    virtual void printReport() = 0;

    //Cleans up the memory of records 
    static void cleanup();

protected:
    static vector<Record*> recordsCollection;
    static Map<int> yearMap;
    static Map<string> regionMap;
    static Map<string> animalMap;
    
};

#endif