#include <cstring>
#include "lstring.h"

const sizet EXT_SZ = 64;

LString::LString(const char* src) {
    m_len = lstrlen(src);
    m_size = m_len + EXT_SZ;
    m_str = new char[m_size];
    lstrcpy(m_str, src);
}

LString& LString::operator=(const LString& rhs) {
    if (m_str != NULL) {
        delete [] m_str;
    }

    m_len = rhs.m_len;
    m_size = rhs.m_size;
    m_str = new char[m_size];
    lstrcpy(m_str, rhs.m_str);

    return *this;
}

LString& LString::operator=(const char* src) {
    sizet slen = strlen(src);
    m_len = slen;
    if (slen >= m_size) {
        m_size = slen + EXT_SZ;

        if (m_str != NULL) {
            delete [] m_str;
        }
        m_str = new char[m_size];
    }

    lstrcpy(m_str, src);

    return *this;
}

bool LString::operator<(const LString& rhs) {
    return lstrcmp(m_str, rhs.m_str) < 0;
}

bool LString::operator>(const LString& rhs) {
    return lstrcmp(m_str, rhs.m_str) > 0;
}

bool LString::operator==(const LString& rhs) {
    return lstrcmp(m_str, rhs.m_str) == 0;
}

LString LString::operator+(LString rhs) {
    rhs.m_size += m_size;
    rhs.m_len += m_len;

    char * buf = new char[rhs.m_size];
    lstrcat(lstrcpy(buf, m_str), rhs.m_str);

    if (rhs.m_str != NULL) {
        delete [] rhs.m_str;
    }
    rhs.m_str = new char[rhs.m_size];
    lstrcpy(rhs.m_str, buf);

    return rhs;
}

ostream& operator<<(ostream& os, const LString& str) {
    os << str.c_str();
    return os;
}

// to be compeleted
istream& operator>>(istream& is, LString& str) {
    char buf[1024]; // not suitable
    is >> buf;
    str = buf;
    return is;
}
