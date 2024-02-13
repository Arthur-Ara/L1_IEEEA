//  Pour toutes les valeurs flottantes x lues sur l'entrée standard,
//    affiche sur la sortie standard,
//    pour la fonction f : x --> sinh(x),
//    les troncatures à l'ordre n
//    de son développement en série au voisinage de 0,
//    pour n allant de 0 à 9,
//    puis f(x).
//  L'affichage de chacune des troncatures est suivi d'une tabulation et de
//    l'affichage de n. Les troncatures et la valeur f(x) sont affichées sur des
//    lignes séparées. Chacune des valeurs flottantes est affichée sur une
//    largeur (minimale) de 13 caractères et avec une précision de 10 décimales.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//  sinh_trunc : renvoie la troncature à l'ordre n
//    du développement en série au voisinage de 0
//    de la fonction x --> sinh(x).
//  AE : n >= 0
//  AS : sinh_trunc(x, n) == somme(x^(2*j + 1) / (2*j + 1)! ; j == 0 ... n)
double sinh_trunc(double x, int n);

#define N_MAX 9

#define PRI_FLT "13.10lf"

int main(void) {
  double x;
  //  IB : pour toutes les valeurs lues sur l'entrée standard, sans compter la
  //        dernière valeur lue si la valeur renvoyée par le dernier appel à
  //        scanf égale 1, les lignes avec les troncatures et l'image en ces
  //        valeurs ont été affichées conformément à la spécification
  //    && x == dernière valeur lue sur l'entrée standard si la valeur renvoyée
  //        par le dernier appel à scanf égale 1
  //  QC : nombre d'appels à scanf
  while (scanf("%lf", &x) == 1) {
    //  IB : 0 <= k && k <= N_MAX && s == somme(x^(2*j + 1) / (2*j + 1)!) && t == x^(2*k + 1) / (2*k + 1)!
    //    && les lignes avec les troncatures en x de 0 à k - 1 ont été affichées
    //        conformément à la spécification
    //  QC : k
    for (int k = 0; k <= N_MAX; ++k) {
      printf("%" PRI_FLT "\t%d\n", sinh_trunc(x, k), k);
    }
    printf("%" PRI_FLT "\n", sinh(x));
  }
  return EXIT_SUCCESS;
}

double sinh_trunc(double x, int n) {
  if (n <= 0) {
    return x;
  }
  double t = x;
  double s = t;
  //  IB : 1 <= k && k <= n
  //    && t == x^(2 * k + 1) / (2 * k + 1)!
  //    && s == somme(x^(2 * j + 1) / (2 * j + 1)! ; j == 0 ... k)
  //  QC : k
  for (int k = 1; k <= n; ++k) {
    t *= x * x / ((2 * k) * (2 * k + 1));
    s += t;
  }
  return s;
}
