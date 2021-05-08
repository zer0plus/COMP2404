#include <iostream>
using namespace std;
#include "Record.h"
#include "ReportGenerator.h"
#include "DescBehaviour.h"
#include "Dict.h"
#include "Control.h"

int main() {
    // Record theRecord(2011, "BC", "North-Coast", "Llamas-Alpacas", 27, 199);
    // cout << endl << "For the record: " << theRecord <<endl <<endl;
    // ReportGenerator::readRecords("farms.dat");
    // // Map<int> yearMap;
    // // repGen.readRecords("test.dat");
    // // repGen.readRecords("test2.dat");
    // DescBehaviour<int> desc;

    // SubRegionGenerator subGen(&desc);
    // subGen.compute();
    // // subGen.formatData();
    // subGen.printReport();
    Control c;
    c.launch();

    return 0;
} 