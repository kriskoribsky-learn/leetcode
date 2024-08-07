#define BASE 2

int hammingWeight(int n) {

    int res = 0;

    while(n > 0) {
        res += (int) n % BASE == 1;
        n /= BASE;
    }

    return res;
}
