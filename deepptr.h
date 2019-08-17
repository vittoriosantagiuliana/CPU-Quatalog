#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class DeepPtr
{
    T * info;

public:
    DeepPtr (const T &);
    DeepPtr (const DeepPtr &);

    DeepPtr & operator=(const DeepPtr &);
    bool operator== (const DeepPtr &) const;
    T & operator* () const;
    T * operator-> () const;

    ~DeepPtr();
};

// IMPLEMENTATION

template<class T>
DeepPtr<T>::DeepPtr(const T & d) : info (&d) { }

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr & d) : info(d.info != nullptr ? new T(d.info) : nullptr) { }

template <class T>
DeepPtr<T> & DeepPtr<T>::operator= (const DeepPtr & d) {
    if (d.info != info && d.info) {
        delete info;
        info = d.info;
    }
}

template <class T>
bool DeepPtr<T>::operator== (const DeepPtr & d) const {
    return info == d.info;
}

template <class T>
T & DeepPtr<T>::operator* () const {
    return *info;
}

template <class T>
T * DeepPtr<T>::operator-> () const {
    return info;
}

template <class T>
DeepPtr<T>::~DeepPtr() { if (info != nullptr) delete info; }

#endif // DEEPPTR_H
