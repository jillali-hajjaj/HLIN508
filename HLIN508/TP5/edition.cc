#include <iostream>
#include <string>
#include <algorithm>
#include "matrice.h"

using namespace std;

int valeur(int **E, int i, int j)
{
  if (i >= 0 && j >= 0)
    return E[i][j];

  if (j == -1)
    return (i + 1);
  if (i == -1)
    return (j + 1);
}

int min(int a, int b, int c)
{
  return min(min(a, b), c);
}

int distanceEdition(string s1, string s2, int **E)
{
  int m = s1.size();
  int n = s2.size();
  int e;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (s1[i] == s2[j])
        e = 0;
      else
        e = 1;

      E[i][j] = min(valeur(E, i - 1, j) + 1, valeur(E, i, j - 1) + 1, valeur(E, i - 1, j - 1) + e);
    }
  }

  return E[m - 1][n - 1];
}

string alignement(string &s1, string &s2, int **E)
{
  int i = s1.size() - 1;
  int j = s2.size() - 1;
  string aligne = "";

  int o = 0;

  while (i >= 0 && j >= 0)
  {

    if (valeur(E, i, j) == valeur(E, i - 1, j - 1) && s1[i] == s2[j])
    {

      i = i - 1;
      j = j - 1;

      ++o;
    }
    else if (valeur(E, i, j) == (valeur(E, i - 1, j - 1) + 1))
    {

      i = i - 1;
      j = j - 1;

      ++o;
    }
    else if (valeur(E, i, j) == (valeur(E, i - 1, j) + 1))
    {

      i = i - 1;
      s2.insert(j + 1, "_");

      ++o;
    }
    else if (valeur(E, i, j) == (valeur(E, i, j - 1) + 1))
    {

      j = j - 1;
      s1.insert(i + 1, "_");

      ++o;
    }
  }

  while (i >= 0)
  {
    s2.insert(0, "_");
    i = i - 1;
  }
  while (j >= 0)
  {
    s1.insert(0, "_");
    j = j - 1;
  }

  // A compléter
  // utiliser la méthode insert: ce qui peut être utile:
  // aligne.insert(i,"a"): insert le caractère "a" à la ième position de align
  // aligne.insert(i,x,"a"): insert x fois le caractere "a" à la ième
  //                         position de align

  return aligne;
}

int main(int argc, char **argv)
{

  string s1, s2;
  int **E;
  if (argc < 3)
  {
    cout << "Entrer la première chaîne de caractère : ";
    getline(cin, s1);
    cout << "Entrer la seconde chaîne de caractère : ";
    getline(cin, s2);
  }
  else
  {
    s1 = argv[1];
    s2 = argv[2];
  }

  E = matrice<int>(s1.size(), s2.size());
  int d = distanceEdition(s1, s2, E);
  cout << d << endl;

  // Décommenter si besoin, pour débugguer :
  //afficheMatrice(s1.size(), s2.size(), E);

  string aligne = alignement(s1, s2, E);
  cout << s1 << endl
       << aligne << endl
       << s2 << endl;

  delete E;
  return 0;
}