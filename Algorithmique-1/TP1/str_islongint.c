#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define MAX_LENGTH 32
#define MAX_LENGTH_SCANF "32"

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
      } else {
        printf("%ld\t%s\tvalue = %ld\n", n, s, x);
      }
    } else {
      printf("%ld\t%s\tillegal value\n", n, s);
    }
  }
  return EXIT_SUCCESS;
}
