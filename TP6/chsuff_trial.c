//  Utilisation :
//    chsuff_trial SUFF REPL [FILE]...
//
//  Avec un nombre de paramètres strictement inférieur à 2, rappelle la syntaxe.
//  Sinon, pour chacun des FILEs, initialise une chaine de caractères obtenue
//    de FILE en remplaçant son suffixe SUFF par REPL puis affiche FILE, une
//    tabulation, la chaine initialisée et une fin de ligne. Pour tout FILE
//    pour lequel SUFF n'est pas un suffixe, un message mentionnant FILE est
//    envoyé sur la sortie erreur.
//
//  Renvoie EXIT_SUCCESS à l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 100

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Syntax: %s SUFF REPL [FILE]...\n", argv[0]);
    return EXIT_SUCCESS;
  }
  const char * const suff = argv[1];
  const char * const repl = argv[2];
  //  IB : 3 <= k && k <= argc
  //    && les fichiers de nom les chaines pointées par argv[3] à argv[k - 1]
  //        ont été traités
  //  QC : k
  for (int k = 3; k < argc; ++k) {
    char chaine[TAILLE_MAX + 1];
    memcpy(chaine, argv[k], strlen(argv[k]) + strlen(repl) + 1);
    if (!strstr(argv[k], suff)) {
      fprintf(stderr, "%s: Invalid suffix for file '%s'\n", argv[0], argv[k]);
    } else {
      strcat(chaine, repl);
      printf("%s\t%s\n", argv[k], chaine);
    }
  }
  return EXIT_SUCCESS;
}
