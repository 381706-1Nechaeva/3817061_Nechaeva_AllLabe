#include <iostream>

#include "vector.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  /*TMatrix<float> A(4), B(4);
  for (int i = 0; i < A.GetSize(); i++)
    for (int j = i; j < A.GetSize(); j++)
      A[i][j] = 15 * i + 1 + j;
  cout <<"  Пример вывода матрицы\n  "<< A << endl;
  cout << "  Введите матрицу с  размерами строчек соответственно ";
  for (int i = A.GetSize(); i > 1; i--)
    cout << i << ", ";
  cout << "1\n";
  cin >> B;
  cout << "  Полученная матрица\n  "<<B<<endl;
  cout << "  Операции с матрицами:\n" << "  Сложение A + B \n  " << A + B << endl << "  Вычитание A - B\n  " << A - B << endl << "  Умножение A * B\n  " << A * B << endl << "  Деление A/B\n  " << A / B << endl;
*/
  TVector<TVector<int>>A(3);

//for(int i=0;i<A.GetSize();i++)
//cout << A[i].GetFirstInd();
  //for (int i = 0; i < A.GetSize(); i++)
  //cout << A[i];
  TMatrix<int> C;
  cout << "Введите матрицу 3 на 3\n";
  cin >> C;
  cout << "Чочооооо\n";
  cout << C;

  return 0;
}