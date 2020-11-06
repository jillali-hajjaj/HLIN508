#include <iostream>
#include "Couples.h"

void TabCouples(int n, couple C[], int Val[], float Priorites[])
{
  for (int i=0; i < n; i++)
  {
    C[i].val = Val[i];
    C[i].priorite = Priorites[i];
  }
}

bool operator<(const couple& x, const couple& y) 
{
    return x.priorite < y.priorite;
}
bool operator>(const couple& x, const couple& y) 
{
    return x.priorite > y.priorite;
}
bool operator==(const couple& x, const couple& y) 
{
    return x.priorite == y.priorite and x.val == y.val;
}
bool operator!=(const couple& x, const couple& y) 
{
    return x.priorite != y.priorite or x.val != y.val;
}
bool operator<=(const couple& x, const couple& y) 
{
    return x.priorite <= y.priorite;
}
bool operator>=(const couple& x, const couple& y) 
{
    return x.priorite >= y.priorite;
}
std::ostream& operator<< (std::ostream &out, const couple& x) {
    out << "(" << x.val << "," << x.priorite << ")";
    return out;
}


