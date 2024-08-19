//  str : String utilities. Un module sur les chaines de caractères réimplantant
//    certaines fonctions de la bibliothèque standard et en proposant d'autres.

#ifndef STR__H
#define STR__H

#include <stddef.h>

//  str_chr, str_pbrk, str_rchr, str_spn : mêmes spécifications que les
//    fonctions strchr, strpbrk, strrchr, strspn, déclarées dans l'en-tête
//    standard <string.h>.

extern char *str_chr(const char *s, int c);
extern char *str_pbrk(const char *s1, const char *s2);
extern char *str_rchr(const char *s, int c);
extern size_t str_spn(const char *s1, const char *s2);

//  str_convert : substitue à chacun des caractères de la chaine pointée par s
//    sa conversion (forcée en char) par charconvert. La fonction pointée par
//    charconvert peut par exemple être l'une des deux fonctions to... de
//    l'en-tête standard <ctype.h>. Renvoie s.
extern char *str_convert(char *s, int (*charconvert)(int));

//  str_lowercasing : remplace chacune des lettres capitales de la chaine
//    pointée par s par les lettres minuscules associées. Renvoie s.
extern char *str_lowercasing(char *s);

//  str_uppercasing : remplace chacune des lettres minuscules de la chaine
//   pointée par s par les lettres capitales associées. Renvoie s.
extern char *str_uppercasing(char *s);

//  str_bleep : substitue bleep (forcé en char) à chacun des caractères de la
//    chaine pointée par s satisfaisant charcond. La fonction pointée par
//    charcond peut par exemple être l'une des douze fonctions is... de
//    l'en-tête standard <ctype.h>. Renvoie s.
extern char *str_bleep(char *s, int bleep, int (*charcond)(int));

#endif
