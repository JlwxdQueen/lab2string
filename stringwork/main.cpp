#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "char_array.h"
#include "c_string.h"
#include "file_string.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    printf("Выберите способ обработки строки:\n");
    printf("1. Строка как массив символов\n");
    printf("2. Строка как Cи-строка\n");
    printf("3. Строка из файла\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: {
            char *str = (char *)malloc(1);
            int length = 0;
            char ch;

            printf("Введите строку: ");
            while ((ch = getchar()) != '\n' && ch != EOF) {
                str[length] = ch;
                length++;
                str = (char *)realloc(str, length + 1);
            }
            str[length] = '\0';
            process_char_array(str);

            free(str);
            break;
        }
        case 2: {
            char *str = (char *)malloc(1);
            int length = 0;
            char ch;

            printf("Введите строку: ");
            while ((ch = getchar()) != '\n' && ch != EOF) {
                str[length] = ch;
                length++;
                str = (char *)realloc(str, length + 1);
            }
            str[length] = '\0';
            process_c_string(str);

            free(str);
            break;
        }
        case 3: {
            const char *input_filename = "../stringwork/file1.txt";
            const char *output_filename = "../stringwork/file2.txt";

            char *str = (char *)malloc(1);
            if (str == nullptr) {
                printf("Ошибка выделения памяти.\n");
                return 1;
            }

            int length = 0;
            char ch;
            printf("Введите строку: ");
            while ((ch = getchar()) != '\n' && ch != EOF) {
                str[length] = ch;
                length++;
                str = (char *)realloc(str, length + 1);
                if (str == NULL) {
                    printf("Ошибка выделения памяти.\n");
                    return 1;
                }
            }
            str[length] = '\0';

            writeStringToFile("../stringwork/file1.txt", str);
            free(str);

            process_file_string(input_filename, output_filename);
            printf("Результат записан в файл %s\n", output_filename);
            break;
        }
        default:
            printf("Неверный выбор!\n");
    }

    return 0;
}
