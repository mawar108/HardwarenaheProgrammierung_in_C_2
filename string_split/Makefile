name=string_split
CFLAGS=-g -fsanitize=address -fsanitize=undefined -Wall -Wextra -Werror -std=c99 `pkg-config --cflags check`
LFLAGS=`pkg-config --libs check`

.PHONY: all
all: tests

$(name)_tests.c: $(name)_tests.ts
	checkmk $(name)_tests.ts > $(name)_tests.c

tests: $(name).c $(name).h $(name)_tests.c
	gcc $(CFLAGS) $(name).c $(name)_tests.c -o tests $(LFLAGS)

run: tests
	./tests

.PHONY: clean
clean:
	rm -f $(name)_tests.c tests
