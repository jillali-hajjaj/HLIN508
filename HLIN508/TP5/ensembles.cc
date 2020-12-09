#include <sstream>

#include "ensembles.h"

using namespace std;

ensemble vide()
{
  return 0;
}

ensemble plein(int n)
{
  return (ensemble(1)<<n) - 1;
}

ensemble suppr(ensemble S, int j)
{
  return S^(1 << j);
}

ensemble ajout(ensemble S, int j)
{
  return S|(1 << j);
}

bool appartient(ensemble S, int j)
{
  return S & (1<<j);
}

string str(ensemble S)
{
  stringstream s;
  s << "{";
  int j = 0;
  while (S > 0)
  {
    if (S&1) {
      s << j;
      if (S^1) s << ", ";
    }
    j++; S >>= 1;
  }
  s << "}";
  return s.str();
}

ensemble suivant(ensemble S, int n, int taille)
{
  // Gosper's hack
  int u = S & -S;
  int v = S + u;
  S = (((S^v) >> 2) / u) | v;
  if (S < (1<<n)) return S;
  return 0;
}
