using namespace std;
#include <vector>
#include <string>
#include <iomanip>
#include "ChangeByYearGenerator.h"
#include <fstream>

ChangeByYearGenerator::ChangeByYearGenerator(CompareBehaviour<float>* c)
{
    chngYearData = new ReportData<float>(c);
}

void ChangeByYearGenerator::compute(){

    int maxArr[yearMap.getKeySize()];
    float tempArr2[yearMap.getKeySize()];
    int mapSize = yearMap.getKeySize();
    float totalAnimals = 0.0f;
    float totalChange = 0.0f;
    Record* addRec;
    Map<int> addMap;
    vector<float> vecAnimalPercent;
    vector<string> vecAnimalNames;
    // CompareBehaviour<string>* c;
    // ReportData<string>(c) tempReport;
    for (int i = 0; i < mapSize; ++i){
        totalAnimals = 0.0f;
        vector<Record*> recordVec = yearMap[yearMap.getKeys().at(i)];
        for (int j = 0; j < recordVec.size(); ++j){
            if (recordVec[j]->getRegion() == "CAN"){
                /* code */
                totalAnimals += recordVec[j]->getNumAnimals();
                maxArr[i] = totalAnimals;
            }
        }
    }


    /////////////////////////////////////////////@ND PART///////////////////////////////////////////////
    for (size_t i = 0; i < animalMap.getKeySize(); i++){
        vecAnimalNames.push_back(animalMap.getKeys()[i]);
    }
    float total_animal_type = 0.0f;
    for (int i = 0; i < vecAnimalNames.size(); i++){
        /* code */
        stringstream stream;
        stream << setw(23) << left<< vecAnimalNames[i];

        for (int j = 0; j < mapSize; j++){
            /* code */
            total_animal_type = 0.0f;
            vector<Record*> recordVec = yearMap[yearMap.getKeys().at(j)];

            for (int k = 0; k < recordVec.size(); k++){
                if (recordVec[k]->getRegion() == "CAN" && recordVec[k]->getAnimalType() == vecAnimalNames[i]){
                    total_animal_type += recordVec[k]->getNumAnimals();
                }
            }
            tempArr2[j] = float((total_animal_type / maxArr[j]) * 100);
            
            stream << setw(14) << left <<setprecision(1)<<fixed<< float((total_animal_type / maxArr[j]) * 100) ;
        }
        totalChange = float(tempArr2[1] - tempArr2[0]);
        stream << setw(5) << right<<setprecision(1)<< float(tempArr2[1] - tempArr2[0]);
        chngYearData->add(totalChange, stream.str());
    }
    // formatData(addMap);
}

void ChangeByYearGenerator::formatData(Map<int> map){
    
}

void ChangeByYearGenerator::printReport(){
    cout << endl;
    cout << setw(6) << left << " " << setw(17) << left << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" <<endl;
    cout << setw(6) << left << " " << setw(17) << left << "----------------------------------------" <<endl<<endl;
    cout << setw(23) << left << " "<< setw(14)<<left<<"2011" << setw(14) << left << "2016"<< setw(5) <<right<<"Change" <<endl<<endl;
    cout<<*chngYearData<<endl;

    ofstream file("AnimalPercentChange.txt", ios::out);
    if (!file) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    file<<*chngYearData;
}

ChangeByYearGenerator::~ChangeByYearGenerator()
{
    delete chngYearData;
}