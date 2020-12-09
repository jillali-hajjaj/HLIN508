#include "TP4.h"

typedef uint32_t chiffre;
typedef int *chiffre;

int somme(int nX, int nY, entier X, entier Y, entier Z)
{
    int size;
    int smaller;

    entier petit;

    if (nX > nY)
    {
        size = nX;
        smaller = nY;
        petit = Y;
    }
    else
    {
        size = nY;
        smaller = nX;
        petit = X;
    }

    Z = entier[size + 1];
    for (int i = 0; i < size + 1; ++i)
    {
        Z[i] = 0;
    }

    // POID FAIBLE AU DEBUT
    for (int i = 0; i < smaller; ++i)
    {
        chiffre cache = X[i] + Y[i];
        if (cache < X[i])
        {
            Z[i + 1] = Z[i + 1] + 1;
            Z[i] = Math.pow(2, 32) - cache;
        }
        else
        {
            Z[i] = cache;
        }
    }

    for (int i = smaller; i < size; ++i)
    {
        Z[i] = Z[i] + petit[i];
    }

    return size + 1;
}

void mul_chiffres(chiffre x, chiffre y, entier z)
{
}

int main(int argc, char **argv)
{
}
