#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *dec_to_bin(int nb) {
    int size = 1;
    int step = 1; // 2⁰
    char *result = NULL;

    while (step < nb) {
        size++;
        step = step * 2; // 2¹, 2², 2³...
    }
    if (step != nb && nb > 0)
        size--;
    result = malloc((sizeof(char) * size) + 1);
    result[size] = '\0';
    for (int i = size - 1; i >= 0; i--) {
        result[i] = nb % 2 + 48;
        nb /= 2;
    }
    return (result);
}

char *binary_string(char *str) {
    char *output = malloc(sizeof(char) * ((strlen(str) * 8) + 1));
    int c = 0;
    int i_output = 0;
    char *bin = NULL;
    int padding = 0;

    for (int i = 0; str[i]; i++) {
        c = str[i];
        bin = dec_to_bin(c);
        padding = 8 - strlen(bin);
        for (int j = 0; j < padding; j++, i_output++)
            output[i_output] = '0';
        for (int j = 0; bin[j]; j++, i_output++)
            output[i_output] = bin[j];
    }
    return (output);
}