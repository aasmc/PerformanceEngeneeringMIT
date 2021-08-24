
#include <cstdlib>

/**
 * Merges two arrays into the third one in sorted order.
 * @param C Pointer to the resulting array.
 * @param A Pointer to first array.
 * @param B Pointer to second array.
 * @param na  Size of array A.
 * @param nb  Size of array B.
 */
static void merge(long * __restrict C,
                  long * __restrict A,
                  long * __restrict B,
                  size_t na,
                  size_t nb
                  ) {
    while (na > 0 && nb > 0) {
        if (*A <= *B) {
            *C++ = *A++; --na;
        } else {
            *C++ = *B++; --nb;
        }
    }
    while (na > 0) {
        *C++ = *A++;
        --na;
    }
    while (nb > 0) {
        *C++ = *B++;
        --nb;
    }
}

/**
 * Runs slower on modern machines because compilers can optimize this
 * better on their own. E.g. clang with -O3 flag will do this better.
 * @param C
 * @param A
 * @param B
 * @param na
 * @param nb
 */
static void mergeBranchless(long * __restrict C,
                            long * __restrict A,
                            long * __restrict B,
                            size_t na,
                            size_t nb) {
    while (na > 0 && nb > 0) {
        long cmp = (*A <= *B);
        // see bit hacks for this one
        long min = *B ^ ((*B ^ *A) & -cmp);
        *C++ = min;
        A +=cmp; na -= cmp;
        B += !cmp; nb -=!cmp;
    }
    while (na > 0) {
        *C++ = *A++;
        --na;
    }
    while (nb > 0) {
        *C++ = *B++;
        --nb;
    }
}

/**
 * Computes (x + y) mod n, assuming that 0 <= x <= n and 0 <= y <= n.
 * Can be done like: r = (x + y) % n. But division is expensive unless by a power of 2.
 * Can be done like: r = (z < n) ? z : z - n; But has unpredictable branch, that is expensive.
 *
 * if (z >= n) is true then it is 1. -1 = 111111111111111111 in two's complement.
 * n & 1111111111111111 = n, so we get z - n
 * else if (z >= n) is false then it is 0. -0 = 0. n & 0 = 0;
 * So we get z - 0 = z.
 *
 * Same result as before.
 */

unsigned modularAddition(unsigned x, unsigned y, unsigned n) {
    unsigned z = x + y;
    unsigned res = z - (n & -(z >= n));
    return res;
}






















