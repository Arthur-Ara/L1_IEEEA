#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

#define TRIAL_PTR(fun, text, arg)                                              \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    char *p = fun(text, arg);                                                  \
    if (p == NULL) {                                                           \
      printf("*");                                                             \
    } else {                                                                   \
      printf("%*c", (int) (p - text + 1), '^');                                \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

#define TRIAL_SIZE(fun, text, arg)                                             \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    for (size_t n = fun(text, arg); n > 0; --n) {                              \
      printf(".");                                                             \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

#define TRIAL_STR_0_ARG(fun, text)                                             \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    printf("%s\n", fun(text));                                                 \
  }

#define TRIAL_STR_1_ARG(fun, text, arg)                                        \
  {                                                                            \
    printf("--- " #fun " " #arg "\n");                                         \
    printf("%s\n", text);                                                      \
    printf("%s\n", fun(text, arg));                                            \
  }

#define TRIAL_STR_2_ARG(fun, text, arg1, arg2)                                 \
  {                                                                            \
    printf("--- " #fun " " #arg1 " " #arg2 "\n");                              \
    printf("%s\n", text);                                                      \
    printf("%s\n", fun(text, arg1, arg2));                                     \
  }

#define TEXT "https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2478.pdf"

int main(void) {
  printf("--- Trials on strings utilities\n"
      "--- Utilities prefixed by 'str_' are homemade\n\n");
#if 1
  {
    const char *s = TEXT;
    TRIAL_PTR(strchr, s, 'd');
    TRIAL_PTR(strchr, s, 'a');
    TRIAL_PTR(strchr, s, '\0');
    TRIAL_PTR(strrchr, s, 'd');
    TRIAL_PTR(strrchr, s, 'a');
    TRIAL_PTR(strrchr, s, '\0');
    TRIAL_PTR(strpbrk, s, "-.:/");
    TRIAL_PTR(strpbrk, s, "0123456789");
    TRIAL_PTR(strpbrk, s, "abiklmquvxyz");
    TRIAL_PTR(strpbrk, s, "f");
    TRIAL_PTR(strpbrk, s, "");
    TRIAL_SIZE(strspn, s, "abcdefghijklmnopqrstuvwxyz");
    TRIAL_SIZE(strspn, s, "-.:/");
    TRIAL_SIZE(strspn, s, "-.:/1248cdefghjnoprstw");
    TRIAL_SIZE(strspn, s, "");
  }
#endif
#if 0
  {
    char s[strlen(TEXT) + 1];
    strcpy(s, TEXT);
    TRIAL_STR_1_ARG(str_convert, s, toupper);
    TRIAL_STR_1_ARG(str_convert, s, tolower);
    TRIAL_STR_0_ARG(str_uppercasing, s);
    TRIAL_STR_0_ARG(str_lowercasing, s);
    TRIAL_STR_2_ARG(str_bleep, s, '#', isdigit);
    TRIAL_STR_2_ARG(str_bleep, s, '.', ispunct);
  }
#endif
  return EXIT_SUCCESS;
}
