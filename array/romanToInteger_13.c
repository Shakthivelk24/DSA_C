int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanToInt(char* s) {
    int len = strlen(s);
    int res = value(s[len - 1]);
    for (int i = len - 2; i >= 0; i--) {
        if (value(s[i]) < value(s[i + 1])) {
            res -= value(s[i]);
        } else {
            res += value(s[i]);
        }
    }
    return res;
}
