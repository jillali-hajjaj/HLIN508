#include "TP4.h"

static int npivot = 0;

enum pivot
{
  FIXE,
  REPET,
  ALEATOIRE
};

int choixPivot(int n, int T[], pivot P)
{
  switch (P)
  {
  case FIXE:
    npivot++;
    return 0;
    break;
  case REPET:
    int ni, ns, p;
    ni = n;
    ns = n;
    while ((ni > (3 * n) / 4) || (ns > (3 * n) / 4))
    {
      p = rand() % n;
      npivot++;
      ni = 0;
      ns = 0;
      for (int i = 0; i < n; i++)
      {
        if (T[i] < T[p])
        {
          ni++;
        }
        if (T[i] > T[p])
        {
          ns++;
        }
      }
    }
    return p;
    break;
  case ALEATOIRE:
    npivot++;
    return rand() % n;
    break;
  }
}

int rang(int k, int n, int T[], pivot P)
{
  if (n == 1)
    return T[0];
  int p = choixPivot(n, T, P);
  int ninf = 0, neq = 0;
  int r; // résultat renvoyé
  int nsup;
  // A compléter : calcul de ninf et neq
  for (int i = 0; i < n; i++)
  {
    if (T[i] < T[p])
    {
      ninf++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (T[i] == T[p])
    {
      neq++;
    }
  }

  if (ninf >= k)
  {
    int *Tinf = (int *)malloc(ninf * sizeof(int));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
      if (T[i] < T[p])
      {
        Tinf[c] = T[i];
        c++;
      }
    }

    r = rang(k, ninf, Tinf, FIXE);

    free(Tinf);
    return r;
  }

  else if (ninf + neq >= k)
  {

    r = p;

    return r;
  }

  else
  {
    int *Tsup = (int *)malloc((n - ninf - neq) * sizeof(int));
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
      if (T[i] > T[p])
      {
        Tsup[c1] = T[i];
        c1++;
      }
    }
    nsup = n - ninf - neq;

    r = rang(k - ninf - neq, nsup, Tsup, FIXE);

    free(Tsup);
    return r;
  }
}

int main(int argc, char **argv)
{

  srand(time(NULL));
  int n = 0;
  //if (argc > 1) n = atoi(argv[1]);
  int *tab = RemplirTableau(n, argc, argv);

  cout << "Tableau de depart:" << endl;
  AfficherTableau(n, tab);

  int k = 0;
  while (k < 1 || k > n)
  {
    cout << "Rang à calculer (entre 1 et " << n << ") : ";
    cin >> k;
  }

  clock_t avant;
  clock_t apres;

  int r;

  cout << "Nombre de rang " << k << " :" << endl;
  cout << "  pivot fixe : ";
  npivot = 0;
  avant = clock();
  r = rang(k, n, tab, FIXE);
  apres = clock();
  cout << r << " (nb pivots: " << npivot << ", temps: " << (double)(apres - avant) / CLOCKS_PER_SEC << "s)" << endl;

  cout << "  pivot avec répétition : ";
  npivot = 0;
  avant = clock();
  r = rang(k, n, tab, REPET);
  apres = clock();
  cout << r << " (nb pivots: " << npivot << ", temps: " << (double)(apres - avant) / CLOCKS_PER_SEC << "s)" << endl;

  cout << "  pivot aléatoire : ";
  npivot = 0;
  avant = clock();
  r = rang(k, n, tab, ALEATOIRE);
  apres = clock();
  cout << r << " (nb pivots: " << npivot << ", temps: " << (double)(apres - avant) / CLOCKS_PER_SEC << "s)" << endl;

  free(tab);
}
