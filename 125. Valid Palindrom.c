bool isPalindrome(char* s) {

    char *left, *right;
    left = s;
    right = s + strlen(s) - 1;
    
    while (left < right) {
        if(!isalnum(*left)) {
            left++;
            continue;
        }
        if(!isalnum(*right)) {
            right--;
            continue;
        }
        if (tolower(*left) != tolower(*right)) {
            return false;
        }
        else {
            left++;
            right--;
        }
    }
    return tolower(*left) == tolower(*right);
}
