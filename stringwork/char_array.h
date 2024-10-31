#ifndef CHAR_ARRAY_H
#define CHAR_ARRAY_H

#include <stdio.h>
#include <string.h>

void process_char_array(char str[]) {
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';
    int i = 0, j = 0;

    while (i < len) {
        int count = 1;
        while (i + count < len && str[i] == str[i + count]) {
            count++;
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
