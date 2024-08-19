#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define HEIGHT_MAX 4
#define MAX_LENGTH 32
#define MAX_LENGTH_SCANF "32"

#define ADD "ADD"
#define MUL "MUL"
#define END "END"
#define SUB "SUB"
#define QUO "QUO"
#define REM "REM"

int main(void) {
  char s[MAX_LENGTH + 1];
  long int p[HEIGHT_MAX];
  int h = 0;
  while (scanf("%" MAX_LENGTH_SCANF "s", s) == 1) {
    char *end;
    errno = 0;
    long int x = strtol(s, &end, 10);
    if (*end == '\0') {
      if (errno != 0) {
        printf("Value out of range\n");
        return EXIT_FAILURE;
      }
      if (h == HEIGHT_MAX) {
        printf("Stack overflow\n");
        return EXIT_FAILURE;
      }
      p[h] = x;
      ++h;
    } else {
      if (strcmp(s, ADD) != 0
          && strcmp(s, MUL) != 0
          && strcmp(s, END) != 0
          && strcmp(s, SUB) != 0
          && strcmp(s, QUO) != 0
          && strcmp(s, REM) != 0) {
        printf("Rejected form\n");
        return EXIT_FAILURE;
      }
      if (strcmp(s, END) == 0) {
        if (h != 1) {
          printf("Missplaced Oparator\n");
          return EXIT_FAILURE;
        }
        --h;
        printf("Result : %ld\n", p[h]);
      } else if (strcmp(s, ADD) == 0) {
        if (h <= 1) {
          printf("Stack underflow\n");
          return EXIT_FAILURE;
        }
        long int c = p[h - 1] + p[h - 2];
        h = h - 1;
        p[h - 1] = c;
      } else if (strcmp(s, MUL) == 0) {
        if (h <= 1) {
          printf("Stack underflow\n");
          return EXIT_FAILURE;
        }
        long int c = p[h - 1] * p[h - 2];
        h = h - 1;
        p[h - 1] = c;
      } else if (strcmp(s, SUB) == 0) {
        if (h <= 1) {
          printf("Stack underflow\n");
          return EXIT_FAILURE;
        }
        long int c = p[h - 2] - p[h - 1];
        h = h - 1;
        p[h - 1] = c;
      } else if (strcmp(s, QUO) == 0) {
        if (h <= 1) {
          printf("Stack underflow\n");
          return EXIT_FAILURE;
        }
        long int c = p[h - 2] / p[h - 1];
        h = h - 1;
        p[h - 1] = c;
      } else if (strcmp(s, REM) == 0) {
        if (h <= 1) {
          printf("Stack underflow\n");
          return EXIT_FAILURE;
        }
        long int c = p[h - 2] % p[h - 1];
        h = h - 1;
        p[h - 1] = c;
      }
    }
  }
  return EXIT_SUCCESS;
}
