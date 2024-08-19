//  Syntaxe : numberlines [FILE]...
//
//  Affiche sur la sortie standard le contenu des fichiers textes FILEs en
//    numérotant leurs lignes. Pour chaque FILE, la numérotation des lignes
//    commence à 1. L'affichage du numéro d'une ligne se fait sur une largeur
//    minimale de champ égale à 6 et avec une justification à droite. Les
//    affichages du numéro d'une ligne et son contenu sont séparés par une
//    tabulation. Si FILE n'est pas vide et que son dernier caractère n'est pas
//    la fin de ligne, affiche une fin de ligne après ce dernier caractère.
//    L'affichage du contenu de tout FILE est précédé de celui d'une tabulation,
//    de FILE et d'une fin de ligne. Tous les FILEs sont traités. Si, lors du
//    traitement d'un FILE, une erreur survient sur FILE ou sur la sortie
//    standard, un message d'erreur est envoyé sur la sortie erreur.
//
//  Renvoie EXIT_SUCCESS à l'environnement d'exécution si aucune erreur n'est
//    survenue. Renvoie EXIT_FAILURE sinon.

#include <stdio.h>
#include <stdlib.h>

//  numberlines : affiche sur la sortie standard la chaine de caractères pointée
//    par filename puis le contenu du fichier texte désigné par filename
//    conformément au format spécifié ci-dessus. Renvoie zéro si aucune erreur
//    n'est survenue, une valeur non nulle sinon.
int numberlines(const char *filename);

int main(int argc, char *argv[]) {
  int r = EXIT_SUCCESS;
  //  IB : 1 <= k && k <= argc
  //    && les fichiers de nom les chaines pointées par argv[1] à argv[k - 1]
  //        ont été traités
  //    && r == (aucune erreur n'est survenue ? EXIT_SUCCESS : EXIT_FAILURE)
  //  QC : k
  for (int k = 1; k < argc; ++k) {
    const char * const a = argv[k];
    if (numberlines(a) != 0) {
      fprintf(stderr, "An error occurred while processing '%s'\n", a);
      r = EXIT_FAILURE;
    }
  }
  return r;
}

int numberlines(const char *filename) {
  FILE *file = fopen(filename, "r");
  printf("\t%s\n", filename);
  if (file == NULL) {
    fclose(file);
    return -1;
  }

  int rg = fgetc(file);
  int i = 1;
  if (rg == EOF) {
    goto closing;
  }
  printf("%d\t", i);
  while (rg != EOF) {
    if (rg != '\n'){
      printf("%c", rg);
      rg = fgetc(file);
    } else {
      i++;
      printf("\n%d\t", i);
      rg = fgetc(file);
    }
  }
  printf("\n");

  if(!feof(file)) {
    fclose(file);
    return -1;
  }

  closing:
  if (fclose(file) != 0) {
    return -1;
  }
  return 0;
}
