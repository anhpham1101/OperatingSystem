#include "findsubstr.h"
#include <stdio.h>
#include <string.h>

int find_sub_string(const char* str, const char* sub) {
    int count = 0;
    char strTemp[100], subTemp[100];
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <='Z') strTemp[i] = str[i] + 32;
        else strTemp[i] = str[i];
    }
    for(int i = 0; i < strlen(sub); i++) {
        if(sub[i] >= 'A' && sub[i] <= 'Z') subTemp[i] = sub[i] + 32;
        else subTemp[i] = sub[i];
    }
    strTemp[strlen(str)] = '\0';
    subTemp[strlen(sub)] = '\0';
    for(int i = 0; i < strlen(strTemp); i++) { 
        if(strTemp[i] == subTemp[0]) {
            for(int j = 0; j < strlen(subTemp); j++) {
                if(strTemp[i + j] == subTemp[j]) count++;
            }
            if(count == strlen(subTemp)) return i;
            else {
                count = 0;
            }
        }
    }
    return -1;
}
