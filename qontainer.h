#ifndef QONTAINER_H
#define QONTAINER_H

#include "deepptr.h"

template <class T>
class Qontainer
{
private:
    T * q;
    unsigned int endIndex;
    unsigned int totalSize;
    static unsigned int defaultSize;

    T * resize (unsigned int) const;

public:
    Qontainer ();
    Qontainer (unsigned int = defaultSize);
    Qontainer (const Qontainer &);

    void push_back (const T &);
    void pop_back ();
    void clear ();
    unsigned int size () const;
    T & front () const;
    T & back () const;


    class iterator
    {
    private:
        T * p;
        iterator (T * = nullptr);
    public:
        iterator & operator++ ();
        iterator operator++ (int);
        iterator & operator-- ();
        iterator operator-- (int);
        T & operator* () const;
        T * operator-> () const;
        bool operator== (const iterator &) const;
        bool operator!= (const iterator &) const;
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
        T & operator* () const;
        T * operator-> () const;
        bool operator== (const const_iterator &) const;
        bool operator!= (const const_iterator &) const;
    };

    iterator & begin();
    iterator & end();
    const_iterator & cbegin() const;
    const_iterator & cend() const;
};

// implementation

template <class T>
unsigned int Qontainer<T>::defaultSize(3);

template <class T>
T * Qontainer<T>::resize (unsigned int size) const {
    T * copy = new T[size];
    for (int i = 0; i < endIndex; ++i)
        copy[i] = q[i];
    return copy;
}


template <class T>
Qontainer<T>::Qontainer(unsigned int i) : q(new T[i]), endIndex(0), totalSize(i) { }

template <class T>
Qontainer<T>::Qontainer(const Qontainer<T> & t) : endIndex(t.endIndex), totalSize(t.totalSize), q(t.sizedCopy(t.totalSize)) {
    for (int i = 0; i < endIndex; ++i)
        q[i] = q[i].clone();
}

template <class T>
T & Qontainer<T>::front() const { return *q; }

template <class T>
T & Qontainer<T>::back() const { return q[endIndex - 1]; }

template <class T>
void Qontainer<T>::push_back(const T & i) {
    if (! totalSize > endIndex) {
        T * temp = q;
        q = resize(totalSize *= 2);
        delete [] temp;
    }
    q[endIndex++] = &i;
}

template <class T>
void Qontainer<T>::pop_back() { delete q + --endIndex; }

template <class T>
void Qontainer<T>::clear () { delete [] q; q = new T[defaultSize]; }

template <class T>
unsigned int Qontainer<T>::size() const { return endIndex; }


// iterators

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
typename Qontainer<T>::iterator & Qontainer<T>::iterator::operator++ () { ++p; return *this; }
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++ (int) { iterator temp (*this); ++p; return temp; }
template <class T>
typename Qontainer<T>::iterator & Qontainer<T>::iterator::operator-- () { --p; return *this; }
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator-- (int) { iterator temp (*this); --p; return temp; }
template <class T>
T & Qontainer<T>::iterator::operator*() const { return *p; }
template <class T>
T * Qontainer<T>::iterator::operator->() const { return p; }
template <class T>
bool Qontainer<T>::iterator::operator== (const iterator & i) const { return p == i.p; }
template <class T>
bool Qontainer<T>::iterator::operator!= (const iterator & i) const { return p != i.p; }

template <class T>
Qontainer<T>::const_iterator::const_iterator(const T * d) : p(d) { }
template <class T>
typename Qontainer<T>::const_iterator & Qontainer<T>::const_iterator::operator++ () { ++p; return *this; }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator++ (int) { const_iterator temp (*this); ++p; return temp; }
template <class T>
typename Qontainer<T>::const_iterator & Qontainer<T>::const_iterator::operator-- () { --p; return *this; }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator-- (int) { const_iterator temp (*this); --p; return temp; }
template <class T>
T & Qontainer<T>::const_iterator::operator* () const { return *p; }
template <class T>
T * Qontainer<T>::const_iterator::operator-> () const { return p; }
template <class T>
bool Qontainer<T>::const_iterator::operator== (const const_iterator & i) const { return p == i.p; }
template <class T>
bool Qontainer<T>::const_iterator::operator!= (const const_iterator & i) const { return p != i.p; }



#endif // QONTAINER_H
