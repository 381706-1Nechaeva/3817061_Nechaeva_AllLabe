#include <iostream>

#include "plex.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  TPlex A;
  TPoint *D, *B, *E, *S, *R, *U;
  S = new TPoint(1,1);
  R = new TPoint(2,2);
  B = new TPoint(3,3);
  E = new TPoint(4,4);
  A.Add(S, B);
  A.Add(B, E);  
  TPlex W(A);
  W.Add(R,E);
  W.Add(B, R);
  TPlex *Q = new TPlex(W);
  cout << "Рекурсивный\n";
  W.Show(Q);
  cout << "Итеративный\n";
  W.Show();
  return 0;
}