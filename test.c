#include <stdio.h>

int main() {
    char *str1 = "I love C";
    char *str2 = "I love C";
    if( str1 == str2) {
        printf("eq\n");
    } else {
        printf("noteq\n");
    }
    return 0;
}