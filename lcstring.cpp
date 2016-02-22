#include "lcstring.h"

sizet lstrlen(const char* str) {
    sizet i = 0;
    while (str[i++]);
    return i - 1;
}

char* lstrcpy(char* dest, const char* src) {
    sizet len = lstrlen(src);
    sizet i = 0;
    for (; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char* lstrcat(char* dest, const char* src) {
    char* p = dest + lstrlen(dest);
    lstrcpy(p, src);
    return dest;
}

int lstrcmp(const char *lhs, const char *rhs) {
    sizet len1 = lstrlen(lhs), len2 = lstrlen(rhs);
    sizet len = lmin(len1, len2);

    int ret = 0, i;
    for (i = 0; i < len && (ret = lhs[i] - rhs[i]); i++);

    if (!ret) {
        return int(len1) - int(len2);
    }

    return ret;
}
