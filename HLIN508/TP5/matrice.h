#include <iostream>

using namespace std;

template <typename T>
T** matrice(int m, int n)
{
  T** M = new T*[m];
  for (int i=0; i < m; i++)
    M[i] = new T[n];
  return M;
}

template <typename T>
void initialise(int m, int n, T** M, T val)
{
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      M[i][j] = val;
}

template <typename T>
void afficheMatrice(int m, int n, T** M)
{
  for (int i=0; i < m; i++)
  {
    for (int j=0; j < n; j++)
      cout << M[i][j] << ' ';
    cout << endl;
  }
}
