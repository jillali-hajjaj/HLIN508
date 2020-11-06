#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include "ArbreBinaire.h"

using namespace std;

//------------------------------------------------------
// Inserer un noeud z dans l'arbre A
//------------------------------------------------------

void inserer(ArbreBinaire *A, noeud *z)
{
  noeud *x = A->racine;
  noeud *p = NULL;
  while (x != NULL)
  {
    p = x;
    if (z->val < x->val)
    {
      x = x->filsG;
    }
    else
    {
      x = x->filsD;
    }
  }
  z->pere = p;
  if (p == NULL)
    A->racine = z;
  else
  {
    if (z->val < p->val)
      p->filsG = z;
    else
      p->filsD = z;
  }
}

//------------------------------------------------------
// Parcours infixe
//------------------------------------------------------

void parcoursInfixe(noeud *x)
{
  if (x != NULL)
  {
    parcoursInfixe(x->filsG);
    cout << x->val << endl;
    parcoursInfixe(x->filsD);
  }
}

//------------------------------------------------------
// Noeud de valeur minimale dans l'arbre
//------------------------------------------------------

noeud *minArbre(noeud *x)
{
  while (x->filsG != NULL)
  {
    x = x->filsG;
  }
  return x;
}

//------------------------------------------------------
// Recherche d'un noeud de valeur k
//------------------------------------------------------

noeud *recherche(ArbreBinaire *arbre, int k)
{
  if (arbre->racine == NULL)
    return NULL;
  if (arbre->racine->val == k)
  {
    return arbre->racine;
  }
  if (arbre->racine->val > k)
  {
    ArbreBinaire *a = ArbreVide();
    a->racine = arbre->racine->filsG;
    return recherche(a, k);
  }
  if (arbre->racine->val < k)
  {
    ArbreBinaire *a = ArbreVide();
    a->racine = arbre->racine->filsD;
    return recherche(a, k);
  }
}

//------------------------------------------------------
// Recherche du successeur du noeud x
//------------------------------------------------------

noeud *successeur(noeud *x)
{
  if (x->filsD != NULL)
  {
    return minArbre(x->filsD);
  }
  noeud *y = x->pere;
  while (y != NULL && x == y->filsD)
  {
    x = y;
    y = x->pere;
  }
  return y;
}

//------------------------------------------------------
// Suppression d'un noeud
//------------------------------------------------------

void remplace(ArbreBinaire *A, noeud *x, noeud *z)
{
  noeud *p = x->pere;
  x->pere = NULL;
  if (p == NULL)
    A->racine = z;
  else
  {
    if (x == p->filsG)
    {
      p->filsG = z;
    }
    else
    {
      p->filsD = z;
    }
  }
  if (z == NULL)
    z->pere = p;
}

void supprimer(ArbreBinaire *A, noeud *z)
{
  if (z->filsG == NULL)
  {
    cout << "remplace 1 : " << endl;
    remplace(A, z, z->filsD);
  }
  else
  {
    if (z->filsD == NULL)
    {
      cout << "remplace 2 : " << endl;
      remplace(A, z, z->filsG);
    }
    else
    {
      cout << "remplace 3 : " << endl;
      noeud *y = successeur(z);
      cout << "successeur de z : " << y->val << endl;
      remplace(A, y, y->filsD);
    }
  }
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main()
{
  ArbreBinaire *arbre = ArbreVide();
  int T[15] = {16, 6, 19, 3, 1, 8, 13, 5, 17, 12, 14, 20, 7, 23, 22};

  // Question 1

  for (int i = 0; i < 15; i++)
  {
    inserer(arbre, creerNoeud(T[i]));
  }
  //dessinArbre(arbre, "exemple");
  //affichageGraphique(arbre);

  // Question 2
  /*
  cout << "Parcours infixe de l'arbre : " << endl;
  parcoursInfixe(arbre->racine);
  cout << endl;
  noeud *min = minArbre(arbre->racine);
  if (min != NULL)
    cout << "Valeur minimale présente dans l'arbre: " << min->val << endl;
  else
    cout << "Arbre vide..." << endl;
*/
  // Question 3
  /*
  int k1;
  while (true)
  {
    cout << "Rentrer une valeur à rechercher (< 0 pour quitter) : ";
    cin >> k1;
    if (k1 < 0)
      break;
    noeud *rech = recherche(arbre, k1);
    cout << "Recherche de la valeur " << k1 << " : ";
    if (rech)
      cout << "trouvée (vérification : " << (rech->val) << ")" << endl;
    else
      cout << "non trouvée" << endl;
  }
*/
  // Question 4
  /*
  int k2;
  while (true)
  {
    cout << "Rentrer la valeur dont on doit trouver le successeur (< 0 pour quitter) : ";
    cin >> k2;
    if (k2 < 0)
      break;
    noeud *rech = recherche(arbre, k2);
    if (rech)
    {
      cout << "Successeur de la valeur " << k2 << " : ";
      noeud *s = successeur(rech);
      if (s)
        cout << s->val << endl;
      else
        cout << rech->val << " est la valeur max !" << endl;
    }
    else
      cout << "Valeur " << k2 << " non présente..." << endl;
  }
*/
  // Question 5

  int k3;
  while (true)
  {
    cout << "Rentrer la valeur du noeud à supprimer (< 0 pour quitter) : ";
    cin >> k3;
    if (k3 < 0)
      break;
    noeud *rech = recherche(arbre, k3);
    cout << "valeur de rech " << rech->val << endl;
    if (rech->val)
    {
      supprimer(arbre, rech);
      //dessinArbre(arbre, "supprime-" + to_string(k3));
      cout << "Valeur a supprimé : " << k3 << " trouve : " << rech->val << endl;
      affichageGraphique(arbre);
    }
    else
      cout << "Valeur " << k3 << " non présente" << endl;
  }

  return 0;
}
