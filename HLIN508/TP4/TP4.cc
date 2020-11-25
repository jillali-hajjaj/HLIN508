#include <cstdlib>
#include <iostream>
#include "TP4.h"

using namespace std;

int* RemplirTableau(int& n, int argc, char** argv)
{
  int* T;
  int choix = 0;
  if (argc > 1) {
    n = atoi(argv[1]);
    choix = 2;
  }
  while(choix < 1 || choix > 4)
  {
      cout << "1: exemple fixé\n2: tableau aléatoire\n3: tableau croissant\n4: tableau décroissant\nCHOIX : ";
      cin >> choix;
  }

  if (choix == 1)
  {
      n = 8;
      T = (int *) malloc(n*sizeof(int));
      T[0]=24;T[1]=59;T[2]=85;T[3]=91;
      T[4]=8;T[5]=55;T[6]=91;T[7]= 79;
      return T;
  }

  if (n == 0) {
    cout << "Taille du tableau à générer : ";
    cin >> n;
  }

  T=(int *) malloc(n*sizeof(int));

  switch (choix)
  {
    case 2: 
      for(int i=0; i < n; i++) T[i] = rand() % n;
      break;

    case 3:
      for (int i=0; i < n; i++) T[i] = i;
      break;

    case 4:
      for (int i=0; i < n; i++) T[i] = n-i;
      break;
  }
  return T;
}

void InitialiserTableau(int n, int T[])
{
  for(int i=0;i<n;i++) T[i]=0;
}

void CopierTableau(int n, int T[], int T2[])
{
  for(int i=0;i<n;i++) T2[i]=T[i];
}

void AfficherTableau(int n, int T[])
{
  cout << "[";
  for(int i=0;i<n-1;i++) cout << T[i] << ",";
  cout << T[n-1] << "]" << endl;
}
