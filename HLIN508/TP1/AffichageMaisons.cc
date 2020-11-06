#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "AffichageMaisons.h"

using namespace std;

#define dcouv 100

void AffichageMaisons(int n, int coordMaison[][2], string nom)
// Cree le fichier Maisons.ps qui affiche les maisons uniquement.
  {ofstream output;                        
  output.open(nom + ".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {output << coordMaison[i][0] << " " << coordMaison[i][1] << " 3 0 360 arc" <<endl;
    output << "0 setgray" <<endl;
    output << "fill" <<endl;
    output << "stroke"<<endl;
    output << endl;
    }
  output << endl;
  output.close();
  }

void AffichageMaisonsEmetteurs(int n, int coordMaison[][2], int emetteur[], string nom)
// Cree le fichier Emetteurs.ps qui affiche les maisons et les emetteurs (en rouge) avec leur couverture.
  {ofstream output;                        
  output.open(nom + ".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;
  for(int i=0;i<n;i++)
    {
      if(emetteur[i]==1){
	output << coordMaison[i][0] << " " << coordMaison[i][1] << " " << dcouv << " 0 360 arc" <<endl;
	output << "0.8 setgray" <<endl;
	output << "fill" <<endl;
	output << "stroke"<<endl;
	output << endl;
      }
    }
  output << endl;
  for(int i=0;i<n;i++)
    {output << coordMaison[i][0] << " " << coordMaison[i][1] << " 3 0 360 arc" <<endl;
      if(emetteur[i]==1){
	output << "1 0 0 setrgbcolor" <<endl;
	output << "fill" <<endl;
	output << "stroke"<<endl;
	output << endl;
      }else{
	output << "0 setgray" <<endl;
	output << "fill" <<endl;
	output << "stroke"<<endl;
	output << endl;
      }
    }
  output << endl;
  output.close();
  }

