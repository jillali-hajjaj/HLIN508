#include <iostream>
#include <fstream>

#include "points.h"

using namespace std;

void pointsAleatoires(int n, coord points[])
{
  for(int i=0;i<n;i++){
    points[i].x = rand() % 613;
    points[i].y = rand() % 793;
  }
}

void dessinPoints(int n, coord points[], string nom)
{ 
  ofstream output;                        
  output.open(nom + ".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {output << points[i].x << " " <<points[i].y << " 3 0 360 arc" <<endl;
    output << "0 setgray" <<endl;
    output << "fill" <<endl;
    output << "stroke"<<endl;
    output << endl;
    }
  output << endl;
  output.close();
}

void dessinTsp(int n, coord points[], int circuit[], string nom)
{
  ofstream output;                        
  output.open(nom + ".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0; i<n; i++)
    {output << points[i].x << " " << points[i].y << " 3 0 360 arc" << endl;
    output << "0 setgray" << endl;
    output << "fill" << endl;
    output << "stroke"<< endl;
    output << endl;
    }
  output << endl;
  for(int i=0; i < n; i++){
      output << points[circuit[i]].x << " " << points[circuit[i]].y
	    << " moveto"  << endl;
     output << points[circuit[(i+1)%n]].x << " " <<  points[circuit[(i+1)%n]].y
	    << " lineto"  << endl;
     output << "stroke" << endl;
     output << endl;
  }
  output.close();
}

void affichePoints(int n, coord* points)
{
  for (int i = 0; i < n-1; i++)
    cout << "(" << points[i].x << "," << points[i].y << "), ";
  cout << "(" << points[n-1].x << "," << points[n-1].y << ")" << endl;
}
