#ifndef LSTRING_H_INCLUDED
#define LSTRING_H_INCLUDED

#include <iostream>
#include "lcstring.h"

using std::istream;
using std::ostream;

class LString {
public:
    LString(): m_str(NULL), m_len(0), m_size(0) {}
    LString(const char *);
    ~LString() { if (m_str != NULL) delete [] m_str; }

    LString& operator=(const LString&);
    LString& operator=(const char *);

    bool operator<(const LString&);
    bool operator>(const LString&);
    bool operator==(const LString&);

    LString operator+(LString);

    friend ostream& operator<<(ostream&, const LString&);
    friend istream& operator>>(istream&, LString&);

    const char * c_str() const { return m_str; }

private:
    char * m_str;
    sizet m_len;
    sizet m_size;
};

#endif // LSTRING_H_INCLUDED
