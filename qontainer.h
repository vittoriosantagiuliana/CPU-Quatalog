#ifndef QONTAINER_H
#define QONTAINER_H

#include <algorithm>

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
    Qontainer (unsigned int = defaultSize);
    Qontainer (const Qontainer &);

    void push_back (const T &);
    void pop_back ();
    void clear ();
    void remove (const T &);
    unsigned int size () const;
    bool empty () const;
    const T & front () const;
    const T & back () const;
    T & front();
    T & back();
    const T & operator[](unsigned int) const;
    T & operator[](unsigned int);


    class iterator
    {
        friend class Qontainer;
    private:
        T * p;
        iterator (T * = nullptr);
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef int difference_type;
        iterator & operator++();
        iterator operator++(int);
        iterator & operator--();
        iterator operator--(int);
        iterator operator+(int) const;
        iterator operator-(int) const;
        T & operator*() const;
        T * operator->() const;
        bool operator==(const iterator &) const;
        bool operator!=(const iterator &) const;
    };

    class const_iterator
    {
        friend class Qontainer;
    private:
        const T * p;
        const_iterator (const T * = nullptr);
    public:
        const_iterator & operator++ ();
        const_iterator operator++ (int);
        const_iterator & operator-- ();
        const_iterator operator-- (int);
        const_iterator operator+(int) const;
        const_iterator operator-(int) const;
        const T & operator* () const;
        const T * operator-> () const;
        bool operator== (const const_iterator &) const;
        bool operator!= (const const_iterator &) const;
    };

    iterator insert(iterator, const T &);
    iterator erase(iterator);
    const_iterator search(const T &) const;
    iterator search(const T &);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator begin() const;
    const_iterator cend() const;
    const_iterator end() const;
};

// implementation

template <class T>
unsigned int Qontainer<T>::defaultSize(3);

template <class T>
T * Qontainer<T>::resize (unsigned int size) const {
    T * copy = new T[size];
    std::copy(q, q + (size > endIndex ? endIndex : size), copy);
    return copy;
}


template <class T>
Qontainer<T>::Qontainer(unsigned int i) : q(new T[i]), endIndex(0), totalSize(i) { }

template <class T>
Qontainer<T>::Qontainer(const Qontainer<T> & t) : endIndex(t.endIndex), totalSize(t.totalSize), q(t.resize(t.totalSize)) { }

template <class T>
const T & Qontainer<T>::front() const { return *q; }

template <class T>
const T & Qontainer<T>::back() const { return q[endIndex - 1]; }

template <class T>
T & Qontainer<T>::front() { return *q; }

template <class T>
T & Qontainer<T>::back() { return q[endIndex - 1]; }

template <class T>
const T & Qontainer<T>::operator[](unsigned int i) const { return q[i]; }

template <class T>
T & Qontainer<T>::operator[](unsigned int i) { return q[i]; }

template <class T>
void Qontainer<T>::push_back(const T & i) {
    if (!(totalSize > endIndex)) {
        T * temp = q;
        q = resize(totalSize *= 2);
        delete [] temp;
    }
    q[endIndex++] = i;
}

template <class T>
void Qontainer<T>::pop_back() { delete (q + --endIndex); }

template <class T>
void Qontainer<T>::clear () { delete [] q; q = new T[defaultSize]; }

template <class T>
void Qontainer<T>::remove(const T & i) { erase(search(i)); }

template <class T>
unsigned int Qontainer<T>::size() const { return endIndex; }

template <class T>
bool Qontainer<T>::empty() const { return endIndex == 0; }


// iterators

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::insert(iterator i, const T & d) {
    if (!(totalSize > endIndex)) {
        T * temp = q;
        q = resize(totalSize *= 2);
        delete [] temp;
    }
    std::copy_backward(i, end(), end() + 1);
    *i = d;
    ++endIndex;
    return i;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::erase(iterator i) {
    if(!empty() && i != end()) {
        std::copy(i + 1, end(), i);
        --endIndex;
    }
    return i;
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::search(const T & d) const {
    for (const_iterator it = cbegin(); it != cend(); ++it)
        if (*it == d)
            return it;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::search(const T & d) {
    for (iterator it = begin(); it != end(); ++it)
        if (*it == d)
            return it;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::begin() { return iterator(q); }
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::end() { return iterator(q + endIndex); }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cbegin() const { return const_iterator(q); }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::begin() const { return const_iterator(q); }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cend() const { return const_iterator(q + endIndex); }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::end() const { return const_iterator(q + endIndex); }

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
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator+(int i) const { return iterator(p + i); }
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator-(int i) const { return iterator(p - i); }
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
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator+(int i) const { return const_iterator(p + i); }
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator-(int i) const { return const_iterator(p - i); }
template <class T>
const T & Qontainer<T>::const_iterator::operator* () const { return *p; }
template <class T>
const T * Qontainer<T>::const_iterator::operator-> () const { return p; }
template <class T>
bool Qontainer<T>::const_iterator::operator== (const const_iterator & i) const { return p == i.p; }
template <class T>
bool Qontainer<T>::const_iterator::operator!= (const const_iterator & i) const { return p != i.p; }



#endif // QONTAINER_H
