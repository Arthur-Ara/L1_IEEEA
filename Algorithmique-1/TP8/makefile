CC = gcc
CFLAGS = -std=c2x \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings \
  -O2
objects = main.o str.o
executable = str

.PHONY: all clean dist

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

dist: clean
	zip "$(CURDIR).zip" *.c *.h makefile

$(executable): $(objects)
	$(CC) $(objects) -o $(executable)

main.o: main.c str.h
str.o: str.c str.h
