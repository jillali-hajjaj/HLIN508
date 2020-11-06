#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

template<typename E>
struct noeud {
  E val;
  noeud<E>* pere;
  noeud<E>* filsG;
  noeud<E>* filsD;
};

template<typename E>
struct ArbreBinaire {
  noeud<E>* racine;
};

template<typename E>
ArbreBinaire<E>* ArbreVide(){
  ArbreBinaire<E>* arbre = (ArbreBinaire<E>*) malloc(sizeof(ArbreBinaire<E>));
  arbre->racine = NULL;
  return arbre;
}

template<typename E>
noeud<E>* creerNoeud(E valeur) {
  noeud<E>* x = (noeud<E>*) malloc(sizeof(noeud<E>));
  x->pere = NULL;
  x->filsG = NULL;
  x->filsD = NULL;
  x->val = valeur;
  return x;
}

void fauxNoeud(int c, string cote, ofstream& output) {
  output << "  " << cote << c << " [label=" << c << ", style = invis];" << endl;
  output << "  N" << c << "-> " << cote << c << " [style=invis];" << endl;
}

template<typename E>
int dessinNoeud(noeud<E>* N, ofstream& output, int c)
{
  output << "  N" << c << " [label = \"" << N->val << "\"];" << endl;
  int d = c;
  if (N->filsG) {
    output << "  N" << c << " -> N" << (c+1) << ";" << endl;
    d = dessinNoeud(N->filsG, output, c+1);
    if (!N->filsD) fauxNoeud(c, "D", output);
  }
  if (N->filsG or N->filsD) fauxNoeud(c, "C", output); 
  if (N->filsD) {
    if (!N->filsG) fauxNoeud(c, "G", output);
    output << "  N" << c << " -> N" << (d+1) << ";" << endl;
    d = dessinNoeud(N->filsD, output, d+1);
  }
  return d;
}

template<typename E>
noeud<E>* sousarbre(int n, E T[], int i) {
  noeud<E>* P = creerNoeud(T[i]);
  if (2*i + 1 < n) {
    noeud<E>* G = sousarbre(n, T, 2*i+1);
    P->filsG = G;
    G->pere = P;
  }
  if (2*i+2 < n) {
    noeud<E>* D = sousarbre(n, T, 2*i+2);
    P->filsD = D;
    D->pere = P;
  }
  return P;
}

template<typename E>
ArbreBinaire<E>* arbre(int n, E T[]) {
  ArbreBinaire<E>* A = ArbreVide<E>();
  A->racine = sousarbre(n, T, 0);
  return A;
}

template<typename E>
void dessinArbre(ArbreBinaire<E>* arbre, string name)
{
  ofstream output;
  output.open(name + ".dot");
  output << "digraph G {" << endl;
  output << "  node [style=filled];" << endl;
  
  dessinNoeud(arbre->racine, output, 0);

  output << "}" << endl;
  output.close();

  if (!system(NULL)) exit (EXIT_FAILURE);
  string s = "dot -Tpdf " + name + ".dot > " + name + ".pdf";
  int i = system(s.c_str());
  if (i != 0) exit (EXIT_FAILURE);
}
  
template<typename E>
void dessinTas(int n, E T[], string name)
{
  ArbreBinaire<E>* A = arbre(n, T);
  dessinArbre(A, name);
}


template<typename E>
void affichageNoeud(noeud<E>* n, int i, ofstream& output, int point[][2]){
  if(n->filsG!=NULL && (2*i+1<31)){
    output << point[i][0] << " " << point[i][1] 
	   << " moveto"  << endl;
    output << point[2*i+1][0] << " " << point[2*i+1][1] 
	   << " lineto"  << endl;
    output << "stroke" << endl;
    affichageNoeud(n->filsG,2*i+1,output,point);
  }
  if(n->filsD!=NULL && (2*i+2<31)){
    output << point[i][0] << " " << point[i][1] 
	   << " moveto"  << endl;
    output << point[2*i+2][0] << " " << point[2*i+2][1] 
	   << " lineto"  << endl;
    output << "stroke" << endl;
    affichageNoeud(n->filsD,2*i+2,output,point);
  }
  output << point[i][0] << " " << point[i][1] << " 14 0 360 arc" <<endl;
  output << "0 setgray" <<endl;
  output << "fill" <<endl;
  output << "stroke"<<endl;
  output << endl;
  output << point[i][0] << " " << point[i][1] << " 12 0 360 arc" <<endl;
  output << "0.8 setgray" <<endl;
  output << "fill" <<endl;
  output << "stroke"<<endl;
  output << endl;
  //if(n->val<10){
  //  output << point[i][0]-4 << " " << point[i][1] -4<< " moveto" <<endl;
  //}else{
    output << point[i][0]-9 << " " << point[i][1] -4<< " moveto" <<endl;
  //}
  output << "0 setgray" <<endl;
  output << "/Courier findfont 15 scalefont setfont" << endl;
  output << "("<< n->val  << ")" << " show" << endl;
  output << "stroke" << endl;
  output << endl;
}

template<typename E>
void affichageGraphique(int n, E T[], string name){
  ArbreBinaire<E>* arb=arbre(n,T);
  int haut=792; int larg=612;
  int point[31][2];
  point[0][0]=larg/2; point[0][1]=5*haut/6;
  for(int i=1;i<3;i++){point[i][0]=i*larg/3;point[i][1]=4*haut/6;}
  for(int i=3;i<7;i++){point[i][0]=(i-2)*larg/5;point[i][1]=3*haut/6;}
  for(int i=7;i<15;i++){point[i][0]=(i-6)*larg/9;point[i][1]=2*haut/6;}
  for(int i=15;i<31;i++){point[i][0]=(i-14)*larg/17;point[i][1]=haut/6;}
  ofstream output;
  output.open(name + ".ps");//
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  

  if(arb->racine!=NULL){
    affichageNoeud(arb->racine,0,output,point);}   
  output.close();
   
}

