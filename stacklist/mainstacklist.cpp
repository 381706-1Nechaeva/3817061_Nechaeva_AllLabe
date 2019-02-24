#include <iostream>
#include "stacklist.h"

int main() 
{
  setlocale(LC_ALL, "Russian");
  TStackList<int> A;
  int a, q = 0;
  while (q != 2)
  {
    cout << "\n  1)Введите значение, которое следует положить в стек\n  2)Выход\n  ";
    cin >> q;
    switch (q)
    {
    case 1:
    {
      cout << "  Введите значение: ";
      cin >> a;
      A.Put(a);
    }
    break;
    case 2: q = 2;
      break;
    }
  }
  cout << "\n  Полученный стек:  "; 
  A.PrintTSL();
  cout << "\n  Извлекаем два элемента:" << A.Get()<<" и " << A.Get() << endl;
  cout << "  Измененный стек:  ";
  A.PrintTSL();
  return 0;
}