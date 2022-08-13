#include "string_split.h"
#include <string.h>
#include <stdlib.h>

void initialize_with_random_chars(char *chars, size_t length){
    for (size_t i = 0; i < length; i++){
        chars[i] = 33 + rand() % 94;
    }
}

void test(
    const char *input,
    const char *expected_output,
    const char *expected_not_length_4[],
    size_t expected_count,
    const char *separator
){
    char not_length_4[10][20];
    // Initialize array with garbage to make missing '\0'-bytes more obvious.
    for (size_t i = 0; i < 10; i++){
        initialize_with_random_chars(not_length_4[i], 20);
    }

    // Allocate exactly enough bytes for output and 0-terminator
    size_t num_bytes = sizeof(char) * (strlen(expected_output) + 1);
    char *output = malloc(num_bytes);
    initialize_with_random_chars(output, num_bytes);

    // Split input string into output and 2d array
    size_t count = string_split(output, not_length_4, input, separator);

    // Check if output matches. Only small strings will be printed.
    if (strlen(output) < 1000 && strlen(expected_output) < 1000){
        ck_assert_str_eq(output, expected_output);
    }else{
        ck_assert_int_eq(0, strcmp(output, expected_output));
    }

    free(output);

    // Check if number of expected parts which are not of length 4 matches.
    ck_assert_int_eq(count, expected_count);

    // Check if parts match the expected parts
    for (size_t i = 0; i < expected_count; i++){
        ck_assert_str_eq(not_length_4[i], expected_not_length_4[i]);
    }
}

#test empty
    test("", "", NULL, 0, ", ");

#test ente
    test("Ente", "Ente", NULL, 0, ", ");

#test ente_gans
    test("Ente,Gans", "Ente,Gans", NULL, 0, ",");

#test ente_gans_other_separator
    test("Ente_~_Gans", "Ente_~_Gans", NULL, 0, "_~_");

#test ente_fuchs
    const char *not_length_4[] = {"Fuchs"};
    test("Ente, Fuchs", "Ente", not_length_4, 1, ", ");

#test pferd_nothing_ente
    const char *not_length_4[] = {"Pferd"};
    test("Pferd, , Ente", "Ente", not_length_4, 1, ", ");

#test beispiel_aufgabenblatt
    const char *not_length_4[] = {
        "Pferd",
        "Kuh",
    };
    test("Pferd,Ente,Kuh,,,,Gans", "Ente,Gans", not_length_4, 2, ",");

#test many_animals
    const char *input =
        ", Donald, Ente, Gans, , Hund, , Fuchs, Kuh, Pferd, Wolf, ";
    const char *output = "Ente, Gans, Hund, Wolf";
    const char *not_length_4[] = {
        "Donald",
        "Fuchs",
        "Kuh",
        "Pferd",
    };

    test(input, output, not_length_4, 4, ", ");

#test pipe_separator
    const char *input = "||||Hello||||World||||";
    const char *not_length_4[] = {
        "Hello",
        "World",
    };
    test(input, "", not_length_4, 2, "|");

#test long_separator
    const char *input =
        "Hello, World!"
        "12345678901234567890123456789012345678901234567890"
        "Lorem"
        "12345678901234567890123456789012345678901234567890"
        "ipsum"
        "12345678901234567890123456789012345678901234567890"
        "dolor"
        "12345678901234567890123456789012345678901234567890"
        "sit"
        "12345678901234567890123456789012345678901234567890"
        "amet";
    const char *not_length_4[] = {
        "Hello, World!",
        "Lorem",
        "ipsum",
        "dolor",
        "sit",
    };
    const char *separator =
        "12345678901234567890123456789012345678901234567890";

    test(input, "amet", not_length_4, 5, separator);

#test longer_separator
    const char *input = "Hello, World!";
    const char *not_length_4[] = {"Hello, World!"};
    const char *separator =
        "123456789012345678901234567890123456789012345678900123456789";

    test(input, "", not_length_4, 1, separator);

#test only_separator
    test("aaaaaaaa", "", NULL, 0, "aa");

#test mostly_separator
    test("aaaaaaaaaaaaaa", "aaaa", NULL, 0, "aaaaa");

#test many_animals_and_nothing_to_remove
    const char *input =
        "Affe---Gans---Hund---Wolf---Orca---"
        "Ente---Ente---Ente---Ente---Ente";
    test(input, input, NULL, 0, "---");

#test remove_most
    const char *input =
        "Gorilla,Schimpanse,Elefant,Giraffe,Koi,"
        "Krabbe,Katze,Kamel,Hirsch,Bison";
    const char *not_length_4[] = {
        "Gorilla",
        "Schimpanse",
        "Elefant",
        "Giraffe",
        "Koi",
        "Krabbe",
        "Katze",
        "Kamel",
        "Hirsch",
        "Bison",
    };

    test(input, "", not_length_4, 10, ",");

#test numbers
    const char *input = "3141   5926   5358   9793   2384   6264   3383   2795";
    test(input, input, NULL, 0, "   ");

#test kommas
    const char *input = "|,|,,|,,,|,,,,|,,,,,|,,,,,,|....|";
    const char *output = ",,,,|....";
    const char *not_length_4[] = {",", ",,", ",,,", ",,,,,", ",,,,,,"};
    test(input, output, not_length_4, 5, "|");

#test max_length_parts
    const char *input =
        "1234567890123456789"
        "!$%&/()=?{[]}+*~#'-_|"
        "abcdefghijklmnopqrs";
    const char *not_length_4[] = {
        "1234567890123456789",
        "abcdefghijklmnopqrs",
    };
    test(input, "", not_length_4, 2, "!$%&/()=?{[]}+*~#'-_|");

#test long_input
    size_t n = 10 * 1000 * 1000;
    char *input = malloc(sizeof(char) * n);

    // Assemble string "aaaa,aaaa,aaaa,...,aaaa"
    memset(input, 'a', n);
    for (size_t i = 4; i < n; i += 5){
        input[i] = ',';
    }
    input[n - 1] = '\0';

    test(input, input, NULL, 0, ",");

    free(input);

#test longest_separator
    const char *input = "Ente";

    size_t n = 10 * 1000 * 1000;
    char *separator = malloc(sizeof(char) * (n + 1));
    memset(separator, 'b', n);
    separator[n] = '\0';

    test(input, input, NULL, 0, separator);

    free(separator);
