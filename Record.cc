#include <iostream>
using namespace std;
#include <iomanip>
#include "Record.h"

Record::Record(int y, string reg, string subReg, string aniType, int farms, int animals)
    :   year(y), region(reg), subRegion(subReg), animalType(aniType), numFarms(farms), numAnimals(animals)
{

}

string Record::getAnimalType() {
    return animalType;
}

string Record::getRegion() {
    return region;
}

string Record::getSubRegion() {
    return subRegion;
}

int Record::getYear() {
    return year;
}

int Record::getNumAnimals() {
    return numAnimals;
}

int Record::getNumFarms() {
    return numFarms;
}


ostream& operator<<(ostream& out, Record& r) {
    out << r.year << "   " << r.region << "   " 
    << r.subRegion << "   " << r.animalType << "   " 
    << r.numFarms << "   " << r.numAnimals;

    return out;
}

Record::~Record()
{
}