#include <stdio.h>
#include <string.h>
#include "readline.h"
#include "findsubstr.h"

int main(int argc, char* argv[]) {
    char str[100], sub[100];
    strcpy(sub, argv[1]);
    while(read_line(str) != -1) {
        if(find_sub_string(str, sub) != -1) printf("%s\n", str);
    }
}