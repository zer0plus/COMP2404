#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include "ReportGenerator.h"
#include "SubRegionGenerator.h"
#include "View.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"
class Control
{
public:
    Control(/* args */);
    ~Control();
    // Launches the controller
    void launch();

private:
    /* data */
    vector<ReportGenerator*> reportVector; 
    View theView;
    DescBehaviour<int>* descInt;
    AscBehaviour<float>* aescFloat;
    DescBehaviour<float>* descFloat;
};

#endif