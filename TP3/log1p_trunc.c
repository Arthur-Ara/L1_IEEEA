//  Pour toutes les valeurs flottantes x lues sur l'entrée standard,
//    affiche sur la sortie standard,
//    pour la fonction f : x --> ln(1 + x),
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

//  log1p_trunc : renvoie la troncature à l'ordre n
//    du développement en série au voisinage de 0
//    de la fonction x --> ln(1 + x).
//  AE : aucune
//  AS : log1p_trunc(x, n) == somme((-1)^(j+1) * x^j / j ; j == 1 ... n)
double log1p_trunc(double x, int n);

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
    //  IB : 0 <= k && k <= N_MAX + 1
    //    && les lignes avec les troncatures en x de 0 à k - 1 ont été affichées
    //        conformément à la spécification
    //  QC : k
    for (int k = 0; k <= N_MAX; ++k) {
      printf("%" PRI_FLT "\t%d\n", log1p_trunc(x, k), k);
    }
    printf("%" PRI_FLT "\n", log1p(x));
  }
  return EXIT_SUCCESS;
}

double log1p_trunc(double x, int n) {
  if (n <= 0) {
    return 0.0;
  }
  int k = 1;
  double t = x;
  double s = t;
  //  IB : 1 <= k && k <= n
  //    && t == (-1)^(k+1) * x^k
  //    && s == somme((-1)^(j+1) * x^j / j ; j == 1 ... k)
  //  QC : k
  while (k < n) {
    k += 1;
    t *= -x;
    s += t / k;
  }
  return s;
}
