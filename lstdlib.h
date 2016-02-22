#ifndef LSTDLIB_H_INCLUDED
#define LSTDLIB_H_INCLUDED

typedef unsigned int sizet;

template<class T>
const T& lmin(const T& a, const T& b) {
    return a < b ? a : b;
}

template<class T>
const T& lmax(const T& a, const T& b) {
    return a > b ? a : b;
}

#endif // LSTDLIB_H_INCLUDED
