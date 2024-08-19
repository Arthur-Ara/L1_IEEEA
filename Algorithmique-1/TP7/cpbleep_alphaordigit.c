//  Syntaxe :
//    cpbleep_alphaordigit BLEEP CLASS SRC DEST
//
//  Crée le fichier texte DEST en lui donnant comme contenu celui du fichier
//    texte SRC mais en substituant le caractère BLEEP aux caractères de la
//    catégorie CLASS. Les valeurs possibles pour CLASS sont "alpha" ou "digit".
//
//  Renvoie EXIT_SUCCESS à l'environnement d'exécution si aucune erreur n'est
//    survenue. Renvoie EXIT_FAILURE sinon, en particulier parce que DEST
//    existait déjà.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  fail_if : si expr ne vaut pas zéro, affiche le message msg sur la sortie
//    erreur et termine le programme en renvoyant EXIT_FAILURE à l'environnement
//    d'exécution.
void fail_if(int expr, const char *msg, const char *progn);

//  cpbleep : crée le fichier texte de nom la chaine pointée par destfn en lui
//    donnant comme contenu celui du fichier texte de nom la chaine pointée par
//    srcfn mais en substituant le caractère bleep aux caractères satisfaisant
//    la condition charcond. Renvoie zéro en cas de succès, une valeur non nulle
//    en cas d'échec.
int cpbleep(const char *destfn, const char *srcfn, int bleep,
    int (*charcond)(int));

// utils : Fonction essayant d'écrire dans file. Elle écrit bleep si charcond(c)
//    sinon c.
//    Elle renvoie 0 si l'écriture a réussi sinon renvoie -1.
//    Elle prend en paramètre le caractère lu par fgetc, bleep, le pointeur vers
//    la fonction charcond et le fichier à modifier.
int utils(int c, int bleep, int (*charcond)(int), FILE *file);

int main(int argc, char *argv[]) {
  enum {
    PROGN_IDX,
    BLEEP_IDX,
    CLASS_IDX,
    SRC_IDX,
    DEST_IDX,
    EXPECTED_ARGC
  };
  fail_if(argc != EXPECTED_ARGC, "Bad number of arguments", argv[0]);
  fail_if(strlen(argv[BLEEP_IDX]) != 1, "Invalid BLEEP argument", argv[0]);
  int (*charcond)(int) = NULL;
  if (strcmp(argv[CLASS_IDX], "alpha") == 0) {
    charcond = isalpha;
  } else if (strcmp(argv[CLASS_IDX], "digit") == 0) {
    charcond = isdigit;
  }
  fail_if(charcond == NULL, "Invalid CLASS argument", argv[0]);
  fail_if(
      cpbleep(argv[DEST_IDX], argv[SRC_IDX], *argv[BLEEP_IDX], charcond) != 0,
      "An error occurred while processing the files", argv[0]);
  return EXIT_SUCCESS;
}

void fail_if(int expr, const char *msg, const char *progn) {
  if (!expr) {
    return;
  }
  fprintf(stderr, "%s: %s\n", progn, msg);
  exit(EXIT_FAILURE);
}

int utils(int c, int bleep, int (*charcond)(int), FILE *file) {
  if (charcond(c)) {
    c = bleep;
  }
  return fputc(c, file) == EOF ? -1 : 0;
}

int cpbleep(const char *destfn, const char *srcfin, int bleep,
    int (*charcond)(int)) {
  FILE *src = fopen(srcfin, "r");
  if (src == NULL) {
    return -1;
  }
  FILE *dest = fopen(destfn, "w");
  if (dest == NULL) {
    fclose(src);
    return -1;
  }
  int rg = fgetc(src);
  while (rg != EOF && utils(rg, bleep, charcond, dest) == 0) {
    rg = fgetc(src);
  }
  if (!feof(src)) {
    fclose(src);
    fclose(dest);
    return -1;
  }
  if (!fclose(src) || !fclose(dest)) {
    return -1;
  }
  return 0;
}
