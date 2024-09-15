uint32_t reverseBits(uint32_t n) {

    uint32_t ans = 0;

    for (int _ = 0; _ < 32; _++) {
        ans <<= 1;
        ans |= n & 1;
        n >>= 1;
    }
    
    return ans;
}
