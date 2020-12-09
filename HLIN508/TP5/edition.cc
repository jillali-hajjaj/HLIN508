#include <iostream>
#include <string>

#include "matrice.h"

using namespace std;

int valeur(int** E, int i, int j)
{
  // A compléter
}

int min(int a, int b, int c)
{
  // A compléter
}

int distanceEdition(string s1, string s2, int** E)
{
  int n1 = s1.size();
  int n2 = s2.size();
  
  // A compléter

  return E[n1-1][n2-1];
}

string alignement(string& s1, string& s2, int** E)
{
  int i = s1.size()-1;
  int j = s2.size()-1;
  string aligne;

  // A compléter
  // utiliser la méthode insert: ce qui peut être utile:
  // aligne.insert(i,"a"): insert le caractère "a" à la ième position de align
  // aligne.insert(i,x,"a"): insert x fois le caractere "a" à la ième
  //                         position de align

  
  return aligne;
}

int main(int argc, char** argv)
{

  string s1, s2;
  int** E;
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
  // afficheMatrice(s1.size(), s2.size(), E);
  
  string aligne = alignement(s1, s2, E);
  cout << s1 << endl << aligne << endl << s2 << endl;

  delete E;
  return 0;
}
