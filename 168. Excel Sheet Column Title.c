char* convertToTitle(int columnNumber) {

    int n_letters = 0;
    int max_column = 0;
    for (int current_column = columnNumber; current_column > 0; current_column -= max_column) {
        max_column += (int) pow(26, n_letters + 1);
        n_letters++;
    } 

    printf("letters: %d, max column: %d\n", n_letters, max_column);

    char string[n_letters + 1];
    while(n_letters) {
        while(max_column > columnNumber) {
            columnNumber -= (int) pow(26, n_letters - 1);
        }
        
    }

    return NULL;
}
