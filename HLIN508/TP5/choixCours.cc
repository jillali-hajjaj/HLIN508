#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm> // std::max
using namespace std;

//--------Structure pour stocker les cours-----------

typedef struct
{
  int deb;
  int fin;
  int val;
} crs;

//--------Generation des cours-----------

crs *GenererCours(int &n)
{
  int choix = 0;
  crs *cours;
  while (choix != 1 && choix != 2)
  {
    cout << "Tapez 1 pour remplir avec un exemple fixé, 2 pour générer aléatoirement:\n";
    cin >> choix;
  }
  switch (choix)
  {
  case 1:
    n = 8;
    cours = new crs[8];
    cours[0] = {76, 78, 10};
    cours[1] = {12, 17, 2};
    cours[2] = {13, 15, 1};
    cours[3] = {19, 28, 8};
    cours[4] = {12, 20, 7};
    cours[5] = {44, 45, 9};
    cours[6] = {43, 45, 5};
    cours[7] = {1, 8, 3};
    cours[8] = {68, 78, 6};
    cours[9] = {85, 88, 7};
    break;
  case 2:
    cout << "Nombre de cours: ";
    cin >> n;
    cours = new crs[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
      cours[i].deb = rand() % 90 + 1;
      cours[i].fin = cours[i].deb + rand() % 10 + 1;
      cours[i].val = rand() % 9 + 1;
    }
    break;
  default:
    cout << "Pas compris, reessayer...\n";
  }
  return cours;
}

//--------Initialisation de tableaux-----------

void InitialisationTab(int n, int tab[], int v)
{
  for (int i = 0; i < n; i++)
  {
    tab[i] = v;
  }
}

//--------Affichage des cours-----------

void AfficherCours(int n, crs cours[])
{
  for (int i = 0; i < n; i++)
  {
    cout << "[" << cours[i].deb << "," << cours[i].fin << ","
         << cours[i].val << "] ";
  }
  cout << endl;
}

//--------Tri des cours-----------

void TrierCours(int n, crs cours[])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (cours[i].fin > cours[j].fin)
      {
        swap(cours[i], cours[j]);
      }
    }
  }
}

//-----Calcul du cours precedent compatible avec fin max----
int compatibilite(int n, crs cours[], crs c1)
{
  for (int i = 0; i < n; i++)
  {
    if (c1.deb > cours[i].fin)
    {
      return i;
    }
  }
  return -1;
}
void CalculDernierPred(int n, crs cours[], int predMax[])
{
  TrierCours(n, cours);
  for (int i = 0; i < n; i++)
  {
    predMax[i] = compatibilite(n, cours, cours[i]);
  }
}

//--------Choix max en prog dyn-----------

void choixMaxProgD(int n, crs cours[], int predMax[], int crsMax[])
{
  TrierCours(n, cours);

  for (int k = 0; k < n; k++)
  {
    for (int j = 0; j < k; j++)
    {
      if (cours[j].fin <= cours[k].deb)
      {
        predMax[k] = j;
      }
    }
  }

  crsMax[0] = cours[0].val;

  for (int k = 0; k < n; k++)
  {
    if (predMax[k] != -1)
    {
      crsMax[k] = max(crsMax[k], cours[k].val + crsMax[predMax[k]]);
    }
    else
      crsMax[k] = max(crsMax[k], cours[k].val);
  }
}
//--------Choix max en recursif-----------

int choixMaxRec(crs cours[], int predMax[], int k)
{
  if (k == -1)
  {
    return 0;
  }
  else
  {
    return cours[k].val + choixMaxRec(cours, predMax, predMax[k]);
  }
}

//--------Choix max en prog dyn avec solution-----------

void choixMaxProgDSol(int n, crs cours[], int predMax[], int crsMax[], int sol[])
{
  choixMaxProgD(n, cours, predMax, crsMax);
  sol[0] = 1;
  for (int i = 1; i < n; i++)
  {
    if (crsMax[i - 1] < crsMax[i])
    {
      sol[i] = 1;
    }
    else
    {
      sol[i] = 0;
    }
  }
}

//--------Reconstruction de la solution-----------

void ChoixCours(int n, int predMax[], int sol[], int choix[])
{
  for (int i = 0; i < n; i++)
  {
    choix[i] = 0;
  }
  int i = n - 1;
  while (i >= 0)
  {
    if (sol[i] == 1)
    {
      choix[i] = 1;
      i = predMax[i];
    }
    else
    {
      i--;
    }
  }
}

//--------Main-----------

int main()
{
  int n;
  crs *cours;
  cours = GenererCours(n);

  clock_t t1, t2;

  cout << endl;
  cout << "Cours non tries:\n";
  AfficherCours(n, cours);
  cout << endl;

  TrierCours(n, cours);
  cout << "Cours tries par dates de fin croissantes:\n";
  AfficherCours(n, cours);
  cout << endl;

  int predMax[n];
  InitialisationTab(n, predMax, -1);

  CalculDernierPred(n, cours, predMax);
  cout << "Calcul de predMax:\n";
  for (int i = 0; i < n; i++)
  {
    cout << "predMax[" << i << "]=" << predMax[i] << " ";
  }
  cout << endl;
  cout << endl;

  int crsMax[n];
  InitialisationTab(n, crsMax, 0);

  t1 = clock();
  choixMaxProgD(n, cours, predMax, crsMax);
  t2 = clock();
  cout << "Valeur d'un choix optimal de cours (en progdyn):" << crsMax[n - 1];
  cout << "  (tps de calcul: " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s)" << endl;
  cout << endl;
  cout << endl;

  t1 = clock();
  cout << "Valeur d'un choix optimal de cours (en recursif): " << choixMaxRec(cours, predMax, n - 1);
  t2 = clock();
  cout << "  (tps de calcul: " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s)" << endl;

  int sol[n];
  int choix[n];
  InitialisationTab(n, sol, 0);
  InitialisationTab(n, choix, 0);

  choixMaxProgDSol(n, cours, predMax, crsMax, sol);
  cout << endl;
  cout << "Tableau d'appartenance a une solution locale max:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "sol[" << i << "]=" << sol[i] << " ";
  }
  cout << endl;

  ChoixCours(n, predMax, sol, choix);

  cout << endl;
  cout << "Une solution optimale:" << endl;

  int valtot = 0;
  for (int i = 0; i < n; i++)
  {
    if (choix[i] == 1)
    {
      cout << "[" << cours[i].deb << "," << cours[i].fin << "," << cours[i].val << "] ";
      valtot += cours[i].val;
    }
  }
  cout << endl;
  cout << "Valeur de cette solution: " << valtot << endl;
}
