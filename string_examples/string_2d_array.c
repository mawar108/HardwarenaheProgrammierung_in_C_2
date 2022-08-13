#include <stdio.h>
#include <string.h>

int main(void){
    // Two-dimensional string arrays can be accessed in various ways, but no
    // matter which way you choose, make sure that every string is terminated!

    // For example, the content could be set at time of initialization.
    // (Technically, this initializes the remaining bytes to zero, but we should
    // be careful and always set them explicitly anyway.)
    char strings[5][6] = {"Never"};

    // The values could be set explicitly.
    strings[1][0] = 103;
    strings[1][1] = 111;
    strings[1][2] = 110;
    strings[1][3] = 110;
    strings[1][4] = 97;
    strings[1][5] = 0;

    // The function strcpy could be used to copy strings to the memory address
    // of the second string.
    strcpy(strings[2], "give");

    // The function memcpy could be used to copy a fixed number of bytes.
    char bytes[] = {121, 111, 117, 0};
    memcpy(strings[3], bytes, 4);

    // Or the values could be copied one by one.
    char c1 = 'u';
    char c2 = 'p';
    char c3 = '!';
    char c4 = '\0';
    strings[4][0] = c1;
    strings[4][1] = c2;
    strings[4][2] = c3;
    strings[4][3] = c4;

    // INCORRECT: Strings can not be copied with the assignment operator.
    // strings[0] = "bad example";

    for (int i = 0; i < 5; i++){
        printf("%s ", strings[i]);
    }
    printf("\n");

    return 0;
}
