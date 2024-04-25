//  helper function declarations
char *string_reverse(char *s);
char *string_resize(char *s, int size);

char* convertToTitle(int columnNumber) {
    
    int i = 0;
    char *column = string_resize(NULL, 1);
    while (columnNumber > 0) {
        column = string_resize(column, i + 2);

        // base 26 system with 1 based indexing
        columnNumber -= 1;
        column[i++] = 'A' + columnNumber % 26;
        columnNumber /= 26;
    }
    column[i++] = '\0';
    return string_reverse(column);
}

// helper function implementations
char *string_reverse(char *s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    return s;
}

char *string_resize(char *s, int size) {
    char *resized = realloc(s, size * sizeof(char));
    if (resized == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        free(s);
        exit(EXIT_FAILURE);
    }
    return resized;
}
