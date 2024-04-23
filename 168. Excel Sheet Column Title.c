char* convertToTitle(int columnNumber) {
    
    int column_length = 1;
    for (int column_number = columnNumber - pow(26, column_length); column_number > 0; column_number -= pow(26, ++column_length))
        ;

    char *column = malloc((column_length + 1) * sizeof(char));
    for (int i = 0; i < column_length - 1; i++) {
        printf("%d\n", pow(26, column_length - i - 1));
        if (columnNumber / pow(26, column_length - i - 1) > 'Z') {
            column[i] = 'Z';
            columnNumber -= pow(26, column_length - i - 1);
        } else {
            column[i] = 'A' - 1 + columnNumber / pow(26, column_length - i - 1);
            columnNumber %= (int) pow(26, column_length - i - 1);
        }
    }
    column[column_length - 1] = 'A' - 1 + columnNumber % 27;
    column[column_length] = '\0';
    return column;
}
