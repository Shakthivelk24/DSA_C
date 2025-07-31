char* intToRoman(int num) {
    
    int numSym[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char* sym[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    
    char* result = (char*)malloc(100 * sizeof(char));
    result[0] = '\0';  

    for (int i = 0; i < 13; i++) {
        while (num >= numSym[i]) {
            strcat(result, sym[i]);
            num -= numSym[i];
        }
    }

    return result;
}
