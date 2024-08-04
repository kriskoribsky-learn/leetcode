#define BIT 0b1lu

uint32_t reverseBits(uint32_t n) {

    uint32_t result = 0;

    for (int left = 31, right = 0; left > right; left--, right++) {
        result |= ((BIT << left) & n) >> (left - right);
        result |= ((BIT << right) & n) << (left - right);
    }
    return result;
}
