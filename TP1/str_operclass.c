#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX_LENGTH 32
#define MAX_LENGTH_SCANF "32"

#define AND "AND"
#define MUL "MUL"
#define END "END"

int main(void) {
  long int n = 0;
  char s[MAX_LENGTH + 1];
  while (scanf("%" MAX_LENGTH_SCANF "s", s) == 1) {
    ++n;
    char *end;
    errno = 0;
    long int x = strtol(s, &end, 10);
    if (*end == '\0') {
      if (errno != 0) {
        printf("%ld\t%s\tvalue out of range\n", n, s);
        return EXIT_FAILURE;
      }
      printf("%ld\t%s\toperand = %ld\n", n, s, x);
    } else {
      if (strcmp(s, AND) != 0
          && strcmp(s, MUL) != 0
          && strcmp(s, END) != 0) {
        printf("%ld\t%s\trejected form\n", n, s);
        return EXIT_FAILURE;
      }
      printf("%ld\t%s\toperator\n", n, s);
    }
  }
  return EXIT_SUCCESS;
}

