#include <stdlib.h>
#include <stdio.h>

int main (void) {
  char s[8+1];
  long int n =0;
  while( scanf("%s", s) == 1) {
    n++;
    printf("%ld\t%s\n", n, s);
  }
  return EXIT_SUCCESS;
}
