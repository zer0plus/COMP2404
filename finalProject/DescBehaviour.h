#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H
#include "CompareBehaviour.h"
#include <iostream>
using namespace std;
#include <iomanip>

template <class T>
class DescBehaviour  :   public CompareBehaviour<T>
{
public:
    DescBehaviour(/* args */);
    ~DescBehaviour();
    // Compares the two parameters for descending (decreasing) order
    virtual bool compare(T, T);

private:
    /* data */
};

template <class T>
DescBehaviour<T>::DescBehaviour(/* args */)
{
}

template <class T>
bool DescBehaviour<T>::compare(T ex1, T ex2) {
    if (ex1 > ex2) {
        return true;
    }
    return false;
}

template <class T>
DescBehaviour<T>::~DescBehaviour()
{
}

#endif