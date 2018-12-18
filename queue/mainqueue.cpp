#include <iostream>

#include "queue.h"

int main()
{
  TQueue<int> A(4);
  A.Put(6);
  A.Put(5);
  A.Put(2);
  cout << A.Get() << endl << A.Get();
  return 0;
}