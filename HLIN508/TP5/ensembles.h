#include <sstream>

using namespace std;

typedef uint64_t ensemble;

// Création de l'ensemble vide
ensemble vide();

// Création de l'ensemble {0, ..., n-1}
ensemble plein(int);

// Supprime l'entier j de l'ensemble S
ensemble suppr(ensemble, int);

// Ajoute l'entier j à l'ensemble S
ensemble ajout(ensemble, int);

// Teste si l'entier j appartient à l'ensemble S
bool appartient(ensemble, int);

// Crée une chaîne de caractère représentant l'ensemble
string str(ensemble);

// Parcours des sous-ensembles de taille k de {0, ..., n-1}
ensemble suivant(ensemble, int, int);

