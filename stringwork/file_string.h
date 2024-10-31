    #ifndef FILE_STRING_H
    #define FILE_STRING_H

    #include <stdio.h>
    #include <string.h>

void writeStringToFile(const char *filename, const char *str) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }
    fprintf(file, "%s\n", str);
    fclose(file);
}


    void process_file_string(const char* input_filename, const char* output_filename) {
        FILE *input_file = fopen(input_filename, "r");
        FILE *output_file = fopen(output_filename, "w");

        if (input_file == NULL || output_file == NULL) {
            printf("Ошибка открытия файла.\n");
            return;
        }

        char str[100];
        fgets(str, sizeof(str), input_file);

        int len = strlen(str);
        if (str[len - 1] == '\n') str[len - 1] = '\0';

        int i = 0, j;
        while (str[i] != '\0') {
            int count = 1;
            j = i + 1;

            while (str[i] == str[j]) {
                count++;
                j++;
            }

            if (count > 3) {
                fputs("###", output_file);
            } else {
                fputc(str[i], output_file);
            }

            i += count;
        }

        fclose(input_file);
        fclose(output_file);
    }

    #endif
