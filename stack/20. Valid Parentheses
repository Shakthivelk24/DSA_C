bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top < 0) {
                free(stack);
                return false;
            }
            if ((c == ')' && stack[top] == '(') ||
                (c == '}' && stack[top] == '{') ||
                (c == ']' && stack[top] == '[')) {
                top--;  // pop
            } else {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}
