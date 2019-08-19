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

    class iterator
    {
    private:
        T * p;
    public:
        iterator Start() const;
        iterator End() const;
        iterator (const T *);
        iterator (const iterator &);

        iterator & operator++ ();
        friend iterator & operator++ (iterator &);
        T * operator->() const;
    };

    class const_iterator
    {
    private:
        const T * p;
    public:
        const_iterator Start() const;
        const_iterator End() const;


        const T * operator->() const;
    };

};

// IMPLEMENTATION


template<class T>
unsigned int Qontainer<T>::size() const {
    return endIndex - startIndex;
}

#endif // QONTAINER_H
