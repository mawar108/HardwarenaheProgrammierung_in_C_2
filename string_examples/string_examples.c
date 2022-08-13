#include <stdio.h>
#include <string.h> // For strcpy

int main(void){
    // The end of a string in C is marked with a byte with value 0. This byte is
    // called zero terminator or null terminator. The real length of a string is
    // usually not saved. Instead, the length has to be computed by counting the
    // chars in the char-array until the first zero byte is found. In hindsight,
    // that was not a good idea because if the zero byte has been forgotten, the
    // search for the first zero byte only ends if a zero byte is encountered in
    // memory, often after the array bounds, which is a common source of errors.
    // String literals ("double quotes") automatically end with a zero byte. The
    // pointer correct1 points to read-only memory, which means that this string
    // can be printed, but not changed.
    char *correct1 = "1234";

    printf("The first string is: %s\n", correct1);

    // It is better to declare a char pointers as "const" to enable the compiler
    // to complain about attempts to write to that memory region.
    const char *correct2 = "1234";

    // String literals can be copied into arrays *at initialization*. The size
    // of the array is determined automatically and includes the zero byte.
    char correct3[] = "1234";

    // String literals can also be copied into arrays of fixed size. Make sure
    // to leave space for the zero byte!
    char correct4[5] = "1234";

    // Strings can also be created character by character.
    char correct5[5] = {'1', '2', '3', '4', '\0'};

    // A character in C is just an integer, which means that the array could
    // be initialized directly with ASCII codes, although this is discouraged
    // because it is harder to read. Note that '\0' corresponds to the value 0,
    // while the char constant '0' corresponds to value 48.
    char correct6[5] = {49, 50, 51, 52, 0};

    // Array values could also be initialized in a mixed fashion:
    char correct7[5];
    correct7[0] = *correct1;
    correct7[1] = correct2[1];
    correct7[2] = '3';
    correct7[3] = 52;
    correct7[4] = '\0';

    // The strcpy function could be used to copy a string. It also copies the
    // zero byte.
    char correct8[5];
    strcpy(correct8, "1234");

    // It is ok to declare arrays slightly larger than necessary, assuming that
    // the uninitialized chars after the zero byte are not read.
    char correct9[100];
    strcpy(correct9, "1234");

    // Print strings so the compiler does not complain about unused variables.
    printf("%s %s %s %s %s %s %s %s %s\n", correct1, correct3, correct3,
        correct4, correct5, correct6, correct7, correct8, correct9);

    // ERROR: All following examples are INCORRECT!

    // The pointer incorrect1 points to a read-only string.
    // It may not be modified.
    char *incorrect1 = "1234";
    incorrect1[0] = '?';

    // Still incorrect with const, but at least the compiler tells us about it.
    //const char *incorrect2 = "1234";
    //incorrect2[0] = '?';

    // '0' has the decimal value 48, so it is not the same as the zero byte.
    char incorrect3[] = {'1', '2', '3', '4', '0'};

    // Zero byte is missing.
    char incorrect4[4] = {49, 50, 51, 52};

    // No space for zero byte.
    char incorrect5[4] = "1234";

    // Zero byte is missing, although there would have been enough space for it.
    char incorrect6[5];
    incorrect6[0] = '1';
    incorrect6[1] = '2';
    incorrect6[2] = '3';
    incorrect6[3] = '4';

    // Length of incorrect7 can not be computed because zero byte is missing.
    // Therefore, strlen breaks through array bounds on search for a zero byte,
    // eventually causing a segmentation fault.
    char incorrect7[5];
    incorrect7[0] = '1';
    incorrect7[1] = '2';
    incorrect7[2] = '3';
    incorrect7[3] = '4';
    int length = strlen(incorrect7);
    incorrect7[length] = '\0';

    // strcpy kann incorrect6 nicht kopieren, da Nullerminator fehlt.
    char incorrect8[5];
    strcpy(incorrect8, incorrect6);

    // strncpy just copies values and does not itself set a zero byte.
    // In incorrect6, the zero byte was missing, so it can not be copied.
    char incorrect9[5];
    strncpy(incorrect9, incorrect6, 5);

    // No space for zero byte.
    char incorrect10[4];
    strcpy(incorrect10, "1234");

    printf("%s %s %s %s %s %s %s %s %i\n", incorrect1, incorrect3, incorrect4,
        incorrect5, incorrect6, incorrect7, incorrect8, incorrect9, length);

    return 0;
}
