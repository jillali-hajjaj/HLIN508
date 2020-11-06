#include <cstdlib>
#include <iostream>
#include <fstream>
#include "ArbreBinaire.h"
#include "Couples.h"

using namespace std;

#define N 1000

// ====================
//  TAS ET TRI PAR TAS
// ====================

template<typename E>
void AfficherTableau(int n, E T[])
{
  // A compléter
}  

template<typename E>
int RemplitTableau(E T[])
{
  // A compléter
}

void TableauAleatoire(int n, int T[], int m, int M)
{
  // A compléter
}

template<typename E>
void Entasser(int n, E T[], int i)
{
  // A compléter
}

template<typename E>
void Tas(int n, E T[])
{
  // A compléter
}

template<typename E>
void Trier(int n, E T[], E Ttrie[])
{
  // A compléter
}

template<typename E>
void TrierSurPlace(int n, E T[])
{
  // A compléter
}

// ===================
//  FILES DE PRIORITE
// ===================

template<typename E>
void Remonter(int n, E T[], int i)
{
  // A compléter
}

template<typename E>
E Supprimer(int n, E T[], int i)
{
  // A compléter
}
  
void AjoutElem(int n, couple F[], int v, float p)
{
  // A compléter
}

couple ExtraitMax(int n, couple F[])
{
  // A compléter
}

void AugmentePriorite(int n, couple F[], int i, float gain)
{
  // A compléter
}

void DiminuePriorite(int n, couple F[], int i, float perte)
{
  // A compléter
}

// ==================
//  FUSION DE LISTES
// ==================

void Fusion(int k, int n, float T[N][N], float Sortie[])
{
  // A compléter
}

// =======
//  TESTS
// =======

