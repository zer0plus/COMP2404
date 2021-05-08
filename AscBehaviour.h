#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H
#include "CompareBehaviour.h"
#include <iostream>
using namespace std;
#include <iomanip>

template <class T>
class AscBehaviour :   public CompareBehaviour<T>
{
public:
    AscBehaviour(/* args */);
    ~AscBehaviour();
    // Compares the two parameters for ascending (increasing) order
    virtual bool compare(T, T);

private:
    /* data */
};

template <class T>
AscBehaviour<T>::AscBehaviour(/* args */)
{
}

template <class T>
bool AscBehaviour<T>::compare(T ex1, T ex2) {
    if (ex1 < ex2) {
        return true;
    }
    return false;
}

template <class T>
AscBehaviour<T>::~AscBehaviour()
{
}

#endif