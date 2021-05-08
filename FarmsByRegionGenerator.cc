using namespace std;
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "FarmsByRegionGenerator.h"

FarmsByRegionGenerator::FarmsByRegionGenerator(CompareBehaviour<float>* a)
{
    farmRegData = new ReportData<float>(a);
}

string animalTypes[ANIMALS] = {
    "Horses-Ponies",
    "Goats",
    "Llamas-Alpacas",
    "Rabbits",
    "Bison-Buffalo",
    "Elk-Wapiti",
    "Domestic-Deer",
    "Wild-Boars",
    "Mink"
};

int* FarmsByRegionGenerator::getFarmCountByType(vector<Record*> records) {
    int* farms = new int[COLUMNS];
    for (int i = 0; i < COLUMNS; i++) farms[i] = 0;
      
    for (int i = 0; i < records.size(); i++) {
        Record* rec = records[i];
        int year = rec->getYear();
        string region = rec->getRegion();
        string subRegion = rec->getSubRegion();

        string animalType = rec->getAnimalType();
        int n_farms = rec->getNumFarms();

        if (year == 2016 && subRegion == "All") {
            for (int j = 0; j < ANIMALS; j++) {
                if (animalType == animalTypes[j]) {

                    farms[j] += n_farms;
                }                
            }

            farms[9] += n_farms;
        }
    }
    return farms;
}

void FarmsByRegionGenerator::compute() {
    vector<string> regions = regionMap.getKeys();
    int n_regions = regions.size();

    for (int i = 0; i < n_regions; i++) {
        if (regions[i] == "CAN") {
            regions.erase(regions.begin()+i);
            n_regions -= 1;
        }
    }

    vector<int*> totals = vector<int*>(n_regions);

    int totalPerColumn[COLUMNS] = {0};
    for (int i = 0; i < n_regions; i++) {
        string region = regions[i];
        int* farms = getFarmCountByType(regionMap[region]);
        totals[i] = farms;
        for (int j = 0; j < COLUMNS; j++) {
            totalPerColumn[j] += farms[j];
        }
    }

    vector<float[COLUMNS]> percentages = vector<float[COLUMNS]>(n_regions);
    for (int i = 0; i < n_regions; i++) {        
        for (int j = 0; j < COLUMNS; j++) {
            if (totalPerColumn[j] == 0) {
                percentages[i][j] = 0;
            } else {
                percentages[i][j] = (float) totals[i][j] / totalPerColumn[j] * 100;
            }
        }
    }

    for (int i = 0; i < n_regions; i++) {  
        delete totals[i];
    }
    
    formatData(percentages);
}

void FarmsByRegionGenerator::formatData(vector<float[COLUMNS]>& percentages){

    vector<string> regions = regionMap.getKeys();
    int n_regions = regions.size();

    for (int i = 0; i < n_regions; i++) {
        if (regions[i] == "CAN") {
            regions.erase(regions.begin()+i);
            n_regions -= 1;
        }
    }

    for (int i = 0; i < n_regions; i++) {
        string region = regions[i];
        float* percentageRow = percentages[i];

        stringstream stream;

        stream
            << region
            << setfill(' ')
            << fixed
            << setprecision(1)
            << right;

        for (int j = 0; j < COLUMNS; j++) {
            stream
                << setw(10)
                << percentageRow[j];
        }
        
        farmRegData->add(percentageRow[9], stream.str());
    }
}

void FarmsByRegionGenerator::printReport(){
    cout << "                         PERCENTAGE OF FARMS BY REGION IN 2016" << endl
         << "                         -------------------------------------" << endl
         << endl
         << "       Horses/    Goats    Llamas    Rabbits   Bison/     Elk/     Domestic   Wild      Mink    Totals" << endl
         << "       Ponies              Alpacas             Buffalo    Wapiti     Deer     Boars                   " << endl
         << *farmRegData << endl;

    ofstream file("FarmsByRegion.txt", ios::out); //SubRegionMaxPonies
    if (!file) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    file<<*farmRegData;
}

// AnimalType :  vector containing that animal
FarmsByRegionGenerator::~FarmsByRegionGenerator() {
    delete farmRegData;
}