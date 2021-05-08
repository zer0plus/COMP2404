#ifndef DICT_H
#define DICT_H
#include <vector>

template <class K, class V>
class Dict
{
public:
    Dict();
    ~Dict();
    // Sets keys and value of the dictionary
    void set(K key, V val);
    //Returns all the keys of the dictionary
    vector<K> getKeys();
    // Overloaded operator for [] which returns the value corresponding to the key value passed in the parameter
    V operator[] (K key);

private:
    vector<K> keysCol;
    vector<V> valuesCol;
};

template <class K, class V>
Dict<K, V>::Dict() {

}

template <class K, class V>
Dict<K, V>::~Dict() {
  
}

template <class K, class V>
void Dict<K, V>::set(K key, V val) {
  for (int i = 0; i < keysCol.size(); i++) {
    if (keysCol[i] == key) {
      valuesCol[i] = val;
      return;
    }
  }

  keysCol.push_back(key);
  valuesCol.push_back(val);
}

template <class K, class V>
vector<K> Dict<K, V>::getKeys() {
  return keysCol;
}

template <class K, class V>
V Dict<K, V>::operator[] (K key) {
  for (int i = 0; i < keysCol.size(); i++) {
    // cout << keysCol.at(i) << endl;
    if (keysCol.at(i) == key) {
      return valuesCol.at(i);
    }
  }

  return NULL;
}

#endif