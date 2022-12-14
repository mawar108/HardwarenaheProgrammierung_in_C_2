/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "string_split_tests.ts" instead.
 */

#include <check.h>

#line 1 "string_split_tests.ts"
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

START_TEST(empty)
{
#line 51
    test("", "", NULL, 0, ", ");

}
END_TEST

START_TEST(ente)
{
#line 54
    test("Ente", "Ente", NULL, 0, ", ");

}
END_TEST

START_TEST(ente_gans)
{
#line 57
    test("Ente,Gans", "Ente,Gans", NULL, 0, ",");

}
END_TEST

START_TEST(ente_gans_other_separator)
{
#line 60
    test("Ente_~_Gans", "Ente_~_Gans", NULL, 0, "_~_");

}
END_TEST

START_TEST(ente_fuchs)
{
#line 63
    const char *not_length_4[] = {"Fuchs"};
    test("Ente, Fuchs", "Ente", not_length_4, 1, ", ");

}
END_TEST

START_TEST(pferd_nothing_ente)
{
#line 67
    const char *not_length_4[] = {"Pferd"};
    test("Pferd, , Ente", "Ente", not_length_4, 1, ", ");

}
END_TEST

START_TEST(beispiel_aufgabenblatt)
{
#line 71
    const char *not_length_4[] = {
        "Pferd",
        "Kuh",
    };
    test("Pferd,Ente,Kuh,,,,Gans", "Ente,Gans", not_length_4, 2, ",");

}
END_TEST

START_TEST(many_animals)
{
#line 78
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

}
END_TEST

START_TEST(pipe_separator)
{
#line 91
    const char *input = "||||Hello||||World||||";
    const char *not_length_4[] = {
        "Hello",
        "World",
    };
    test(input, "", not_length_4, 2, "|");

}
END_TEST

START_TEST(long_separator)
{
#line 99
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

}
END_TEST

START_TEST(longer_separator)
{
#line 124
    const char *input = "Hello, World!";
    const char *not_length_4[] = {"Hello, World!"};
    const char *separator =
        "123456789012345678901234567890123456789012345678900123456789";

    test(input, "", not_length_4, 1, separator);

}
END_TEST

START_TEST(only_separator)
{
#line 132
    test("aaaaaaaa", "", NULL, 0, "aa");

}
END_TEST

START_TEST(mostly_separator)
{
#line 135
    test("aaaaaaaaaaaaaa", "aaaa", NULL, 0, "aaaaa");

}
END_TEST

START_TEST(many_animals_and_nothing_to_remove)
{
#line 138
    const char *input =
        "Affe---Gans---Hund---Wolf---Orca---"
        "Ente---Ente---Ente---Ente---Ente";
    test(input, input, NULL, 0, "---");

}
END_TEST

START_TEST(remove_most)
{
#line 144
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

}
END_TEST

START_TEST(numbers)
{
#line 163
    const char *input = "3141   5926   5358   9793   2384   6264   3383   2795";
    test(input, input, NULL, 0, "   ");

}
END_TEST

START_TEST(kommas)
{
#line 167
    const char *input = "|,|,,|,,,|,,,,|,,,,,|,,,,,,|....|";
    const char *output = ",,,,|....";
    const char *not_length_4[] = {",", ",,", ",,,", ",,,,,", ",,,,,,"};
    test(input, output, not_length_4, 5, "|");

}
END_TEST

START_TEST(max_length_parts)
{
#line 173
    const char *input =
        "1234567890123456789"
        "!$%&/()=?{[]}+*~#'-_|"
        "abcdefghijklmnopqrs";
    const char *not_length_4[] = {
        "1234567890123456789",
        "abcdefghijklmnopqrs",
    };
    test(input, "", not_length_4, 2, "!$%&/()=?{[]}+*~#'-_|");

}
END_TEST

START_TEST(long_input)
{
#line 184
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

}
END_TEST

START_TEST(longest_separator)
{
#line 199
    const char *input = "Ente";

    size_t n = 10 * 1000 * 1000;
    char *separator = malloc(sizeof(char) * (n + 1));
    memset(separator, 'b', n);
    separator[n] = '\0';

    test(input, input, NULL, 0, separator);

    free(separator);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, empty);
    tcase_add_test(tc1_1, ente);
    tcase_add_test(tc1_1, ente_gans);
    tcase_add_test(tc1_1, ente_gans_other_separator);
    tcase_add_test(tc1_1, ente_fuchs);
    tcase_add_test(tc1_1, pferd_nothing_ente);
    tcase_add_test(tc1_1, beispiel_aufgabenblatt);
    tcase_add_test(tc1_1, many_animals);
    tcase_add_test(tc1_1, pipe_separator);
    tcase_add_test(tc1_1, long_separator);
    tcase_add_test(tc1_1, longer_separator);
    tcase_add_test(tc1_1, only_separator);
    tcase_add_test(tc1_1, mostly_separator);
    tcase_add_test(tc1_1, many_animals_and_nothing_to_remove);
    tcase_add_test(tc1_1, remove_most);
    tcase_add_test(tc1_1, numbers);
    tcase_add_test(tc1_1, kommas);
    tcase_add_test(tc1_1, max_length_parts);
    tcase_add_test(tc1_1, long_input);
    tcase_add_test(tc1_1, longest_separator);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
