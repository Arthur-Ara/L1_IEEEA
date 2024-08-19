//  Pour toutes les valeurs flottantes x lues sur l'entrée standard,
//    affiche sur la sortie standard,
//    pour la fonction f : x --> atan(x),
//    les troncatures à l'ordre 2n+1
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

//  atan_truc : renvoie la troncature à l'ordre n
//    du développement en série au voisinage de 0
//    de la fonction x --> ln(1 + x).
//  AE : n >= 0
//  AS : atan_truc(x, n) == somme((-1)^j * x^(2*j+1) / 2*j+1 ; j == 0 ... n)
double atan_truc(double x, int n);

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
    //  IB : 0 <= k && k <= N_MAX && s = somme((-1)^j * x^(2*j+1) / 2*j+1)
    //    && t = (-1)^k * x^(2*k+1)
    //    && les lignes avec les troncatures en x de 0 à k - 1 ont été affichées
    //        conformément à la spécification
    //  QC : k
    for (int k = 0; k <= N_MAX; ++k) {
      printf("%" PRI_FLT "\t%d\n", atan_truc(x, k), k);
    }
    printf("%" PRI_FLT "\n", atan(x));
  }
  return EXIT_SUCCESS;
}

double atan_truc(double x, int n) {
  if (n <= 0) {
    return 0.0;
  }
  int k = 0;
  double t = x;
  double s = t;
  //  IB : 0 <= k && k <= n
  //    && t == (-1)^(2*k+1)
  //    && s == somme((-1)^(j+1) * x^j / j ; j == 1 ... k)
  //  QC : k
  while (k < n) {
    k += 1;
    t *= -x * x;
    s += t / (2 * k + 1);
  }
  return s;
}
