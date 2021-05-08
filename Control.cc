#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include "SubRegionGenerator.h"
#include "FarmsByRegionGenerator.h"
#include "ChangeByYearGenerator.h"

Control::Control(/* args */){
    descInt = new DescBehaviour<int>();
    aescFloat = new AscBehaviour<float>();
    descFloat = new DescBehaviour<float>();
    reportVector.push_back(new FarmsByRegionGenerator(descFloat));
    reportVector.push_back(new ChangeByYearGenerator(aescFloat));
    reportVector.push_back(new SubRegionGenerator(descInt));
}

void Control::launch(){
    int i = -1;
    ReportGenerator::readRecords("farms.dat");
    reportVector[0]->compute();
    reportVector[1]->compute();
    reportVector[2]->compute();

    while (i != 0){
        theView.showMenu(i);
        if (i == 3){
            // reportVector[0]->compute();
            reportVector[2]->printReport();
        }
        else if (i == 2){
            // reportVector[0]->compute();
            reportVector[1]->printReport();
        }
        else if (i == 1){
            
            reportVector[0]->printReport();
        }
        else{
            continue;
        }
    }
}

Control::~Control() {
    ReportGenerator::cleanup();
    delete descFloat;
    delete descInt;
    delete aescFloat;
    for (int i = 0; i < reportVector.size(); ++i){
        delete reportVector[i];
    }
}