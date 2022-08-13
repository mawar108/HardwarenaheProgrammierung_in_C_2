#include <stddef.h>

// This function splits an input string on a given separator up into parts.
// Parts of length 4 are written into the output string, again separated by
// the given separator.
// Parts of length 0 are discarded.
// Other parts are written into the array not_length_4.
size_t string_split(
    char *output,
    char not_length_4[10][20],
    const char *input,
    const char *separator
);
