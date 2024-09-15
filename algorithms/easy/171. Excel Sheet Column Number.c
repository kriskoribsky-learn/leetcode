#define BASE 26
#define OFFSET 1

int titleToNumber(char* columnTitle) {

    int length = 0;
    while(columnTitle[++length] != '\0')
        ;

    int result = 0;
    long base = 1;
    while(--length >= 0) {
        result += ((columnTitle[length] - 'A') + OFFSET) * base;
        base *= BASE;
    }

    return result;
}
