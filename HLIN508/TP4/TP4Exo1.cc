#include "TP4.h"
#include <math.h>
void fusion(int n1, int n2, int T1[], int T2[], int T[])
{
  int n = n1 + n2;
  int i1 = 0;
  int i2 = 0;
  int i = 0;

  while (i < n)
  {
    if (i1 == n1 || (T2[i2] < T1[i1] && i2 < n2))
    {
      T[i] = T2[i2];
      i2++;
    }
    else
    {
      T[i] = T1[i1];
      i1++;
    }

    i++;
  }
}

void trifusion(int n, int T[])
{
  if (n > 1)
  {
    int n1 = n / 2;
    int n2 = n - n1;
    int *T1 = (int *)malloc(n1 * sizeof(int));
    int *T2 = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i)
    {
      T1[i] = T[i];
    }

    int tabIndex = n1;
    for (int i = 0; i < n2; ++i)
    {
      T2[i] = T[tabIndex];
      tabIndex++;
    }

    trifusion(n1, T1);
    trifusion(n2, T2);

    fusion(n1, n2, T1, T2, T);

    free(T1);
    free(T2);
  }
}

void tribulles(int n, int T[])
{
  int i, temp;

  do
  {
    temp = 0;

    for (i = 0; i < n - 1; i++)
    {

      if (T[i] > T[i + 1])
      {

        swap(T[i], T[i + 1]);
        temp = 1;
      }
    }
    n--;
  } while (temp);
}

int main(int argc, char **argv)
{

  srand(time(NULL));
  int n = 0;
  if (argc > 1)
    n = atoi(argv[1]);
  int *tab = RemplirTableau(n, argc, argv);
  int *tab2 = (int *)malloc(n * sizeof(int));
  clock_t t1;
  clock_t t2;

  CopierTableau(n, tab, tab2);

  cout << "Tableau de départ : " << endl;
  AfficherTableau(n, tab);

  t1 = clock();
  trifusion(n, tab);
  t2 = clock();
  cout << "Après trifusion (temps : " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s):" << endl;
  AfficherTableau(n, tab);

  t1 = clock();
  tribulles(n, tab2);
  t2 = clock();
  cout << "Apres tribulles (temps : " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s):" << endl;
  AfficherTableau(n, tab2);

  free(tab);
  free(tab2);
}
