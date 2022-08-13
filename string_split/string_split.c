#include "string_split.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

size_t string_split(
    char *output,
    char not_length_4[10][20],
    const char *input,
    const char *separator
){
    size_t count = 0;

    char *dst = malloc(strlen(input) + 1); // Space for length plus nul
    strcpy(dst, input);
    char *ptr = strtok(dst, separator);
    int counter = 0;

    while (ptr != NULL) {
        if(strlen(ptr)==4){
            if(counter == 1){
                strcat(output, separator);
                strcat(output, ptr);
                //printf("%s", output);

            } else{
                output = ptr;
                counter++;
                //printf("%s", output);
            } 
        } else{
            for(int i = 0; i < (int) strlen(ptr); i++){
                not_length_4[count][i] = ptr[i];
                // printf("%c", not_length_4[count][i]); funktioniert 
            }
            count++;
        }
        ptr = strtok(NULL, separator);
    }
    printf("%s", output);
    free(dst);
    return count;
}

char *iterate(char *p, const char *d, const size_t len){
    while (p != NULL && *p && memcmp(p, d, len) == 0)
    {
        memset(p, 0x0, len);
        p += len;
    }
    return p;
}

char **
tokenize(char **result, char *working, const char *src, const char *delim){
    int i = 0;
    char *p = NULL;
    size_t len = strlen(delim);
    strcpy(working, src);
    p = working;
    for (result[i] = NULL, p = iterate(p, delim, len); p != NULL && *p; p = iterate(p, delim, len))
    {
        result[i++] = p;
        result[i] = NULL;
        p = strstr(p, delim);
    }
    return result;
}



int main(void)
{
    
    char *output;
    char not_length_4[10][20];
    size_t n = 10 * 1000 * 1000;
    //char *input = malloc(sizeof(char) * n);

    // Assemble string "aaaa,aaaa,aaaa,...,aaaa"
    // memset(input, 'a', n);
    // for (size_t i = 4; i < n; i += 5)
    // {
    //     input[i] = ',';
    // }

    const char *input = "abbbcbac1234";
    const char *separator = "bac";

    size_t test = string_split(output, not_length_4, input, separator);
    printf("hier: %ld", test);
}
