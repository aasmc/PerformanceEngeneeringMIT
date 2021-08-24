
/**
 * Sets the kth bit in unsigned integer [x] to 1.
 * First create mask by shifting 1 to the left k number of times.
 * Then OR the result with x.
 *
 * E.g. k = 7, x = 1011110101101101
 *        1 << k = 0000000010000000
 *  x | (1 << k) = 1011110111101101
 *
 * @param x
 * @param k
 * @return
 */
unsigned setKthBit(unsigned x, unsigned k) {
    x = x | (1 << k);
    return x;
}

/**
 * Clears kth bit in an unsigned integer [x].
 * First create mask by shifting 1 to the left k number of times.
 * Invert the mask. AND the result with x.
 *
 * E.g.      k = 7
 *           x = 1011110111101101
 *      1 << k = 0000000010000000
 *   ~(1 << k) = 1111111101111111
 * x&~(1 << k) = 1011110101101101
 * @param x
 * @param k
 * @return
 */
unsigned clearKthBit(unsigned x, unsigned k) {
    x = x & ~(1 << k);
    return x;
}

/**
 * Toggles kth bit in an unsigned integer [x] on or off depending on the initial state of [x].
 * First create mask by shifting 1 to the left k number of times.
 * XOR the result with x.
 *
 * E.g. k = 7, x = 1011110101101101
 *        1 << k = 0000000010000000
 *  x ^ (1 << k) = 1011110111101101
 *
 * E.g. k = 7, x = 1011110111101101
 *        1 << k = 0000000010000000
 *  x ^ (1 << k) = 1011110101101101
 *
 * @param x
 * @param k
 * @return
 */
unsigned toggleKthBit(unsigned x, unsigned k) {
    x = x ^ (1 << k);
    return x;
}

/**
 * Extracts a bit field from unsigned integer [x].
 * The bits to be extracted are specified in the mask.
 *
 * E.g.            x = 1011110101101101
 *              mask = 0000011110000000
 *          x & mask = 0000010100000000
 * x & mask >> shift = 0000000000001010
 *
 * @param x unsigned integer from which a bit field is extracted
 * @param shift number of trailing (or leading if you look from the point of binary representation) zeroes in the mask
 * @param mask specifies the bits to be extracted
 * @return
 */
unsigned extractBitField(unsigned x, unsigned shift, unsigned mask) {
    unsigned y = (x & mask) >> shift;
    return y;
}

/**
 * Sets the bit field in an unsigned integer x to the bits stored in y.
 * The bit field to be set is specified by mask.
 *
 * E.g.                         x = 1011110101101101
 *                              y = 0000000000000011
 *                           mask = 0000011110000000
 *                       x & mask = 1011100001101101
 * x = (x & ~mask) | (y << shift) = 1011100111101101
 * @param x
 * @param y
 * @param shift
 * @param mask
 * @return
 */
unsigned setBitField(unsigned x, unsigned y, unsigned shift, unsigned mask) {
    x = (x & ~mask) | (y << shift);
    return x;
}

/**
 * Swaps two integers without employing a tmp variable. Inefficient
 * because compiler cannot optimize sequential instructions.
 *
 * E.g.     x = 10111101
 *          y = 00101110
 *  x = x ^ y = 10010011
 *  y = x ^ y = 10111101
 *  x = x ^ y = 00101110
 *
 * @param x
 * @param y
 */
void noTempSwap(unsigned *x, unsigned *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

/**
 * Selects the minimum of two integers and returns the result without using if statements.
 *
 * Look from right to left. (x < y), if it is true then we need to return x. Also, if
 * it is true its value is represented as 1.
 *     -(x < y) = -1 (this is represented as all ones in two's complement, i.e. 1111111111111111)
 *     (x ^ y) & 111111111111 = (x ^ y);
 *     y ^ (x ^ y) = x;
 *
 *     If x < y is false then we have it represented as 0.
 *     -(x < y) = 0
 *     (x ^ y) & 0000000000000000 = 0
 *     y ^ 0 = y
 *
 * @param x
 * @param y
 * @return
 */
unsigned minimumOfTwo(unsigned x, unsigned y) {
    unsigned r = y ^ ((x ^ y) & -(x < y));
    return r;
}

/**
 * E.g.
 *        x = 0010000001010000
 *       -x = 1101111110110000
 * x & (-x) = 0000000000010000
 * @param x
 * @return
 */
int computeLeastSignificantBitMask(int x) {
    int res = x & (-x);
    return res;
}

/**
 * Counts the number of bits set to 1 in unsigned integer [x].
 * It does so by repeatedly eliminating a least significant bit.
 *
 * E.g. iteration 1.
 *             x = 0010110111010000
 *         x - 1 = 0010110111001111
 *   x & (x - 1) = 0010110111000000
 * @param x
 * @return the number of bits set to 1 in unsigned integer x
 */
unsigned populationCount(unsigned x) {
    int r;
    for(r = 0; x != 0; ++r) {
        x &= x - 1;
    }
    return r;
}












