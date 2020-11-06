#include <iostream>

typedef struct couple {
  int val;
  float priorite;
} couple;

void TabCouples(int n, couple C[], int Val[], float Priorites[]);

bool operator<(const couple& x, const couple& y);
bool operator>(const couple& x, const couple& y);
bool operator==(const couple& x, const couple& y);
bool operator!=(const couple& x, const couple& y);
bool operator<=(const couple& x, const couple& y);
bool operator>=(const couple& x, const couple& y);
std::ostream& operator<< (std::ostream &out, const couple& x);
