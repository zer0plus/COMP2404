#ifndef RECORD_H
#define RECORD_H
#include <string>

class Record
{
    friend ostream& operator<<(ostream&, Record&);
public:
    Record(int, string, string, string, int, int);
    ~Record();
    // Returns AnimalType
    string getAnimalType();
    // Returns Year
    int getYear();
    // Returns Sub Region
    string getSubRegion();
    // Returns Region
    string getRegion();
    // Returns Number of animals
    int getNumAnimals();
    // Returns Number of farms
    int getNumFarms();
    
private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};

#endif