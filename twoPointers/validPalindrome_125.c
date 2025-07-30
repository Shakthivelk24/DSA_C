bool isPalindrome(char *s) {
    if(s == " ")
       return true;
    int i, j = 0;
    char *str = (char *)malloc((strlen(s) + 1) * sizeof(char));
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' &&isalnum(s[i])) {
            str[j++] = tolower(s[i]);
        }
    }
    str[j] = '\0';
    int start = 0, end = j - 1;
    while (start < end) {
        if (str[start++] != str[end--]) {
            free(str);
            return false;
        }
    }

    free(str);
    return true;
}
