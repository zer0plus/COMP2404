using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "ReportGenerator.h"

vector<Record*> ReportGenerator::recordsCollection = vector<Record*>(0);
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;

ReportGenerator::ReportGenerator(/* args */)
{
}

void ReportGenerator::readRecords(string filename) {
  std::ifstream infile(filename, ios::in);
  if (!infile) {
      cout << "Error: could not open file" <<endl;
  }

//   ReportGenerator::recordsCollection.clear();
  
  int year, numFarms, numAnimals;
  string region, subRegion, animalType;

  while(infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals) {
    Record* theRecord = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
    ReportGenerator::recordsCollection.push_back(theRecord);
    ReportGenerator::yearMap.add(year, theRecord);
    ReportGenerator::regionMap.add(region, theRecord);
    ReportGenerator::animalMap.add(animalType, theRecord);
  }

//   // DEBUGGING PURPOSES ONLY
//   vector<string> keys = ReportGenerator::regionMap.getKeys();
//   for (int i = 0; i < ReportGenerator::regionMap.getKeySize(); i++) {
//     vector<Record*> vecRecords = ReportGenerator::regionMap[keys[i]];
//     cout << "The Key is: " << keys[i] << endl;
//     for (int j = 0; j < vecRecords.size(); j++) {
//       Record* r = vecRecords.at(j);
//       cout << *r << endl;
//     }
//   }
}

void ReportGenerator::cleanup() {
    for (int i = 0; i < ReportGenerator::recordsCollection.size(); i++) {
      delete ReportGenerator::recordsCollection[i];
    }
}

ReportGenerator::~ReportGenerator()
{
    
}