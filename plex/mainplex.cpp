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
  U = new TPoint(32, 2);
  A.Add(S, B);
  A.Add(B, E);  
  TPlex W(A);
  W.Add(R,E);
  W.Add(B, R);
  W.Add(E,S);
  W.Add(S, R);
  W.Add(S, U);
  TPlex *Q = new TPlex(W);
  cout << "Рекурсивный\n";
  W.Show(Q);
  cout << "Итеративный\n";
  W.Show();
  return 0;
}