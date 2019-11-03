#include "bytes.h"

#include <limits.h>
#include <string.h>

#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) &&             \
    (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) && (CHAR_BIT == 8)
#define LITTLE_ENDIAN 1
#else
#define LITTLE_ENDIAN 0
#endif

uint32_t bytes_to_u32(const unsigned char *p)
{
    if (LITTLE_ENDIAN)
    {
        uint32_t x;
        memcpy(&x, p, sizeof x);
        return x;
    }
    else
    {
        return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 |
               (uint32_t)p[3] << 24;
    }
}

void bytes_from_u32(unsigned char *p, uint32_t x)
{
    if (LITTLE_ENDIAN)
    {
        memcpy(p, &x, sizeof x);
    }
    else
    {
        p[0] = (unsigned char)x & 0xFFU;
        p[1] = (unsigned char)(x >> 8) & 0xFFU;
        p[2] = (unsigned char)(x >> 16) & 0xFFU;
        p[3] = (unsigned char)(x >> 24) & 0xFFU;
    }
}