#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Fonctions fournies :

void InitialiserCours(int n, int a[][2])
{
  for(int i=0;i<n;i++)
  {
    a[i][0]=0;
    a[i][1]=0;
  }
}

void AfficherCours(int n, int cours[][2])
{
  for(int i=0;i<n;i++)
    cout << "[" << cours[i][0] << "," << cours[i][1] << "] ";
}  

// Fonctions à compléter :


void GenererCours(int n, int cours[][2])
{
  srand(time(NULL));
  for (int i = 0; i < n; ++i)
  {
  	  	cours[i][0] = rand() % 90 + 1;
  		int a = rand() % 10 + 1;
  		cours[i][1] = cours[i][0] + a;
  		cout << "Début du cours : " <<  cours[i][0] << " Durée du cours : " << cours[i][1]  << endl;
  }
}


void TrierCours(int n, int cours[][2])
{
	int v[2];
  for (int i = n-1; i >= 1; --i)
  {
  	for (int j = 0; j < i; ++j)
  	{
  		if((cours[j][1]) > (cours[j+1][1])){
  			v[0] = cours[j][0];
  			v[1] = cours[j][1];
  			cours[j][0] = cours[j+1][0];
  			cours[j][1] = cours[j+1][1];
  			cours[j+1][0] = v[0];
  			cours[j+1][1] = v[1];
  		}
  	}
  }

}


int ChoixCoursGlouton(int n, int cours[][2], int choix[][2])
{
  for (int i = 0; i < n; ++i)
   {
   	choix[i][0] = 0;
   	choix[i][1] = 0;
   }

   int cc = 0;
   choix[0][0] = cours[0][0];
   choix[0][1] = cours[0][1];

   int fin = cours[0][0] + cours[0][1];

   int li = 0;
   for (int i = 1; i < n; ++i)
   {

   	if(cours[i][0] >= fin){

   		choix[li+1][0] = cours[i][0];
   		choix[li+1][1] = cours[i][1];

   		cc++;

   		fin = cours[i][0] + cours[i][1];
		li++;
   	}

   }
  return cc;
}

// Tests :

int main(){

  srand(time(NULL));

  // Test cours aléatoires :
  
  cout << "Test cours aléatoires :" << endl;

  cout << "  Entrer le nombre de cours : ";
  int n;
  cin >> n;
  int cours[n][2];
  InitialiserCours(n, cours);
  
  GenererCours(n, cours);
  cout << "  Cours non tries : ";
  AfficherCours(n, cours);
  cout << endl;

  TrierCours(n,cours);
  cout << "  Cours triés par dates de fin croissantes : ";
  AfficherCours(n,cours);
  cout << endl;

  int choix[n][2];
  int nbCours = ChoixCoursGlouton(n,cours,choix);
  cout << "  Nombre de cours choisis : " << nbCours << endl;
  cout << "  Liste des cours choisis :";
  AfficherCours(nbCours,choix);
  cout << endl << endl;

  // Test non aléatoire

  cout << "Test non aléatoire :" << endl;

  int n2 = 10;
  int cours2[n2][2]={{76,78},{12,17},{13,15},{19,28},{12,20},{43,45},{44,45},{1,8},{68,78},{85,88}};
  
  cout << "  Cours non tries : ";
  AfficherCours(n2, cours2);
  cout << endl;

  TrierCours(n2, cours2);
  cout << "  Cours triés par dates de fin croissantes : ";
  AfficherCours(n2, cours2);
  cout << endl;

  int choix2[n2][2];
  int nbCours2 = ChoixCoursGlouton(n2, cours2, choix2);
  cout << "  Nombre de cours choisis : " << nbCours2 << endl;
  cout << "  Liste des cours choisis :";
  AfficherCours(nbCours2, choix2);
  cout << endl << endl;
 
}

