#ifndef REPORTDATA_H
#define REPORTDATA_H
#include <string>
#include <vector>
#include "CompareBehaviour.h"

template <class T>
class ReportData
{
    template <class V> 
    friend ostream& operator<<(ostream& out, ReportData<V>& r);
private:
    /* data */  
    template <class V> 
    class ReportRow{
        public:
            // ReportRow(V, string);
            V rowKey;
            string reportRowData;

        // template <class V>
        ReportRow(V key, string data) : rowKey(key), reportRowData(data) { }
    };
    vector<ReportRow<T>> vecRows; // Figure out whether using report row objects would be better or ptrs for speed
    CompareBehaviour<T>* comparer;

public:
    ReportData(CompareBehaviour<T>*);
    ~ReportData();
    void add(T, string);
    int getVecSize();
};

///////////////////////////////////////////////////////////////////

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c)   :   comparer(c)
{
}

template <class T>
void ReportData<T>::add(T Key, string row) {
    bool flag = true;
    ReportRow<T> rowIn(Key, row);
    class vector<ReportRow<T> >::iterator itr;

    if (vecRows.size() == 0) {
        vecRows.push_back(rowIn);
        
        return;
    }

    for (itr = vecRows.begin(); itr != vecRows.end(); ++itr) {
        /* code */
        if (comparer->compare(Key, itr->rowKey)) {  
            vecRows.insert(itr, rowIn);
            flag = false;
            return;
        }
    }
    if (flag) {
        /* code */
        vecRows.push_back(rowIn);
        return;
    }
}

template <class T>
int ReportData<T>::getVecSize(){
    return vecRows.size();
}

template <class T>
ostream& operator<<(ostream& out, ReportData<T>& r) {
    for (int i = 0; i < r.vecRows.size(); ++i){
        out << r.vecRows[i].reportRowData <<endl;
    }
    return out;
}

template <class T>
ReportData<T>::~ReportData()
{
}

#endif