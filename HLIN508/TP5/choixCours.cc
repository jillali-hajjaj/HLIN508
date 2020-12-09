#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//--------Structure pour stocker les cours-----------

typedef struct{
  int deb;
  int fin;
  int val;
} crs;

//--------Generation des cours-----------

crs* GenererCours(int &n){
  int choix=0;
  crs* cours;
  while(choix!=1 && choix!=2){
    cout << "Tapez 1 pour remplir avec un exemple fixé, 2 pour générer aléatoirement:\n";
    cin >> choix;}
  switch(choix){
  case 1:
    n=8;
    cours= new crs[8];
    cours[0]={76,78,10}; cours[1]={12,17,2};cours[2]={13,15,1};
    cours[3]={19,28,8}; cours[4]={12,20,7}; cours[5]={44,45,9};
    cours[6]={43,45,5}; cours[7]={1,8,3};
    cours[8]={68,78,6}; cours[9]={85,88,7};
    break;
  case 2:
    cout << "Nombre de cours: ";
    cin >> n;
    cours= new crs[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
      cours[i].deb=rand()%90+1;
      cours[i].fin=cours[i].deb+rand()%10+1;
      cours[i].val=rand()%9+1;
    }
    break;
  default:
    cout <<"Pas compris, reessayer...\n";
  }
  return cours;
}

//--------Initialisation de tableaux-----------

void InitialisationTab(int n, int tab[], int v){
  for(int i=0;i<n;i++){
    tab[i]=v;
  }
}

//--------Affichage des cours-----------

void AfficherCours(int n, crs cours[]){
  for(int i=0;i<n;i++){
    cout<<"["<<cours[i].deb<<","<<cours[i].fin<<","
	<<cours[i].val<<"] ";}
  cout << endl;
}  

//--------Tri des cours-----------

void TrierCours(int n, crs cours[]){
  //
  // A IMPLEMENTER
  //
}

//-----Calcul du cours precedent compatible avec fin max----

void  CalculDernierPred(int n,crs cours[], int predMax[]){
  //
  // A IMPLEMENTER
  //
}


//--------Choix max en prog dyn-----------

void choixMaxProgD(int n, crs cours[], int predMax[], int crsMax[]){
  //
  // A IMPLEMENTER
  //
} 


//--------Choix max en recursif-----------

int choixMaxRec(crs cours[], int predMax[], int k){
  //
  // A IMPLEMENTER
  //
}


//--------Choix max en prog dyn avec solution-----------

void choixMaxProgDSol(int n, crs cours[], int predMax[], int crsMax[], int sol[]){
  //
  // A IMPLEMENTER
  //
}

//--------Reconstruction de la solution-----------

void ChoixCours(int n, int predMax[], int sol[], int choix[]){
  //
  // A IMPLEMENTER
  //
}

//--------Main-----------

int main(){
  int n;
  crs* cours;
  cours=GenererCours(n);

  clock_t t1,t2;
  
  cout << endl;
  cout << "Cours non tries:\n";
  AfficherCours(n,cours);
  cout<<endl;

  TrierCours(n,cours);
  cout << "Cours tries par dates de fin croissantes:\n";
  AfficherCours(n,cours);
  cout<<endl;
  
  int predMax[n];
  InitialisationTab(n,predMax,-1);
  
  CalculDernierPred(n,cours,predMax);
  cout<<"Calcul de predMax:\n";
  for(int i=0;i<n;i++){
    cout << "predMax[" << i << "]=" << predMax[i] << " ";
  }
  cout << endl;
  cout << endl;

  int crsMax[n];
  InitialisationTab(n,crsMax,0);

  t1 = clock();
  choixMaxProgD(n,cours,predMax,crsMax);
  t2=clock();
  cout << "Valeur d'un choix optimal de cours (en progdyn):"<< crsMax[n-1];
    cout<<"  (tps de calcul: " << (double)(t2-t1)/ CLOCKS_PER_SEC << "s)"<<endl;
  cout << endl;
  cout << endl;

  t1 = clock();
  cout << "Valeur d'un choix optimal de cours (en recursif): "<< choixMaxRec(cours,predMax,n-1);
  t2=clock();  
  cout<<"  (tps de calcul: " << (double)(t2-t1)/ CLOCKS_PER_SEC << "s)"<<endl;
  
  int sol[n];
  int choix[n];
  InitialisationTab(n,sol,0);
  InitialisationTab(n,choix,0);
  
  choixMaxProgDSol(n,cours,predMax,crsMax,sol);
  cout<< endl;
  cout << "Tableau d'appartenance a une solution locale max:"<<endl;
  for(int i=0;i<n;i++){
    cout << "sol["<<i<<"]="<<sol[i] << " ";
  }
  cout << endl;

  
  ChoixCours(n,predMax,sol,choix);

  cout << endl;
  cout << "Une solution optimale:"<<endl;
  
  int valtot=0;
  for(int i=0;i<n;i++){
    if(choix[i]==1){
      cout << "[" << cours[i].deb << "," << cours[i].fin << "," << cours[i].val << "] ";
      valtot+=cours[i].val;
  }
  }
  cout <<endl;
  cout<< "Valeur de cette solution: "<<valtot << endl;
}
