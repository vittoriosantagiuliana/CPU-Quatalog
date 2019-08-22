#ifndef QONTAINER_H
#define QONTAINER_H

#include "deepptr.h"

template <class T>
class Qontainer
{
private:
    T * q;
    int endIndex;
    int totalSize;



public:
    Qontainer();

    unsigned int size() const;


    class iterator
    {
        friend class Qontainer;
    private:
        T * p;
        iterator (T * = nullptr);
    public:
        iterator & operator++ ();
        iterator operator++ (int);
        iterator & operator-- ();
        iterator operator-- (int);
        T & operator*() const;
        T * operator->() const;
    };

    class const_iterator
    {
    private:
        const T * p;
        const_iterator (const T * = nullptr);
    public:
        const_iterator & operator++ ();
        const_iterator operator++ (int);
        const_iterator & operator-- ();
        const_iterator operator-- (int);
        T & operator*() const;
        T * operator->() const;
    };

    iterator & begin();
    iterator & end();
    const_iterator & cbegin() const;
    const_iterator & cend() const;
};

// IMPLEMENTATION

template <class T>
Qontainer<T>::Qontainer() : q(nullptr), endIndex(0), totalSize(0) { }

template <class T>
unsigned int Qontainer<T>::size() const { return endIndex; }

template <class T>
typename Qontainer<T>::iterator & Qontainer<T>::begin() { return iterator(q); }
template <class T>
typename Qontainer<T>::iterator & Qontainer<T>::end() { return iterator(q + endIndex); }
template <class T>
typename Qontainer<T>::const_iterator & Qontainer<T>::cbegin() const { return const_iterator(q); }
template <class T>
typename Qontainer<T>::const_iterator & Qontainer<T>::cend() const { return const_iterator(q + endIndex); }

template <class T>
Qontainer<T>::iterator::iterator(T * d) : p(d) { }
template <class T>
typename Qontainer<T>::iterator & Qontainer<T>::iterator::operator++ () { p++; return *this; }
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++ (int) { iterator temp (* this); p++; return temp; }


template <class T>
Qontainer<T>::const_iterator::const_iterator(const T * d) : p(d) { }


#endif // QONTAINER_H
