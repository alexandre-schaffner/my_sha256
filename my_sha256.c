#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "binary.h"

char **parse(char *input) {
    int nb_of_blocks = strlen(input) / 512;
    char **parsed = malloc(sizeof(char *) * (nb_of_blocks + 1));
    int i = 0;

    printf("nb of blocks: %i\n", nb_of_blocks);
    parsed[nb_of_blocks] = NULL;
    for (int j = 0; j < nb_of_blocks; j++) {
        parsed[j] = malloc(sizeof(char) * 513);
        parsed[j][512] = 0;
        for (int k = 0; k < 512; i++, k++)
            parsed[j][k] = input[i];
    }
    return (parsed);
}

char **preprocess(char *bin_str) {
    int dec_og_len = strlen(bin_str);
    char *bin_og_len = dec_to_bin(dec_og_len);
    char *input = NULL;
    int padding = 0;
    int i = 0;

    while (((dec_og_len + 1 + padding) - 448) % 512 != 0)
        padding++;
    input = malloc(sizeof(char) * ((dec_og_len + 1 + padding + 64) + 1));
    input[dec_og_len + 1 + padding] = 0;
    for (; i < dec_og_len; i++)
        input[i] = bin_str[i];
    input[i] = '1';
    i++;
    for (int j = 0; j < padding; j++, i++)
        input[i] = '0';
    for (int j = 0; j < 64 - strlen(bin_og_len); j++, i++)
        input[i] = '0';
    for (int j = 0; j < strlen(bin_og_len); j++, i++)
        input[i] = bin_og_len[j];
    return (parse(input));
}

char *sha256(char *str) {
    // char *pre_string = preprocess(binary_string(str));
    char **M = preprocess(binary_string(str));
    int W[8][8] = {
        {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5},
        {0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174},
        {0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da},
        {0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967},
        {0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85},
        {0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070},
        {0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3},
        {0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2}
    };
    int H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    for (int i = 0; M[i] != NULL; i++) {
        
    }
}

int main() {
    char **pre = preprocess(binary_string("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"));
    int l = 0;

    for(int i = 0; pre[i] != NULL; i++) {
        for (int j = 0, k = 0; j < 16; j++) {
            printf("W[%i] = ", j);
            for (int l = 0; l < 32; l++, k++)
                printf("%c", pre[i][k]);
            printf("\n");
        }
        printf("\n");
    }
}