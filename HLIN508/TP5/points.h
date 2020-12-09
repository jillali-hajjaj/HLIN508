#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
  float x;
  float y;
} coord;

void pointsAleatoires(int, coord*);
void dessinPoints(int, coord*, string = "Points");
void dessinTsp(int, coord*, int*, string = "Circuit");
void affichePoints(int, coord*);

