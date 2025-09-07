#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int brute(char text[],char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if(j==m){
                return i;
         }
    }
    return -1;
}
int main(){
     char text[100],pattern[100];
     printf("Enter the text : ");
     gets(text);
     printf("Enter the Pattern : ");
     gets(pattern);
     int res = brute(text,pattern);
     if(res != -1){
        printf("Pattern found at index %d\n",res);
     }
     else{
        printf("Pattern not found");
     }
     return 0;
}
