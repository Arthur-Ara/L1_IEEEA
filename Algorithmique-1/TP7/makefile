CC = gcc
CFLAGS = -std=c2x \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2
executables = \
  cpbleep_alphaordigit \
  chbleep_alphaordigit \
  numberlines

.PHONY: all clean dist

all : $(executables)

clean:
	$(RM) $(executables)

dist: clean
	zip "$(CURDIR).zip" *.c makefile
