#define HAPPY_NUMBER 1

int squareDigitSum(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    int n_slow = n;
    int n_fast = squareDigitSum(n);
    while (n_slow != n_fast) {
        n_slow = squareDigitSum(n_slow);
        n_fast = squareDigitSum(squareDigitSum(n_fast));
    }
    return n_slow == HAPPY_NUMBER;
}
