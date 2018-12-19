#include <iostream>

#include "multistack.h"

int main()
{
  TMStack<int> A(9, 3);
  A.Put(0, 5);
  A.Put(0, 4);
  A.Put(0, 4);
  A.Put(0, 4);
  cout << A.Get(0);
  return 0;
}