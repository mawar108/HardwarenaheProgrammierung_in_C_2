#include <stdio.h>

const char* correct(void){
    // It is ok to return a pointer to a string literal because it is stored in
    // constant memory and not on the stack.
    return "Hello, World!";
}

void incorrect1(char **pointer){
    // INCORRECT: This string is stored on the stack and will vanish once the
    // function returns. The string should have been stored outside the function
    // (or later, it could be dynamically allocated on the heap).
    char string[] = "Hello, World!";
    *pointer = string;
}

const char* incorrect2(void){
    // INCORRECT: Same mistake as before.
    char string[] = "Hello, World!";
    return string;
}

void print_string(char *string){
    char unused[] = "Hacked!";
    printf("%s\n", string);
}

int main(void){
    printf("%s\n", correct());
    char *pointer;
    incorrect1(&pointer);
    print_string(pointer);
    printf("%s\n", incorrect2());

    return 0;
}
