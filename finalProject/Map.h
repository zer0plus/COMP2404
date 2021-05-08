#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
#include "Record.h"

template <class T>
class Map
{
public:
    Map();
    ~Map();
    // Adds a record to it's corresponding matching key
    void add(T key, Record* rec);
    //Returns the size of the vector of keys
    int getKeySize();
    //Returns all the vector of keys of the map
    vector<T> getKeys();
    // Returns the value of the map corresponding to the key from the parameter
    vector<Record*>& operator[] (T key);

private:
    vector<T> keysCol;
    vector<vector<Record*>> valuesCol;
};

template <class T>
Map<T>::Map() {

}

template <class T>
Map<T>::~Map() {
  
}

template <class T>
void Map<T>::add(T key, Record* rec) {
  for (int i = 0; i < keysCol.size(); i++) {
    if (keysCol.at(i) == key) {
      valuesCol.at(i).push_back(rec);
      return;
    }
  }
  
  keysCol.push_back(key);

  vector<Record*> v = vector<Record*>(0);
  v.push_back(rec);
  valuesCol.push_back(v);
}

template <class T>
int Map<T>::getKeySize() {
  return keysCol.size();
}

template <class T>
vector<T> Map<T>::getKeys() {
  return keysCol;
}

template <class T>
vector<Record*>& Map<T>::operator[] (T key) {
  for (int i = 0; i < keysCol.size(); i++) {
    if (keysCol.at(i) == key) {
      return valuesCol.at(i);
    }
  }
  cerr << "Key was not found";
  exit(1);
//   throw "Key was not found"; //" + key + " // Follow Christine's error handling
}