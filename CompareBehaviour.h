#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H
#include <iostream>
using namespace std;
#include <iomanip>

template <class T>
class CompareBehaviour
{
public:
    CompareBehaviour(/* args */);
    ~CompareBehaviour();
    // pure virtual function defined to compare ascending or descending behaviour
    virtual bool compare(T, T) = 0;

private:
    /* data */
};

template <class T>
CompareBehaviour<T>::CompareBehaviour(/* args */)
{
}

template <class T>
CompareBehaviour<T>::~CompareBehaviour()
{
}

#endif