#ifndef C_STRING_H
#define C_STRING_H

#include <stdio.h>
#include <string.h>

void process_c_string(char* str) {
    int i = 0, j;
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    while (str[i] != '\0') {
        int count = 1;
        j = i + 1;

        while (str[i] == str[j]) {
            count++;
            j++;
        }

        if (count > 3) {
            printf("###");
        } else {
            printf("%c", str[i]);
        }

        i += count;
    }
    printf("\n");
}

#endif