int main()
{

  srand(time(NULL));

// ============================
//  Exo 1 : TAS ET TRI PAR TAS
// ============================

  cout << "===== EXO 1 =====" << endl;

  int T1[N]={7,12,4,8,10,2,1,1,3,9};
  float T2[N]={5.3,1.1,6.8,8.3,2.9,10.0};
  
  // Question 1
/*
  cout << "Tableau T1 [7,12,4,8,10,2,1,1,3,9] : ";
  AfficherTableau(10, T1);
  cout << "Tableau T2 [5.3,1.1,6.8,8.3,2.9,10] : ";
  AfficherTableau(6, T2);
  //dessinTas(10, T1, "T1");
  //affichageGraphique(10,T1,"T1");
  //dessinTas(6, T2, "T2");
  //affichageGraphique(6, T2, "T2");
*/
  
  // Question 2
/*
  int T3[N];
  int s = RemplitTableau(T3);
  cout << "Tableau T3 (vérifier !) : ";
  AfficherTableau(s, T3);
  //dessinTas(s, T3, "T3");
  //affichageGraphique(s, T3, "T3");
*/

  // Question 3
/*
  int T4[N];
  TableauAleatoire(10, T4, 0, 100);
  AfficherTableau(10, T4);
  //dessinTas(10, T4, "T4");
  //affichageGraphique(10, T4, "T4");
*/
  
  // Question 4 
/*
  Entasser(10, T1, 0);
  cout << "Tableau T1 après entassement [12,10,4,8,9,2,1,1,3,7] : ";
  AfficherTableau(10,T1); 
  //dessinTas(10, T1, "T1entasse");
  //affichageGraphique(10, T1, "T1entasse");
*/

  // Question 5
/*
  Tas(6, T2);
  cout << "Tableau T2 après Tas [10,8.3,6.8,1.1,2.9,5.3] : ";
  AfficherTableau(6,T2);
  //dessinTas(6, T2, "T2tas");
  //affichageGraphique(6, T2, "T2tas");
*/

  // Question 6
/*
  int T1tri[N];
  Trier(10, T1, T1tri);
  cout << "Tableau T1tri [1,1,2,3,4,7,8,9,10,12] : ";
  AfficherTableau(10, T1tri);
  //dessinTas(10, T1tri, "T1tri");
  //affichageGraphique(10, T1tri, "T1tri");
*/

  // Question 7
/*
  TrierSurPlace(10, T1);
  cout << "Tableau T1 après tri [1,1,2,3,4,7,8,9,10,12] : ";
  AfficherTableau(10, T1);
  //dessinTas(10, T1, "T1trisurplace");
  //affichageGraphique(10, T1, "T1trisurplace");
*/

// ===========================
//  Exo 2 : FILES DE PRIORITE
// ===========================

  cout << endl<<endl << "===== EXO 2 =====" << endl;
  
  int V[N] = {1,3, 5, 6, 3, 2, 7};
  float P[N] = {.1, .4, .6, .8, .3, .5, .9};
  couple C[N];
  TabCouples(7, C, V, P);
  
  cout << "Tableau C : "; 
  AfficherTableau(7, C);
  //dessinTas(7, C, "C");
  //  affichageGraphique(7, C, "C");
  
  // Question 1
/*
  Remonter(7, C, 3);
  cout << "après Remonter [(6,0.8),(1,0.1),(5,0.6),(3,0.4),(3,0.3),(2,0.5),(7,0.9)] :" << endl
       << "            -> ";
  AfficherTableau(7, C);
  //dessinTas(7, C, "C1");
  //affichageGraphique(7, C, "C1");
*/

  // Question 2
/*
  Supprimer(7, C, 2);
  cout << "après Supprimer [(7,0.9),(1,0.1),(6,0.8),(3,0.4),(3,0.3),(2,0.5)] :" << endl
       << "             -> ";
  AfficherTableau(6, C);
  //dessinTas(6, C, "C2");
  //affichageGraphique(6, C, "C2");
*/

  // Question 3
/*
  Tas(6, C);
  AjoutElem(6, C, 4, 1.);
  cout << "après AjoutElem [(4,1),(3,0.4),(7,0.9),(1,0.1),(3,0.3),(2,0.5),(6,0.8)] :" << endl
       << "             -> ";
  AfficherTableau(7, C);
  //dessinTas(7, C, "C3");
  //affichageGraphique(7, C, "C3");

  couple y = ExtraitMax(7, C);
  cout << "après ExtraitMax [(7,0.9),(3,0.4),(6,0.8),(1,0.1),(3,0.3),(2,0.5)] :" << endl
       << "              -> ";
  AfficherTableau(6, C);
  cout << "    (valeur extraite (4,1) : " << y << ")" << endl;
  //dessinTas(6, C, "C3bis")
  //affichageGraphique(6, C, "C3bis");
*/
  
  // Question 4
/*
  AugmentePriorite(6, C, 4, .5);
  DiminuePriorite(6, C, 2, .2);
  cout << "après changement priorité [(7,0.9),(3,0.8),(6,0.6),(1,0.1),(3,0.4),(2,0.5)] :" << endl
       << "                       -> ";
  AfficherTableau(6, C);
  //dessinTas(6, C, "C4");
  //affichageGraphique(6, C, "C4");
*/

// ================
//  Exo 3 : FUSION
// ================

  cout << endl<<endl << "===== EXO 3 =====" << endl;

  float T[N][N];
  int Tint[N][N];

/*
  int K;
  int n;
  cout << "Entrer le nombre de listes : ";
  cin >> K;
  cout << "Entrer la taille des listes : ";
  cin >> n;
  cout << "Listes à fusionner :" << endl;
  for (int k = 0; k < K; k++) {
    TableauAleatoire(n, Tint[k], 0, 10000);
    for (int i=0; i < n; i++) T[k][i] = float(Tint[k][i]);
    TrierSurPlace(n, T[k]);
    cout << "  ";
    AfficherTableau(n, T[k]);
  }

  float F[N];
  Fusion(K, n, T, F);
  cout << "Liste fusionnée : "; 
  AfficherTableau(n*K, F);
*/

}
