#!/usr/bin/env python3
from itertools import count
from os.path import commonprefix
import sys

def remove_common_back(str1, str2):
    prefix_len = len(commonprefix([list(reversed(str1)),
                                   list(reversed(str2))]))
    return str1[:-prefix_len], str2[:-prefix_len]


def remove_common_front(str1, str2):
    prefix_len = len(commonprefix([str1, str2]))
    return str1[prefix_len:], str2[prefix_len:]

any_difference = False
too_many_differences = False
for filename in ("file1.c", "file2.c", "file3.c", "main.c"):
    with open(filename) as f_new, open("original/" + filename) as f_original:
        for line_new, line_original, n in zip(f_new, f_original, count(0, 1)):
            if line_new != line_original:
                l1, l2 = remove_common_front(line_new, line_original)
                l1, l2 = remove_common_back(l1, l2)
                count_different_characters = max(len(l1), len(l2))
                print("Zeile {} in {} hat {} unterschiedliche(s) Zeichen \n{}{}\n".format(
                    n, filename, count_different_characters, line_new, line_original))
                if not any_difference and count_different_characters == 1:
                    any_difference = True
                else:
                    too_many_differences = True

sys.exit(0 if not too_many_differences else 1)
