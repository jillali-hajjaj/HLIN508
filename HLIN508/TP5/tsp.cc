#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include <algorithm>

#include "ensembles.h"
#include "matrice.h"
#include "points.h"

using namespace std;

float distance(coord* P, int i, int j)
{
  // A compléter
}

float tsp(int n, coord* P, float** D, int** Prec, int& min)
{
  D[vide()][n-1] = 0;

  for (int s = 1; s < n; s++)
  {
    ensemble U = plein(s);
    while (U)
    {
      D[U][n-1] = FLT_MAX;

      // A compléter

      U = suivant(U, n-1, s);
    }
  }


  float res = FLT_MAX;

  // A compléter

  return res;
}

void tsp_rec(int* circuit, int n, float** D, int** Prec, int min)
{
  // A compléter
}

float tsp_bruteforce(int n, coord* P)
{
  // A compléter
}

int main(int argc, char** argv)
{
  
  int n;
  if (argc > 1) n = atoi(argv[1]);
  else {
    cout << "Entrer un nombre de point, ou 0 pour l'exemple fixé : ";
    cin >> n;
  }

  coord* P;

  if (n == 0) {
    n = 5;
    P = new coord[n];
    int i = 0;
    P[i].x = 601; P[i].y = 423; i++;
    P[i].x = 474; P[i].y = 600; i++;
    P[i].x = 490; P[i].y = 397; i++;
    P[i].x = 529; P[i].y = 34;  i++;
    P[i].x = 45;  P[i].y = 365; i++;
  }
  else {
    srand(time(NULL));
    P = new coord[n];
    pointsAleatoires(n, P);
  }
    
  cout << n << " points : "; 
  affichePoints(n, P);
  
  float** D = matrice<float>(1 + plein(n-1), n);
  int** Prec = matrice<int>(1 + plein(n-1), n);
  int min;

  float d = tsp(n, P, D, Prec, min);

  cout << "Longueur du circuit le plus court : " << d << endl;

  dessinPoints(n, P);

  int* circuit = new int[n];
  for(int i=0; i < n; i++) circuit[i] = i; // pour éviter le segfault quand algos non implémentés
  tsp_rec(circuit, n, D, Prec, min);

  cout << "Circuit le plus court : ";
  for (int i=0; i < n; i++)
    cout << circuit[i] << " → ";
  cout << circuit[0] << endl;

  dessinTsp(n, P, circuit);

  if (n <= 5) {
    cout << endl;
    afficheMatrice(n, 1<<(n-1), D);
  }

  // Comparaison ProgDyn et Force brute
  
  // A décommenter pour la question bonus
  

  /*
  clock_t t1, t2, t3;

  t1 = clock();
  float d1 = tsp(n, P, D, Prec, min);
  t2 = clock();
  float d2 = tsp_bruteforce(n, P);
  t3 = clock();

  cout << endl;
  cout << "Comparaison des algos :" << endl;
  cout << "  Valeurs renvoyées : " << d1 << " & " << d2 << endl;
  cout << "  Temps de calcul : " << (double)(t2-t1)/CLOCKS_PER_SEC << "s & " << (double)(t3-t2)/CLOCKS_PER_SEC << "s" <<endl;

  */

  delete P, D, Prec, circuit;

  return 0;
}
