using namespace std;
#include <vector>
#include <string>
#include <iomanip>
#include "SubRegionGenerator.h"
#include <fstream>
SubRegionGenerator::SubRegionGenerator(CompareBehaviour<int>* a)
{
    subRegData = new ReportData<int>(a);
}

Dict<string, Record*>* SubRegionGenerator::getMaxSubRegions(vector<Record*> records) {
    Dict<string, Record*>* maxRecs = new Dict<string, Record*>();
    int maxPonies = -1;
      
    for (int i = 0; i < records.size(); i++) {
        Record* rec = records[i];
        int year = rec->getYear();
        string region = rec->getRegion();
        string subRegion = rec->getSubRegion();
        int numAnimals = rec->getNumAnimals();
        Record* maxRec = (*maxRecs)[region];
        if (year == 2016
            && subRegion != "All"
            && (
                maxRec == NULL
                || numAnimals > maxRec->getNumAnimals()
            )) {
            maxRecs->set(region, rec);
        }
    }

    return maxRecs;
}

void SubRegionGenerator::compute() {
    vector<Record*> poniesRecords = animalMap["Horses-Ponies"];
    Dict<string, Record*>* maxRecs = getMaxSubRegions(poniesRecords);
    // printReport();
    formatData(maxRecs);
    
    delete maxRecs;
}

void SubRegionGenerator::formatData(Dict<string, Record*>* maxRecs){
    vector<string> keys = maxRecs->getKeys();
    
    for (int i = 0; i < keys.size(); i++) {
        Record* rec = (*maxRecs)[keys.at(i)];
        std::stringstream stream;
        // std::string::paddedLeft()
        stream << std::setfill(' ')
            << std::setw(9)
            << std::left
            << rec->getRegion()
            << std::setw(33)
            << rec->getSubRegion()
            << std::setw(8)
            << std::right
            << rec->getNumAnimals();
        
        // cout << stream.str() << endl;
        subRegData->add(rec->getNumAnimals(), stream.str());
    }
}

void SubRegionGenerator::printReport(){
    cout << "SUB REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl
         << "----------------------------------------------------" << endl << endl;
    
    cout << *subRegData << endl;

    ofstream file("SubRegionMaxPonies.txt", ios::out); 
    if (!file) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    file<<*subRegData;
}

// AnimalType :  vector containing that animal
SubRegionGenerator::~SubRegionGenerator() {
    delete subRegData;
}