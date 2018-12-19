#include <iostream>

#include "list.h"

int main()
{
  TList<int> list;
  list.PutBegin(1);
  list.PutEnd(2);
  TList<int> list1(list);
  cout << list.GetEnd();
  return 0;
}