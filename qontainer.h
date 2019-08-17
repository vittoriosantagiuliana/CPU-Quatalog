#ifndef QONTAINER_H
#define QONTAINER_H

#include "deepptr.h"

template <class T>
class Qontainer
{
private:
    DeepPtr<T> * q;
    int startIndex;
    int endIndex;
    int totalSize;



public:
    Qontainer();

    unsigned int size() const;

    class Iterator
    {
    public:
        Iterator Start() const;

        T * operator->() const;
    };
};

// IMPLEMENTATION


template<class T>
unsigned int Qontainer<T>::size() const {
    return endIndex - startIndex;
}

#endif // QONTAINER_H
